#!/usr/bin/env python3
"""Explains why the rebuilt ROM doesn't match: compares each rebuilt module (main, ITCM, DTCM, overlays) in
build/<ver>/build/ with the extracted one.

For each module that differs: the size difference, words that differ by a constant small amount grouped (pointers
shifted because code or data moved), and the first difference that isn't such a shift, with the symbol it falls in.
Typical causes: a function with a wrong or zero size, so dsd maps the data after it as ARM code (the linker then adds
ARM-to-Thumb veneers at the end of .text and later pointers shift by 12 bytes per veneer), a unit range that ends on a
halfword, or a unit whose compiled object is a different size.

Then it compares the whole rebuilt ROM with the base ROM and names the part the first difference falls in (header,
ARM9, ARM7, file name or allocation table, overlay tables, banner, or a file by its id), so a mismatch outside the
code modules (a file, the header) is explained too.

  diff_rom.py [--max-shift 0x1000] [module ...]
"""
import argparse
import bisect
import collections
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import GAME, ROOT, VERSION, VERSIONS, module_base, module_paths, modules  # noqa: E402  (tools/project.py)


def is_pointer(v):
    """An address in ITCM, main RAM or DTCM."""
    return 0x01ff8000 <= v < 0x02000000 or 0x02000000 <= v < 0x02400000 or 0x027e0000 <= v < 0x02800000


def symbols(cfg):
    out = []
    for line in (cfg / "symbols.txt").read_text().splitlines():
        if m := re.match(r"(\S+) kind:(\S+) addr:(0x[0-9a-f]+)", line):
            out.append((int(m.group(3), 16), m.group(1), m.group(2)))
    return sorted(out)


def diff_module(module, max_shift):
    """Prints the report for one module; returns True when it matches."""
    cfg, extracted, rebuilt = module_paths(module)
    if not rebuilt.is_file():
        print(f"{module}: no rebuilt binary ({rebuilt}); run ninja")
        return False
    built, orig = rebuilt.read_bytes(), extracted.read_bytes()
    if built == orig:
        return True
    base = module_base(module)
    print(f"{module}: size built {len(built):#x}, original {len(orig):#x} ({len(built) - len(orig):+#x})")
    shifts = collections.defaultdict(list)
    first = None
    for i in range(0, min(len(built), len(orig)) - 3, 4):
        x, y = struct.unpack_from("<I", built, i)[0], struct.unpack_from("<I", orig, i)[0]
        if x == y:
            continue
        if is_pointer(y) and 0 < abs(x - y) <= max_shift:
            shifts[x - y].append((base + i, y))
        elif first is None:
            first = base + i
    if first is None and len(built) != len(orig):
        first = base + min(len(built), len(orig))
    for d, hits in sorted(shifts.items(), key=lambda kv: -len(kv[1])):
        lowest = min(t for _, t in hits)
        print(f"  pointers shifted by {d:+#x}: {len(hits)} words, lowest original target {lowest:#010x} "
              f"(something before that address grew or moved by {d:+#x})")
    if first is None:
        print("  no difference other than shifted pointers")
        return False
    syms = symbols(cfg)
    k = bisect.bisect_right([s[0] for s in syms], first) - 1
    name, kind = (syms[k][1], syms[k][2]) if k >= 0 else ("?", "?")
    print(f"  first other difference at {first:#010x}, in {name} ({kind})")
    for label, data in (("built", built), ("original", orig)):
        o = first - base
        print(f"    {label:8} {data[max(o - 8, 0):o + 16].hex(' ', 4)}")
    off = first - base
    if off + 4 <= min(len(built), len(orig)):
        ow, bw = struct.unpack_from("<I", orig, off)[0], struct.unpack_from("<I", built, off)[0]
        if ow & 1 and is_pointer(ow) and bw & 1 and bw > ow:
            print("  the original word is a Thumb function pointer and the built one points further on, at a veneer "
                  "the linker added: dsd mapped this stretch as ARM code. Look for a function before it with a wrong "
                  "or zero size (a size-0 `_unk` from dsd init) and give it its real size (docs/decompiling.md, "
                  "'Setting up a new game')")
    return False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("modules", nargs="*", help="default: every module")
    ap.add_argument("--max-shift", type=lambda s: int(s, 0), default=0x1000)
    a = ap.parse_args()
    if stale := stale_build():
        sys.exit(stale)
    results = [diff_module(m, a.max_shift) for m in (a.modules or modules())]
    if all(results):
        print("every module matches")
    if not a.modules:
        diff_rom_file()


def stale_build():
    """A message when the rebuilt ROM is older than the config or a source (the last build failed or wasn't run),
    so its modules are not what the current files produce; None when it is current."""
    built = ROOT / "build" / VERSION / f"{GAME}_{VERSION}.nds"
    if not built.is_file():
        return f"{built.relative_to(ROOT)} doesn't exist: run ninja first"
    inputs = [*(ROOT / "config" / VERSION).rglob("*.txt")]
    inputs += [p for d in ("src", "libs", "include") for p in (ROOT / d).rglob("*") if p.suffix in (".c", ".cpp", ".h", ".s")]
    newer = [p for p in inputs if p.stat().st_mtime > built.stat().st_mtime]
    if newer:
        return (f"{built.relative_to(ROOT)} is older than {newer[0].relative_to(ROOT)}"
                f"{f' and {len(newer) - 1} more' if len(newer) > 1 else ''}: the last build failed or wasn't run; "
                "run ninja and read its error first")
    return None


def rom_region(rom: bytes, off: int) -> str:
    """The part of an NDS image that `off` falls in, from the header's offset/size fields."""
    if off < 0x200:
        return f"header (field at {off:#x})"
    word = lambda o: struct.unpack_from("<I", rom, o)[0]  # noqa: E731
    parts = [("ARM9", 0x20, 0x2C), ("ARM7", 0x30, 0x3C), ("file name table", 0x40, 0x44),
             ("file allocation table", 0x48, 0x4C), ("ARM9 overlay table", 0x50, 0x54),
             ("ARM7 overlay table", 0x58, 0x5C)]
    for name, o, s in parts:
        if word(o) <= off < word(o) + word(s):
            return f"{name} (+{off - word(o):#x})"
    if word(0x68) and word(0x68) <= off < word(0x68) + 0xA00:
        return f"banner (+{off - word(0x68):#x})"
    fat, fat_size = word(0x48), word(0x4C)
    for fid in range(fat_size // 8):
        start, end = word(fat + fid * 8), word(fat + fid * 8 + 4)
        if start <= off < end:
            return f"file id {fid} (+{off - start:#x})"
    return "padding between parts"


def diff_rom_file():
    """Compares the whole rebuilt ROM with the base ROM and names the part of the first difference."""
    base_path = ROOT / VERSIONS[VERSION]["baserom"]
    built_path = ROOT / "build" / VERSION / f"{GAME}_{VERSION}.nds"
    if not base_path.is_file() or not built_path.is_file():
        print(f"ROM: {built_path.relative_to(ROOT)} or {base_path.relative_to(ROOT)} missing")
        return
    base, built = base_path.read_bytes(), built_path.read_bytes()
    if base == built:
        print(f"ROM: {built_path.relative_to(ROOT)} matches byte for byte")
        return
    first = next((i for i in range(min(len(base), len(built))) if base[i] != built[i]), min(len(base), len(built)))
    count = sum(1 for x, y in zip(base, built) if x != y) + abs(len(base) - len(built))
    print(f"ROM: {count} byte(s) differ (sizes {len(built):#x} built, {len(base):#x} base); first at {first:#x}, in "
          f"{rom_region(base, first)}")


if __name__ == "__main__":
    main()
