#!/usr/bin/env python3
"""Checks which decompiled units are ready to be linked (marked `complete` in delinks.txt).

For each unit it compares the compiled object with the original layout:
  - function order: the linker keeps the order functions have in the object (mwcc 2.0 emits them in source order,
    1.2 in reverse: tools/project.py emits_reversed), so the definitions must give the original addresses
    (forward-declare callees defined later; tools/reorder_functions.py does it);
  - other sections: a compiled `.data`/`.rodata`/`.bss`/`.ctor`/`.init` with contents needs a matching range in
    the unit's delinks entry, or linking would duplicate the original copy still in the gap.

  link_check.py [--all] [unit-substring ...]

Prints one line per unit: READY, ORDER (with the out-of-order functions) or DATA (sections without a range).
Run `ninja report` first so the objects exist.
"""
import argparse
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
CFG = ROOT / f"config/{VERSION}/arm9"
BUILD = ROOT / f"build/{VERSION}"
SYM = re.compile(r"^(\S+) kind:(\S+) addr:(0x[0-9a-f]+)")
RANGE = re.compile(r"^\s+(\.\w+)\s+start:(0x[0-9a-f]+)\s+end:(0x[0-9a-f]+)")


def delinks_files():
    yield "main", CFG / "delinks.txt"
    for m in ("itcm", "dtcm"):
        if (CFG / m / "delinks.txt").exists():
            yield m, CFG / m / "delinks.txt"
    for d in sorted((CFG / "overlays").iterdir()) if (CFG / "overlays").is_dir() else ():
        yield d.name, d / "delinks.txt"


def parse_units(path: Path):
    units = []
    cur = None
    for line in path.read_text().splitlines():
        if line and not line[0].isspace() and line.rstrip().endswith(":") and not line.startswith("//"):
            cur = {"file": line.rstrip()[:-1], "ranges": {}, "complete": False}
            units.append(cur)
        elif cur is not None and line.strip() == "complete":
            cur["complete"] = True
        elif cur is not None and (m := RANGE.match(line)):
            cur["ranges"][m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16))
    return units


def load_symbols(module: str) -> dict[str, int]:
    path = CFG / "symbols.txt" if module == "main" else (
        CFG / module / "symbols.txt" if module in ("itcm", "dtcm") else CFG / "overlays" / module / "symbols.txt")
    out = {}
    for line in path.read_text().splitlines():
        if m := SYM.match(line):
            out.setdefault(m.group(1), int(m.group(3), 16))
    return out


def check(module: str, unit: dict, syms: dict[str, int]):
    obj = BUILD / Path(unit["file"]).with_suffix(".o")
    if not obj.exists():
        return "MISSING", [f"{obj} not built"]
    problems = []
    with obj.open("rb") as f:
        elf = ELFFile(f)
        symtab = elf.get_section_by_name(".symtab")
        funcs_by_sec: dict[int, list] = {}
        binds_by_sec: dict[int, set] = {}
        for s in symtab.iter_symbols():
            if isinstance(s["st_shndx"], int) and s["st_info"]["type"] == "STT_OBJECT":
                binds_by_sec.setdefault(s["st_shndx"], set()).add(s["st_info"]["bind"])
            if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int) and not s.name.startswith("$"):
                funcs_by_sec.setdefault(s["st_shndx"], []).append(s)
        order = []
        extra = {}
        for idx, sec in enumerate(elf.iter_sections()):
            if not sec["sh_flags"] & 2 or sec["sh_size"] == 0:  # SHF_ALLOC
                continue
            if sec.name == ".text":
                # One entry per function; C1/C2 (and D1/D2) aliases share an offset, use whichever is known.
                at: dict[int, list[str]] = {}
                for s in funcs_by_sec.get(idx, []):
                    at.setdefault(s["st_value"], []).append(s.name)
                for _, names in sorted(at.items()):
                    order.append(next((n for n in names if n in syms), names[0]))
            elif binds_by_sec.get(idx) and binds_by_sec[idx] <= {"STB_WEAK", 14}:
                continue  # demoted C++ inline statics (singletons, guards): the original's copy wins
            else:
                extra[sec.name] = extra.get(sec.name, 0) + sec["sh_size"]
    addrs = [(syms.get(n), n) for n in order]
    unknown = [n for a, n in addrs if a is None]
    if unknown:
        problems.append("unknown symbols: " + ", ".join(unknown[:5]))
    lo, hi = unit["ranges"].get(".text", (0, 0))
    foreign = [n for a, n in addrs if a is not None and not lo <= a < hi]
    if foreign:
        problems.append("defined outside the unit's .text (inline copies?): " + ", ".join(foreign[:5]))
    known = [(a, n) for a, n in addrs if a is not None and lo <= a < hi]
    bad = [n for (a0, _), (a1, n) in zip(known, known[1:]) if a1 < a0]
    kind = None
    if bad:
        kind = "ORDER"
        problems.append("out of order: " + ", ".join(bad[:8]) + (" ..." if len(bad) > 8 else ""))
    missing = {k: v for k, v in extra.items() if k not in unit["ranges"]}
    if missing:
        kind = kind or "DATA"
        problems.append("no range for " + ", ".join(f"{k} ({v:#x} bytes)" for k, v in sorted(missing.items())))
    if (unknown or foreign) and kind is None:
        kind = "UNKNOWN" if unknown else "FOREIGN"
    return kind or "READY", problems


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("filter", nargs="*")
    ap.add_argument("--all", action="store_true", help="include units already marked complete")
    args = ap.parse_args()
    counts = {}
    for module, path in delinks_files():
        syms = None
        for unit in parse_units(path):
            if not unit["file"].startswith(("src/", "libs/")) or (unit["complete"] and not args.all):
                continue
            if args.filter and not any(f in unit["file"] for f in args.filter):
                continue
            syms = syms or load_symbols(module)
            kind, problems = check(module, unit, syms)
            counts[kind] = counts.get(kind, 0) + 1
            print(f"{kind:8} {unit['file']}" + "".join(f"\n         {p}" for p in problems))
    print(", ".join(f"{k}: {v}" for k, v in sorted(counts.items())), file=sys.stderr)


if __name__ == "__main__":
    main()
