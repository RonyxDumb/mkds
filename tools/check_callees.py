#!/usr/bin/env python3
"""Lists functions whose callees differ from the original's, including functions that don't match yet.

check_calls.py compares call targets instruction by instruction, which needs identical code. This compares, per
function, the list of `bl` targets (by address, in code order) in our compiled object with the `bl`/`blx` targets
inside the original function's address range, so wrong callees (e.g. a neighbouring routine, or a signed instead of
an unsigned division helper) show up while the function still differs. A different set is printed as what is extra
and what is missing; the same set in another order prints both lists in order. A call to a name that no symbols.txt
has is printed with "(unknown)" and counts as a difference. Run after `ninja`.

Usage: check_callees.py [object.o ...]   (default: every object under build/<ver>/src and build/<ver>/libs)
"""
import struct
import sys
from collections import Counter
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).parent))
from check_calls import ROOT, load_symbols, module_bytes, module_of  # noqa: E402
from probe_compilers import thumb_branch_target  # noqa: E402
from project import VERSION  # noqa: E402  (tools/project.py)


def original_callees(blob, base, start, size, thumb=False):
    out = []  # call targets in code order
    if thumb:  # bl/blx are a pair of halfwords: F000-prefix then E800/F800 suffix
        site = start
        while site + 4 <= start + size:
            if base <= site < base + len(blob) - 3:
                hi, lo = struct.unpack_from("<HH", blob, site - base)
                if hi & 0xF800 == 0xF000 and lo & 0xE800 == 0xE800:
                    target = thumb_branch_target(blob, site - base, site)
                    # a BL within the function is a far branch to its own code (a shared epilogue), not a call
                    if not start <= target < start + size or target == start:
                        out.append(target | 1)
                    site += 4
                    continue
            site += 2
        return out
    for site in range(start, start + size, 4):
        if not base <= site < base + len(blob) - 3:
            continue
        word = struct.unpack_from("<I", blob, site - base)[0]
        cond = word >> 28
        if word & 0x0E000000 == 0x0A000000 and cond != 0xF:  # BL, and B (a tail call when it targets a function)
            d = word & 0xFFFFFF
            d -= (1 << 24) if d & 0x800000 else 0
            target = site + 8 + d * 4
            # a B within the function is a loop, not a call; a BL to the function's own start is recursion
            if not start <= target < start + size or (word & 0x01000000 and target == start):
                out.append(target | 1)
        elif cond == 0xF and word & 0x0E000000 == 0x0A000000:  # BLX imm
            d = word & 0xFFFFFF
            d -= (1 << 24) if d & 0x800000 else 0
            out.append((site + 8 + d * 4 + (word >> 24 & 1) * 2) | 1)
    return out


def load_sizes():
    """{name: (size, Thumb?)} for every function in symbols.txt."""
    import re
    sizes = {}
    files = [ROOT / f"config/{VERSION}/arm9/symbols.txt", ROOT / f"config/{VERSION}/arm9/itcm/symbols.txt",
             *sorted((ROOT / f"config/{VERSION}/arm9/overlays").glob("*/symbols.txt"))]
    for path in files:
        for line in path.read_text().splitlines():
            m = re.match(r"(\S+) kind:function\((\w+),size=(0x[0-9a-f]+)", line)
            if m:
                sizes.setdefault(m.group(1), (int(m.group(3), 16), m.group(2) == "thumb"))
    return sizes


def main():
    tables = load_symbols()
    sizes = load_sizes()
    objs = [Path(p).resolve() for p in sys.argv[1:]] or sorted(
        [*(ROOT / f"build/{VERSION}/src").rglob("*.o"), *(ROOT / f"build/{VERSION}/libs").rglob("*.o")])
    names_at = {}
    for t in tables.values():
        for n, a in t.items():
            names_at.setdefault(a | 1, n)
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
            funcs = [s for s in syms if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int)
                     and s["st_size"] and s.name in local]
            ours = {f.name: [] for f in funcs}  # (offset, address | 1, or the name when no symbols.txt has it)
            for sec in elf.iter_sections():
                if not sec.name.startswith(".rel"):
                    continue
                for r in sec.iter_relocations():
                    if r["r_info_type"] not in (1, 10, 28, 29):  # ARM branches, Thumb bl/blx (10)
                        continue
                    fn = next((f for f in funcs if f["st_shndx"] == sec["sh_info"]
                               and f["st_value"] <= r["r_offset"] < f["st_value"] + f["st_size"]), None)
                    if fn is None:
                        continue
                    target = syms[r["r_info_sym"]].name
                    addr = local.get(target, tables["main"].get(target))
                    if addr is None:
                        addr = next((t[target] for t in tables.values() if target in t), None)
                    ours[fn.name].append((r["r_offset"], target if addr is None else addr | 1))
            for f in funcs:
                if f.name.startswith("_ZThn"):  # this-adjusting thunks: the original tail-branches
                    continue
                # scan the original over the ORIGINAL function's size, not ours
                size, thumb = sizes.get(f.name, (f["st_size"], False))
                theirs = original_callees(blob, base, local[f.name], size, thumb)
                # literal-pool words can decode as branches: keep only targets that are known function starts
                theirs = [a for a in theirs if a in names_at]
                mine = [a for _, a in sorted(ours[f.name], key=lambda x: x[0])]
                if mine != theirs:
                    name = lambda a: a + "(unknown)" if isinstance(a, str) else names_at.get(a, hex(a))
                    if Counter(mine) != Counter(theirs):
                        extra = Counter(mine) - Counter(theirs)
                        missing = Counter(theirs) - Counter(mine)
                        fmt = lambda c: ", ".join(f"{name(a)}x{n}" for a, n in c.items())
                        print(f"{obj.relative_to(ROOT)}: {f.name}: calls {fmt(extra) or '-'}; the original calls "
                              f"{fmt(missing) or '-'}")
                    else:
                        fmt = lambda c: ", ".join(name(a) for a in c)
                        print(f"{obj.relative_to(ROOT)}: {f.name}: calls in order {fmt(mine)}; the original calls in "
                              f"order {fmt(theirs)}")
                    problems += 1
    print(f"{problems} function(s) with different callees")


if __name__ == "__main__":
    main()
