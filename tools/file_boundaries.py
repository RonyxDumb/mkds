#!/usr/bin/env python3
"""Looks for units whose boundaries are probably not the original files' boundaries, from the layout of the
original's data (the rules are in docs/decompiling.md, "Data"):

  ORDER    The linker places each file's .data, .rodata and .bss in the order of the files' .text. Two units whose
           data come in the other order than their code are probably one file (or cut in the wrong place).
  SIZE     The compiler sorts a file's objects by size, smallest first; its function strings follow. A smaller
           object after a bigger one, or an object after strings, inside one unit's range means the unit holds
           more than one file.
  SHARED   A data object outside every unit's ranges that only a run of consecutive units uses belongs to one of
           their files: if the run has more than one unit, they are probably one file.
  OWNER    For each object outside every unit's ranges, the units that can hold it: those between the units whose data
           come before and after it (the link order), and among them the ones that use it. CERTAIN: only one unit
           holds code next to it (a file of data only could still sit there); LIKELY: only one of
           those uses it; OPEN: more than one.
  PRAGMA   Units this tool would join, but whose `#pragma optimize_for_size` differs: the pragma covers a whole
           file, so they cannot be one file as they are written.

Object sizes come from the distance to the next symbol, so an object followed by alignment padding looks bigger;
SIZE allows for that (up to 3 bytes, or up to the next 32-byte boundary). Everything printed is a candidate to look
at, not a proof. Run after `ninja` (it reads the original module from the extracted ROM).

  file_boundaries.py [module ...] [--kind ORDER,SIZE,SHARED,PRAGMA]
"""
import argparse
import bisect
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import CFG, delinks_files, parse_units  # noqa: E402
from probe_compilers import module_bytes  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SYM = re.compile(r"^(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:(0x[0-9a-f]+)")
RELOC = re.compile(r"^from:(0x[0-9a-f]+) kind:\S+ to:(0x[0-9a-f]+)(?: add:\S+)? module:(\S+)")
DATA_SECTIONS = (".data", ".rodata", ".bss")


def module_dir(module: str) -> Path:
    if module == "main":
        return CFG
    if module in ("itcm", "dtcm"):
        return CFG / module
    return CFG / "overlays" / module


def section_bounds(module: str):
    head = (module_dir(module) / "delinks.txt").read_text().split("\n\n", 1)[0]
    return {m.group(1): (int(m.group(2), 16), int(m.group(3), 16))
            for m in re.finditer(r"^\s+(\.\w+)\s+start:(0x[0-9a-f]+) end:(0x[0-9a-f]+)", head, re.M)}


def reloc_field_module(field: str, module: str) -> bool:
    if module.startswith("ov"):
        return field == f"overlay({int(module[2:])})" or (field.startswith("overlays(") and str(int(module[2:])) in field)
    return field == module


def is_string(blob: bytes) -> bool:
    if b"\0" not in blob:
        return False
    s = blob[:blob.index(b"\0")]
    return len(s) >= 2 and all(32 <= c < 127 or c in (9, 10) for c in s) and not any(blob[blob.index(b"\0"):].strip(b"\0"))


def analyse(module: str, kinds: set[str]):
    units = [u for u in parse_units(module_dir(module) / "delinks.txt") if ".text" in u["ranges"]]
    units.sort(key=lambda u: u["ranges"][".text"][0])
    bounds = section_bounds(module)
    try:
        base, blob = module_bytes(module)
    except (Exception, SystemExit):  # noqa: BLE001  (a module without code, e.g. dtcm)
        return []
    syms = []
    for line in (module_dir(module) / "symbols.txt").read_text().splitlines():
        if (m := SYM.match(line)) and m.group(2) in ("data", "bss"):
            syms.append((int(m.group(4), 16), m.group(1), m.group(2)))
    syms.sort()
    addrs = [a for a, _, _ in syms]
    out = []
    text_of = {u["file"]: u["ranges"][".text"] for u in units}

    def unit_at(addr: int, section: str):
        for u in units:
            lo, hi = u["ranges"].get(section, (0, 0))
            if lo <= addr < hi:
                return u["file"]
        return None

    def section_of(addr: int):
        for name in DATA_SECTIONS:
            if name in bounds and bounds[name][0] <= addr < bounds[name][1]:
                return name
        return None

    def objects(lo: int, hi: int, section: str):
        """(address, size, is string) of the symbols in [lo, hi)."""
        i, j = bisect.bisect_left(addrs, lo), bisect.bisect_left(addrs, hi)
        res = []
        for k in range(i, j):
            a = addrs[k]
            end = addrs[k + 1] if k + 1 < len(addrs) and addrs[k + 1] < hi else hi
            data = b"" if section == ".bss" else blob[a - base:end - base]
            res.append((a, end - a, section != ".bss" and is_string(data), syms[k][1]))
        return res

    # ORDER: data sections in the order of the code
    if "ORDER" in kinds:
        for section in DATA_SECTIONS:
            withs = [u for u in units if section in u["ranges"]]
            for a, b in zip(withs, withs[1:]):
                if b["ranges"][section][0] < a["ranges"][section][0]:
                    out.append(("ORDER", f"{a['file']} and {b['file']}: {section} of the second comes first "
                                         f"({b['ranges'][section][0]:#010x} < {a['ranges'][section][0]:#010x})"))

    relocs = []  # (from, to) of this module's relocations into this module
    for path in CFG.rglob("relocs.txt"):
        if ("main" if path.parent == CFG else path.parent.name) != module:
            continue
        for line in path.read_text().splitlines():
            if (m := RELOC.match(line)) and reloc_field_module(m.group(3), module):
                relocs.append((int(m.group(1), 16), int(m.group(2), 16)))
    code = [b for n, b in bounds.items() if n not in DATA_SECTIONS]
    from_code = {to for frm, to in relocs if any(lo <= frm < hi for lo, hi in code)}

    # SIZE: object order inside each unit's range. Objects (strings an initializer points to among them) come
    # sorted by size; the strings the functions use come after all of them.
    if "SIZE" in kinds:
        for u in units:
            for section in DATA_SECTIONS:
                if section not in u["ranges"]:
                    continue
                objs = objects(*u["ranges"][section], section)
                seen_fn_string = None
                prev = None
                for a, size, string, name in objs:
                    if string:
                        n = blob[a - base:].index(b"\0") + 1
                        if a in from_code:
                            seen_fn_string = seen_fn_string or name
                            continue
                        size = n  # an initializer's string: its own length, not the padding after it
                    if seen_fn_string:
                        out.append(("SIZE", f"{u['file']}: {section} object {name} at {a:#010x} follows the "
                                            f"function string {seen_fn_string}"))
                        break
                    if prev:
                        pa, psize, pname = prev
                        slack = max(3, (-(pa + psize) % 32) if psize >= 32 else 3)
                        if size + slack < psize and not (a % 32 == 0 and size >= 32):
                            out.append(("SIZE", f"{u['file']}: {section} {name} ({size:#x} bytes at {a:#010x}) "
                                                f"follows the bigger {pname} ({psize:#x} bytes)"))
                            break
                    prev = (a, size, name)

    # SHARED: gap objects used by a run of consecutive units. "next to" says the object sits right after the data
    # of the run's first unit or right before the data of its last one, in the same section.
    if "SHARED" in kinds:
        users = defaultdict(set)
        unit_starts = [u["ranges"][".text"][0] for u in units]
        for frm, to in relocs:
            section = section_of(to)
            if not section or unit_at(to, section):
                continue
            k = bisect.bisect_right(unit_starts, frm) - 1
            if k >= 0 and frm < units[k]["ranges"][".text"][1]:
                users[to].add(k)
        for to, ks in sorted(users.items()):
            ks = sorted(ks)
            if len(ks) > 1 and ks[-1] - ks[0] + 1 == len(ks):
                section = section_of(to)
                name = next((n for a, n, _ in syms if a == to), f"{to:#010x}")
                near = []
                for k in ks:
                    lo, hi = units[k]["ranges"].get(section, (None, None))
                    if lo is not None and (0 <= to - hi < 0x40 or 0 <= lo - to < 0x40):
                        near.append(units[k]["file"])
                where = f"; next to the data of {', '.join(near)}" if near else ""
                out.append(("SHARED", f"{name} ({section}, outside every unit) is used only by the consecutive "
                                      + ", ".join(units[k]["file"] for k in ks) + where))

    # OWNER: which units can hold each object outside every unit's ranges. The linker lays out a section in the
    # order of the files, so an object between the data of units X and Y in a section belongs to X, to Y or to a
    # unit between them; of those, the ones that use it are the likely owners.
    if "OWNER" in kinds and units:
        users = defaultdict(set)
        unit_starts = [u["ranges"][".text"][0] for u in units]
        for frm, to in relocs:
            k = bisect.bisect_right(unit_starts, frm) - 1
            if k >= 0 and frm < units[k]["ranges"][".text"][1]:
                users[to].add(k)
        for section in DATA_SECTIONS:
            if section not in bounds:
                continue
            placed = [(u["ranges"][section], k) for k, u in enumerate(units) if section in u["ranges"]]
            for a, size, string, name in objects(*bounds[section], section):
                if unit_at(a, section):
                    continue
                before = [k for (lo, hi), k in placed if hi <= a]
                after = [k for (lo, hi), k in placed if lo > a]
                first = max(before) if before else 0
                last = min(after) if after else len(units) - 1
                span = set(range(first, last + 1))
                likely = sorted(users.get(a, set()) & span)
                if len(span) == 1:
                    verdict = "ONE"
                elif len(likely) == 1:
                    verdict = "LIKELY"
                else:
                    verdict = "OPEN"
                out.append(("OWNER", f"{verdict} {section} {name} {a:#010x} {size:#x} "
                                     f"span={units[first]['file']}..{units[last]['file']} ({len(span)} units) "
                                     f"users-in-span={','.join(units[k]['file'] for k in likely)}"))

    # PRAGMA: optimize_for_size differs between units ORDER/SHARED would join
    if "PRAGMA" in kinds:
        def size_pragma(f):
            p = ROOT / f
            return p.suffix != ".s" and p.exists() and "#pragma optimize_for_size on" in p.read_text()
        for kind, msg in list(out):
            if kind not in ("ORDER", "SHARED"):
                continue
            files = re.findall(r"((?:src|libs)/\S+?\.(?:c|cpp))", msg)
            flags = {f: size_pragma(f) for f in files}
            if len(set(flags.values())) > 1:
                out.append(("PRAGMA", "optimize_for_size differs: " + ", ".join(f"{f}={'size' if v else 'speed'}"
                                                                                  for f, v in flags.items())))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--kind", default="ORDER,SIZE,SHARED,PRAGMA,OWNER")
    a = ap.parse_args()
    kinds = set(a.kind.split(","))
    total = 0
    for module, _ in delinks_files():
        if a.modules and module not in a.modules:
            continue
        for kind, msg in analyse(module, kinds):
            print(f"{kind:7} {module:6} {msg}")
            total += 1
    print(f"{total} candidate(s)")


if __name__ == "__main__":
    main()
