#!/usr/bin/env python3
"""Adds the relocations a decompiled unit shows but config/<ver>/arm9/**/relocs.txt lacks.

dsd init records relocations only in code it analysed. When a function it missed is decompiled, the calls and
pool words inside it (and calls into it from other missed code) have no relocation, so the delinked original
links them as plain bytes and the linker can strip a function nothing seems to reference. For every function of
the unit's compiled object that matches the original at its address (relocations masked), this reads each
relocation site's target from the ORIGINAL bytes (bl/blx/b decoding, or the pool word) and adds an entry for
every site relocs.txt doesn't have. Targets outside every module (hardware registers, constants) are skipped.

  add_relocs.py build/<ver>/src/Main/Some/Unit.o [more objects...] [--write]

Dry run unless --write. Run `ninja report` (or `ninja`) first so the objects exist; afterwards the ROM must still
match.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
from probe_compilers import compare, module_bytes, thumb_branch_target  # noqa: E402
from project import BASES, CONFIG, module_paths  # noqa: E402  (tools/project.py)

FUNC = re.compile(r"(\S+) kind:function\((\w+),size=(0x[0-9a-f]+)[^)]*\) addr:(0x[0-9a-f]+)")
MODULE_SIZES = {}


def module_of(addr):
    """Module whose loaded range contains addr, or None (a register, a constant)."""
    for mod, base in BASES.items():
        if mod not in MODULE_SIZES:
            _, extracted, _ = module_paths(mod)
            size = len(extracted.read_bytes()) if extracted.is_file() else 0
            bss = re.search(r"\.bss\s+start:0x[0-9a-f]+ end:(0x[0-9a-f]+)", (module_paths(mod)[0] / "delinks.txt").read_text()) \
                if (module_paths(mod)[0] / "delinks.txt").is_file() else None
            MODULE_SIZES[mod] = (int(bss.group(1), 16) - base) if bss else size
        if base <= addr < base + MODULE_SIZES[mod]:
            return mod
    return None


def functions_by_name(module):
    cfg = module_paths(module)[0]
    out = {}
    for line in (cfg / "symbols.txt").read_text().splitlines():
        if m := FUNC.match(line):
            out[m[1]] = (int(m[4], 16), int(m[3], 16), m[2] == "thumb")
    return out


def arm_branch_target(word, pc):
    off = word & 0xFFFFFF
    if off & 0x800000:
        off -= 1 << 24
    target = pc + 8 + off * 4
    if word >> 28 == 0xF:  # blx (immediate): bit 24 adds a halfword, target is Thumb
        target += (word >> 24 & 1) * 2
    return target


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("objects", nargs="+", type=Path)
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    known = {}  # relocs.txt path -> set of from addresses
    added = {}
    for obj in a.objects:
        elf = ELFFile(open(obj, "rb"))
        symtab = elf.get_section_by_name(".symtab")
        for module in sorted(BASES):
            cfg = module_paths(module)[0]
            if not (cfg / "symbols.txt").is_file():
                continue
            funcs = functions_by_name(module)
            base, blob = module_bytes(module) if module != "dtcm" else (None, None)
            if blob is None:
                continue
            for sym in symtab.iter_symbols():
                if sym["st_info"]["type"] != "STT_FUNC" or sym.name not in funcs:
                    continue
                addr, size, thumb = funcs[sym.name]
                sec = elf.get_section(sym["st_shndx"])
                start = sym["st_value"] & ~1
                code = sec.data()[start:start + sym["st_size"]]
                rel = next((s for s in elf.iter_sections() if isinstance(s, RelocationSection)
                            and s["sh_info"] == sym["st_shndx"]), None)
                relocs = [r for r in rel.iter_relocations() if start <= r["r_offset"] < start + size] if rel else []
                mask = {r["r_offset"] - start + k for r in relocs for k in range(4)}
                if len(code) != size or not compare(code, mask, blob[addr - base:addr - base + size])[0]:
                    continue  # only a matching function says where the original's relocation sites are
                path = cfg / "relocs.txt"
                if path not in known:
                    known[path] = {int(m[1], 16) for m in re.finditer(r"^from:(0x[0-9a-f]+)", path.read_text(), re.M)}
                for r in relocs:
                    site = addr + r["r_offset"] - start
                    if site in known[path] or site in added.get(path, {}):
                        continue
                    o = site - base
                    t = r["r_info_type"]
                    if t == 10:  # Thumb bl/blx
                        target = thumb_branch_target(blob, o, site)
                        lo = struct.unpack_from("<H", blob, o + 2)[0]
                        kind = "thumb_call" if lo & 0x1000 else "thumb_call_arm"
                    elif t in (1, 28, 29):  # ARM bl / blx / b
                        word = struct.unpack_from("<I", blob, o)[0]
                        target = arm_branch_target(word, site)
                        kind = "arm_call_thumb" if word >> 28 == 0xF else "arm_branch" if not word & 0x01000000 else "arm_call"
                    elif t == 2:  # pool word
                        target = struct.unpack_from("<I", blob, o)[0]
                        kind = "load"
                    else:
                        continue
                    tmod = module_of(target & ~1)
                    if tmod is None:
                        continue
                    added.setdefault(path, {})[site] = f"from:{site:#010x} kind:{kind} to:{target:#010x} module:{tmod}"
    for path, entries in added.items():
        print(f"{path.relative_to(CONFIG.parent.parent.parent)}: {len(entries)} relocation(s) to add")
        for site in sorted(entries):
            print("   ", entries[site])
        if a.write:
            lines = path.read_text().splitlines() + list(entries.values())
            lines.sort(key=lambda l: int(re.match(r"from:(0x[0-9a-f]+)", l)[1], 16))
            path.write_text("\n".join(lines) + "\n")
    if not added:
        print("nothing to add")


if __name__ == "__main__":
    main()
