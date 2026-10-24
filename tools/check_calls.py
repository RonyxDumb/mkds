#!/usr/bin/env python3
"""Checks that calls and pointers in the compiled objects go where the original's go.

Function matching masks relocated words, so a function can "match" while calling the wrong function (e.g. `_fdiv`
where the original calls `_fmul`; both are a plain `bl`). For every compiled function whose address is known from
symbols.txt, this decodes each branch the original makes at the same offset and compares it with the address of
the symbol the object calls (when that symbol's address is known). Pointer words in the function's literal pool
(a tail call through a register, a function pointer, a global's address) are checked the same way: the original's
word at that offset must be the referenced symbol's address (plus the addend). String literals and other file-local
data have no address before linking; check_strings.py and data_ranges.py cover them. Run after `ninja` and
`sync_symbols.py`.

Only fully matching functions are checked (from build/<ver>/report.json; run `ninja report` first).

Usage: check_calls.py [object.o ...]   (default: every object under build/<ver>/src and build/<ver>/libs)
"""
import json
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).parent))
from probe_compilers import module_bytes, thumb_branch_target  # noqa: E402
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
LINE = re.compile(r"^(\S+) kind:(\S+).* addr:(0x[0-9a-f]+)")


def load_symbols() -> dict[str, dict[str, int]]:
    tables = {}
    for path in [ROOT / f"config/{VERSION}/arm9/symbols.txt", ROOT / f"config/{VERSION}/arm9/itcm/symbols.txt",
                 *sorted((ROOT / f"config/{VERSION}/arm9/overlays").glob("*/symbols.txt"))]:
        module = "main" if path.parent.name == "arm9" else path.parent.name
        table = {}
        for line in path.read_text().splitlines():
            if m := LINE.match(line):
                table.setdefault(m.group(1), int(m.group(3), 16))
        tables[module] = table
    return tables


def module_of(obj: Path) -> str | None:
    for ext in (".cpp", ".c"):
        rel = obj.relative_to(ROOT / f"build/{VERSION}").with_suffix(ext).as_posix()
        for path in [ROOT / f"config/{VERSION}/arm9/delinks.txt", ROOT / f"config/{VERSION}/arm9/itcm/delinks.txt",
                     *sorted((ROOT / f"config/{VERSION}/arm9/overlays").glob("*/delinks.txt"))]:
            if f"{rel}:" in path.read_text():
                return "main" if path.parent.name == "arm9" else path.parent.name
    return None


def matched_functions() -> set[str]:
    """Functions objdiff reports as fully matching (only these have code at the same offsets)."""
    report = ROOT / f"build/{VERSION}/report.json"
    if not report.exists():
        return set()
    names = set()
    for unit in json.loads(report.read_text())["units"]:
        for fn in unit.get("functions", []):
            if fn.get("fuzzy_match_percent", 0) >= 100:
                names.add(fn["name"])
    return names


def check_pointer(obj, r, funcs, syms, code, local, tables, base, blob) -> int:
    """1 if the original's pool word at this relocation isn't the address of the symbol the object points to."""
    fn = next((s for s in funcs if s["st_value"] <= r["r_offset"] < s["st_value"] + s["st_size"]), None)
    target = syms[r["r_info_sym"]]
    if fn is None or not target.name or target["st_info"]["type"] == "STT_SECTION" or target.name[0] in "@$":
        return 0  # file-local data: no address before linking
    want = local.get(target.name, tables["main"].get(target.name))
    if want is None:
        return 0
    off = r["r_offset"]
    site = local[fn.name] + off - fn["st_value"]
    if not base <= site <= base + len(blob) - 4:
        return 0
    # mwcc writes RELA (the addend is in the entry); a REL object keeps it in the word itself
    addend = r["r_addend"] if r.is_RELA() else struct.unpack_from("<I", code, off)[0]
    actual = struct.unpack_from("<I", blob, site - base)[0]
    if (actual | 1) == ((want + addend) | 1):  # a Thumb function pointer carries the Thumb bit
        return 0
    names = [n for t in tables.values() for n, a in t.items() if a == actual & ~1]
    print(f"{obj.relative_to(ROOT)}: {fn.name}+{off - fn['st_value']:#x} points to {target.name} "
          f"({want + addend:#010x}); the original points to {actual:#010x} {names[:1]}")
    return 1


def main():
    if any(a in ("-h", "--help") for a in sys.argv[1:]):
        print(__doc__)
        sys.exit(0)
    tables = load_symbols()
    matched = matched_functions()
    objs = [Path(p).resolve() for p in sys.argv[1:]] or sorted([*(ROOT / f"build/{VERSION}/src").rglob("*.o"), *(ROOT / f"build/{VERSION}/libs").rglob("*.o")])
    problems = 0
    for obj in objs:
        module = module_of(obj)
        if module is None:
            continue
        base, blob = module_bytes(module)
        local = tables[module]
        with open(obj, "rb") as fh:
            elf = ELFFile(fh)
            syms = list(elf.get_section_by_name(".symtab").iter_symbols())
            for sec in elf.iter_sections():
                if not sec.name.startswith(".rel"):
                    continue
                funcs = [s for s in syms if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] == sec["sh_info"]
                         and s["st_size"] and s.name in local and s.name in matched]
                code = elf.get_section(sec["sh_info"]).data()
                for r in sec.iter_relocations():
                    if r["r_info_type"] == 2:  # R_ARM_ABS32: a pointer word in a literal pool
                        problems += check_pointer(obj, r, funcs, syms, code, local, tables, base, blob)
                        continue
                    if r["r_info_type"] not in (1, 10, 28, 29):  # ARM branches, Thumb bl/blx (10)
                        continue
                    fn = next((s for s in funcs if s["st_value"] <= r["r_offset"] < s["st_value"] + s["st_size"]), None)
                    if fn is None:
                        continue
                    target = syms[r["r_info_sym"]].name
                    want = local.get(target, tables["main"].get(target))
                    if want is None:
                        continue
                    site = local[fn.name] + r["r_offset"] - fn["st_value"]
                    if not base <= site < base + len(blob):
                        continue
                    if r["r_info_type"] == 10:
                        hi, lo = struct.unpack_from("<HH", blob, site - base)
                        if hi & 0xF800 != 0xF000 or lo & 0xE800 != 0xE800:  # not a bl/blx pair in the original
                            continue
                        actual = thumb_branch_target(blob, site - base, site)
                    else:
                        word = struct.unpack_from("<I", blob, site - base)[0]
                        if word & 0x0E000000 != 0x0A000000:  # not a branch in the original
                            continue
                        disp = word & 0xFFFFFF
                        if disp & 0x800000:
                            disp -= 1 << 24
                        actual = site + 8 + disp * 4
                        if word >> 28 == 0xF:  # BLX: bit 24 adds a halfword
                            actual += (word >> 24 & 1) * 2
                    if (actual | 1) != (want | 1):  # ignore the Thumb bit
                        names = [n for t in tables.values() for n, a in t.items() if a == actual]
                        print(f"{obj.relative_to(ROOT)}: {fn.name}+{r['r_offset'] - fn['st_value']:#x} calls {target} "
                              f"({want:#010x}); the original calls {actual:#010x} {names[:1]}")
                        problems += 1
    print(f"{problems} call(s) or pointer(s) differ")
    sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
