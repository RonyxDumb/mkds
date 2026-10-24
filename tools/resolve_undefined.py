#!/usr/bin/env python3
"""Finds where the original places the symbols a unit references but symbols.txt doesn't name.

For each undefined symbol U in our compiled object, takes the relocations that use it, finds the relocation at the
same function offset in the delinked original object, and reports its target there:
  - a placeholder symbol (func_/data_<addr>) -> rename it to U in symbols.txt;
  - a point inside a bigger symbol (target+addend) -> add U as a new symbol at that address.

  resolve_undefined.py src/Main/Some/Unit.c [--write]
"""
import argparse
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from project import PLACEHOLDER, VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / f"build/{VERSION}"


def load(path):
    e = ELFFile(open(path, "rb"))
    syms = list(e.get_section_by_name(".symtab").iter_symbols())
    funcs = {}
    for s in syms:
        if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int):
            funcs.setdefault(s.name, (s["st_shndx"], s["st_value"], s["st_size"]))
    relocs = []  # (section index, offset, symbol, addend-or-None)
    for sec in e.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name.startswith(".rel"):
            tgt = sec["sh_info"]
            for r in sec.iter_relocations():
                sym = syms[r["r_info_sym"]]
                add = r["r_addend"] if r.is_RELA() else None
                if add is None:  # REL: implicit addend for ABS32 words
                    data = e.get_section(tgt).data()
                    if r["r_info_type"] == 2:
                        add = int.from_bytes(data[r["r_offset"]:r["r_offset"] + 4], "little")
                relocs.append((tgt, r["r_offset"], sym, add, r["r_info_type"]))
    return e, syms, funcs, relocs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    stem = str(Path(a.unit).with_suffix(".o"))
    ours, theirs = BUILD / stem, BUILD / "delinks" / stem
    _, osyms, ofuncs, orel = load(ours)
    theirs_elf, tsyms, tfuncs, trel = load(theirs)
    undef = {s.name for s in osyms if s["st_shndx"] == "SHN_UNDEF" and s.name}
    # symbols.txt by name and by address, per module file
    symfiles = list((ROOT / f"config/{VERSION}/arm9").rglob("symbols.txt"))
    by_name, by_addr, functions = {}, {}, []
    for p in symfiles:
        for i, l in enumerate(p.read_text().splitlines()):
            m = re.match(r"(\S+) kind:(\S+) addr:(0x[0-9a-f]+)", l)
            if m:
                by_name[m.group(1)] = (p, int(m.group(3), 16))
                by_addr.setdefault(int(m.group(3), 16), []).append((p, m.group(1)))
                if f := re.match(r"function\(\w+,size=(0x[0-9a-f]+)", m.group(2)):
                    functions.append((int(m.group(3), 16), int(m.group(3), 16) + int(f.group(1), 16), m.group(1)))

    def in_function(addr):
        return next((n for lo, hi, n in functions if lo <= addr < hi), None)
    missing = sorted(u for u in undef if u not in by_name)
    plan = {}
    for u in missing:
        for sec, off, sym, add, typ in orel:
            if sym.name != u:
                continue
            fn = next((n for n, (si, v, sz) in ofuncs.items() if si == sec and v <= off < v + max(sz, 1)), None)
            if fn is None or fn not in tfuncs:
                continue
            o_base = ofuncs[fn][1]
            t_sec, t_base, _ = tfuncs[fn]
            hit = next((r for r in trel if r[0] == t_sec and r[1] == t_base + (off - o_base)), None)
            if not hit:
                if typ != 2:
                    continue
                # no relocation in the original: the pool word holds the address itself
                word = theirs_elf.get_section(t_sec).data()[t_base + off - o_base:t_base + off - o_base + 4]
                addr = int.from_bytes(word, "little") - ((add or 0) if add else 0)
                owner = max((v for v in by_addr if v <= addr), default=None)
                tname = by_addr[owner][0][1] if owner is not None else None
                plan.setdefault(u, set()).add((tname, addr))
                continue
            tname = hit[2].name
            if tname in by_name:
                addr = by_name[tname][1] + ((hit[3] or 0) if typ == 2 else 0)
            else:
                continue
            plan.setdefault(u, set()).add((tname, addr))
    for u in missing:
        if u not in plan:
            print(f"{u}: not found in the original's relocations")
            continue
        if len(plan[u]) != 1:
            print(f"{u}: ambiguous {plan[u]}")
            continue
        tname, addr = next(iter(plan[u]))
        here = by_addr.get(addr, [])
        if any(n == tname for _, n in here) and PLACEHOLDER.match(tname) and by_name[tname][1] == addr:
            print(f"{u}: rename {tname} at {addr:#x}")
            if a.write:
                p = by_name[tname][0]
                t = p.read_text()
                p.write_text(re.sub(rf"^{re.escape(tname)}(?= kind:)", u, t, flags=re.M))
        elif not here and (fn := in_function(addr)):
            # A point inside a function is a label or a function dsd merged: decide by reading the code.
            print(f"{u}: {addr:#x} is inside function {fn}; not added (a label, or a function to split?)")
        elif not here:
            # Data: inside a data object (dsd can't tell where the neighbour ends) or in a gap between functions.
            print(f"{u}: add data at {addr:#x}" + (f" (after {tname})" if tname else ""))
            if a.write:
                p = by_name[tname][0] if tname in by_name else symfiles[0]
                with open(p, "a") as f:
                    f.write(f"{u} kind:data(any) addr:{addr:#010x}\n")
        else:
            print(f"{u}: {addr:#x} already named {[n for _, n in here]}; source should use that name")
    return 0


if __name__ == "__main__":
    sys.exit(main())
