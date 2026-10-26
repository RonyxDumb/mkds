#!/usr/bin/env python3
"""Finds where a decompiled unit's data sections live in the original module, to fill in its delinks.txt entry.

Every relocation in an exactly matching function points where the original's literal pool word points, so a
relocation against one of the unit's own data sections gives that section's original address:
    base = original word - symbol offset - addend.
Data sections found this way are scanned too (vtables, tables of string pointers), which places the sections
they point to. The result lists each compiled data section with its original address, checks that sections of
one kind are laid out in object order without overlaps, and prints the delinks lines.

  data_ranges.py src/Main/Some/Unit.c [--write]

--write replaces the unit's data ranges in delinks.txt (only when every section was placed consistently).
"""
import argparse
import fcntl
import json
import os
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import BUILD, CFG, delinks_files, load_symbols, parse_units  # noqa: E402
from probe_compilers import module_bytes  # noqa: E402
from project import placeholder  # noqa: E402  (tools/project.py)

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
KINDS = {".rodata": "rodata", ".data": "data", ".bss": "bss", ".init": "rodata", ".ctor": "rodata",
         ".sbss": "bss", ".sdata": "data"}
R_ARM_ABS32 = 2


def find_unit(src: str):
    for module, path in delinks_files():
        for unit in parse_units(path):
            if unit["file"] == src:
                return module, path, unit
    raise SystemExit(f"{src} not in any delinks.txt")


def matched_functions(src: str) -> set[str]:
    """Functions at 100% in the report, plus those whose bytes equal the original's with relocated words masked
    (objdiff counts a differently named relocation target, e.g. an `@N` static, as a mismatch)."""
    report = json.loads((BUILD / "report.json").read_text())
    name = str(Path(src).with_suffix(""))
    good = set()
    for unit in report["units"]:
        if unit["name"] == name:
            good = {f["name"] for f in unit.get("functions", []) if f.get("fuzzy_match_percent", 0) == 100}
    try:
        module, _, _ = find_unit(src)
        syms = load_symbols(module)
        mbase, blob = module_bytes(module)
        with (BUILD / Path(src).with_suffix(".o")).open("rb") as fh:
            elf = ELFFile(fh)
            secs = list(elf.iter_sections())
            masked = {}
            for sec in secs:
                if isinstance(sec, RelocationSection):
                    masked.setdefault(sec["sh_info"], set()).update(r["r_offset"] & ~3 for r in sec.iter_relocations())
            for s in elf.get_section_by_name(".symtab").iter_symbols():
                if s["st_info"]["type"] != "STT_FUNC" or s.name in good or s.name not in syms or not s["st_size"]:
                    continue
                data = secs[s["st_shndx"]].data()[s["st_value"]:s["st_value"] + s["st_size"]]
                start = syms[s.name] - mbase
                orig = blob[start:start + len(data)]
                if len(orig) == len(data) and all(data[i:i + 4] == orig[i:i + 4] for i in range(0, len(data) - 3, 4)
                                                  if (s["st_value"] + i) not in masked.get(s["st_shndx"], ())):
                    good.add(s.name)
    except Exception:
        pass
    return good


def analyse(src: str):
    module, delinks_path, unit = find_unit(src)
    syms = load_symbols(module)
    mbase, blob = module_bytes(module)
    good = matched_functions(src)
    obj = BUILD / Path(src).with_suffix(".o")

    with obj.open("rb") as fh:
        elf = ELFFile(fh)
        sections = list(elf.iter_sections())
        symtab = elf.get_section_by_name(".symtab")
        symbols = list(symtab.iter_symbols())
        relocs: dict[int, list] = {}
        for sec in sections:
            if isinstance(sec, RelocationSection):
                relocs.setdefault(sec["sh_info"], []).extend(sec.iter_relocations())
        data_secs = {}
        names_in: dict[int, list[str]] = {}
        binds_in: dict[int, set] = {}
        for s in symbols:
            if isinstance(s["st_shndx"], int) and s["st_info"]["type"] in ("STT_OBJECT", "STT_FUNC", "STT_NOTYPE"):
                if s.name and not s.name.startswith("$"):
                    names_in.setdefault(s["st_shndx"], []).append(s.name)
                if s["st_info"]["type"] == "STT_OBJECT":
                    binds_in.setdefault(s["st_shndx"], set()).add(s["st_info"]["bind"])
        for idx, sec in enumerate(sections):
            if sec["sh_flags"] & 2 and sec["sh_size"] and sec.name != ".text":
                weak = binds_in.get(idx) and binds_in[idx] <= {"STB_WEAK", 14}
                # In C++ code, weak singleton guards and instances are the kept copies of another unit (the first file
                # that used them); a weak function-local static of an inline accessor (a table) belongs to this unit.
                singleton = any(n.startswith("_ZGV") or n.endswith("GetEvE8instance") for n in names_in.get(idx, []))
                if not weak or not singleton:
                    data_secs[idx] = sec
        contents = {idx: (sec.data() if sec["sh_type"] != "SHT_NOBITS" else b"") for idx, sec in data_secs.items()}

        # Function sections -> original address (exact matches only).
        func_addr = {}
        for s in symbols:
            if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int) and s.name in good \
                    and s.name in syms and s["st_value"] == 0:
                func_addr[s["st_shndx"]] = syms[s.name]
        text_contents = {idx: sections[idx].data() for idx in func_addr}

        base: dict[int, int] = {}
        conflicts = []

        def place(idx, addr, why):
            if idx not in data_secs:
                return
            if idx in base and base[idx] != addr:
                conflicts.append(f"{data_secs[idx].name}#{idx} ({', '.join(names_in.get(idx, [])[:2])}): "
                                 f"{base[idx]:#x} vs {addr:#x} ({why})")
                return
            if idx not in base:
                base[idx] = addr
                queue.append(idx)

        def word(at):
            off = at - mbase
            return struct.unpack_from("<I", blob, off)[0] if 0 <= off <= len(blob) - 4 else None

        def scan(src_idx, src_addr, data):
            for r in relocs.get(src_idx, []):
                if r["r_info_type"] != R_ARM_ABS32:
                    continue
                sym = symbols[r["r_info_sym"]]
                tgt = sym["st_shndx"]
                if not isinstance(tgt, int) or tgt not in data_secs:
                    continue
                orig = word(src_addr + r["r_offset"])
                if orig is None:
                    continue
                addend = r["r_addend"] if r.is_RELA() else struct.unpack_from("<I", data, r["r_offset"])[0]
                value = sym["st_value"] if sym["st_info"]["type"] != "STT_SECTION" else 0
                place(tgt, (orig - value - addend) & 0xFFFFFFFF, f"from {src_addr + r['r_offset']:#x}")

        queue: list[int] = []
        for idx, addr in func_addr.items():
            scan(idx, addr, text_contents[idx])
        while queue:
            idx = queue.pop()
            if data_secs[idx]["sh_type"] != "SHT_NOBITS":
                scan(idx, base[idx], contents[idx])
        # Data sections addressed by a named symbol that symbols.txt already knows.
        for idx in data_secs:
            if idx not in base:
                for n in names_in.get(idx, []):
                    if n in syms:
                        s = next(s for s in symbols if s.name == n and s["st_shndx"] == idx)
                        place(idx, syms[n] - s["st_value"], f"symbols.txt {n}")
                        break
        while queue:
            idx = queue.pop()
            if data_secs[idx]["sh_type"] != "SHT_NOBITS":
                scan(idx, base[idx], contents[idx])

    # Sections used only by functions the original doesn't have (e.g. the unused C2 copy of a C++ constructor,
    # which the linker strips along with its strings) are dropped from the unit.
    users: dict[int, set] = {}
    for src_idx, rels in relocs.items():
        for r in rels:
            tgt = symbols[r["r_info_sym"]]["st_shndx"]
            if isinstance(tgt, int) and tgt in data_secs:
                users.setdefault(tgt, set()).add(src_idx)
    func_names = {}
    for sym in symbols:
        if sym["st_info"]["type"] == "STT_FUNC" and isinstance(sym["st_shndx"], int) and not sym.name.startswith("$"):
            func_names.setdefault(sym["st_shndx"], []).append(sym.name)
    for idx in list(data_secs):
        if idx in base or not users.get(idx):
            continue
        if all(sections[u].name == ".text" and not any(n in syms for n in func_names.get(u, []))
               for u in users[idx]):
            del data_secs[idx]
    reloc_offsets = {idx: [r["r_offset"] for r in relocs.get(idx, [])] for idx in data_secs}
    return module, delinks_path, unit, data_secs, names_in, base, conflicts, contents, (mbase, blob), reloc_offsets


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()
    (module, delinks_path, unit, data_secs, names_in, base, conflicts, contents, (mbase, blob),
     reloc_offsets) = analyse(args.source)

    # The module's own section bounds (the header of its delinks.txt): a compiled .data section placed inside
    # the original's .rodata means the source disagrees about const-ness, and so on.
    bounds = {}
    for line in delinks_path.read_text().splitlines():
        if not line.startswith((" ", "\t")):
            if line.strip() and not line.startswith("//"):
                break
            continue
        if m := re.match(r"\s+(\.\w+)\s+start:(0x[0-9a-f]+)\s+end:(0x[0-9a-f]+)", line):
            bounds[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))
    for idx, sec in data_secs.items():
        if idx in base and sec.name in bounds:
            lo, hi = bounds[sec.name]
            if not (lo <= base[idx] and base[idx] + sec["sh_size"] <= hi):
                conflicts.append(f"{sec.name}#{idx} ({', '.join(names_in.get(idx, [])[:2])}) placed at "
                                 f"{base[idx]:#x}, outside the original {sec.name} {lo:#x}-{hi:#x}")
    ok = not conflicts
    for c in conflicts:
        print("conflict:", c)
    by_kind: dict[str, list] = {}
    for idx, sec in data_secs.items():
        by_kind.setdefault(sec.name, []).append(idx)
    ranges = {}
    for name, idxs in by_kind.items():
        print(f"{name}:")
        prev_end = None
        placed = [i for i in idxs if i in base]
        order_ok = placed == sorted(placed, key=lambda i: base[i])
        for i in idxs:
            sec = data_secs[i]
            b = base.get(i)
            label = ", ".join(names_in.get(i, [])[:3]) or "(anonymous)"
            same = ""
            if b is not None and sec["sh_type"] != "SHT_NOBITS":
                orig = bytearray(blob[b - mbase: b - mbase + sec["sh_size"]])
                mine = bytearray(contents[i])
                for off in reloc_offsets.get(i, ()):
                    orig[off:off + 4] = mine[off:off + 4] = b"\0\0\0\0"
                same = " bytes-ok" if orig == mine else " BYTES-DIFFER"
                if orig != mine:
                    ok = False
            where = f"{b:#010x}" if b is not None else "??????????"
            gap = ""
            if b is not None and prev_end is not None and b != prev_end:
                gap = f"  (gap {b - prev_end:+#x})"
            if b is not None:
                prev_end = b + sec["sh_size"]
            if args.verbose or b is None or gap or "DIFFER" in same:
                print(f"  {where} size {sec['sh_size']:#6x} align {sec['sh_addralign']:2} {label}{same}{gap}")
        if any(i not in base for i in idxs):
            print(f"  {sum(i not in base for i in idxs)} of {len(idxs)} sections not placed")
            ok = False
            continue
        if not order_ok:
            print("  object order differs from address order")
            ok = False
        lo = min(base[i] for i in idxs)
        hi = max(base[i] + data_secs[i]["sh_size"] for i in idxs)
        # The padding up to the next object's (4-aligned) start belongs to this one: a range ending unaligned
        # would leave a gap object that the linker realigns.
        hi = (hi + 3) & ~3
        total = sum(data_secs[i]["sh_size"] for i in idxs)
        print(f"  range {lo:#010x}-{hi:#010x} ({hi - lo:#x} bytes, sections {total:#x})")
        ranges[name] = (lo, hi)
    for name, (lo, hi) in sorted(ranges.items()):
        print(f"    {name:<11} start:{lo:#010x} end:{hi:#010x}")
    if args.write:
        if not ok:
            raise SystemExit("not writing: unresolved sections or conflicts")
        # Nothing after the unit in its section: the range runs to the section's end (the tail is alignment
        # padding, and a boundary symbol there would name nothing in the linked binary).
        sym_addrs = sorted(load_symbols_any(module))
        for name, (lo, hi) in list(ranges.items()):
            if name in bounds and not any(hi <= a < bounds[name][1] for a in sym_addrs):
                ranges[name] = (lo, bounds[name][1])
        # Several of these can run at once (tools/try_link.py): one writer at a time, and each file is replaced
        # whole so a reader never sees half of it.
        with open(BUILD / ".data_ranges.lock", "w") as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            write_ranges(delinks_path, args.source, ranges)
            add_boundaries(module, ranges, bounds)


def write_whole(path: Path, text: str):
    tmp = path.with_name(path.name + f".{os.getpid()}.tmp")
    tmp.write_text(text)
    os.replace(tmp, path)


def write_ranges(path: Path, src: str, ranges: dict[str, tuple[int, int]]):
    order = [".text", ".init", ".rodata", ".ctor", ".data", ".bss", ".sbss"]
    lines = path.read_text().splitlines()
    out, i = [], 0
    while i < len(lines):
        line = lines[i]
        out.append(line)
        if line.rstrip() == src + ":":
            body = []
            i += 1
            while i < len(lines) and lines[i].startswith((" ", "\t")) and lines[i].strip():
                body.append(lines[i])
                i += 1
            keep = [b for b in body if not re.match(r"\s+\.\w+\s+start:", b)]
            have = {re.match(r"\s+(\.\w+)", b).group(1): b for b in body if re.match(r"\s+\.\w+\s+start:", b)}
            for name, (lo, hi) in ranges.items():
                have[name] = f"    {name:<11} start:{lo:#010x} end:{hi:#010x}"
            out.extend(keep)
            out.extend(have[n] for n in sorted(have, key=lambda n: order.index(n) if n in order else 99))
            # drop the "code only" provisional note above the entry
            j = len(out) - len(keep) - len(have) - 2
            if j >= 0 and out[j].startswith("// provisional: code only"):
                del out[j]
            continue
        i += 1
    write_whole(path, "\n".join(out) + "\n")


def load_symbols_any(module: str) -> set[int]:
    path = CFG / "symbols.txt" if module == "main" else (
        CFG / module / "symbols.txt" if module in ("itcm", "dtcm") else CFG / "overlays" / module / "symbols.txt")
    return {int(m.group(1), 16) for ln in path.read_text().splitlines()
            if "kind:function" not in ln and (m := re.search(r" addr:(0x[0-9a-f]+)", ln))}


def add_boundaries(module: str, ranges: dict[str, tuple[int, int]], bounds: dict | None = None):
    """dsd sizes a data symbol up to the next symbol, so a range must not end inside one: add a symbol at the
    range's end (and start) when the symbols around it would straddle the boundary."""
    path = CFG / "symbols.txt" if module == "main" else (
        CFG / module / "symbols.txt" if module in ("itcm", "dtcm") else CFG / "overlays" / module / "symbols.txt")
    lines = path.read_text().splitlines()
    addr_re = re.compile(r" addr:(0x[0-9a-f]+)")
    data_lines = [(int(m.group(1), 16), i) for i, ln in enumerate(lines)
                  if (m := addr_re.search(ln)) and "kind:function" not in ln and "kind:label" not in ln]
    have = {a for a, _ in data_lines}
    new = []
    for name, (lo, hi) in ranges.items():
        kind = "bss" if name in (".bss", ".sbss") else "data(any)"
        for at in (lo, hi):
            if at in have:
                continue
            if bounds and name in bounds and at == bounds[name][1]:
                continue  # the section ends here: nothing follows to straddle, and the name would be lost
            before = [a for a, _ in data_lines if a < at]
            after = [a for a, _ in data_lines if a > at]
            if before:  # the symbol before would otherwise extend over the boundary
                new.append((at, f"{placeholder('data', at, module)} kind:{kind} addr:{at:#010x}"))
                have.add(at)
    if not new:
        return
    for at, line in new:
        idx = next((i for a, i in sorted(data_lines) if a > at), len(lines))
        lines.insert(idx, line)
        data_lines = [(a, i + 1 if i >= idx else i) for a, i in data_lines] + [(at, idx)]
    write_whole(path, "\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
