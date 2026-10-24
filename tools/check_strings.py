#!/usr/bin/env python3
"""Checks that string literals used by matching functions are the same strings the original uses.

Probes and objdiff mask relocated words, so a function that loads the wrong file name or message still "matches".
For each fully matching function, every 4-byte pool word that our object relocates against a string in its own
.data/.rodata (a local `@N` literal or a named char array) is compared with the original: the original's pool word
at the same offset is an address, and the NUL-terminated bytes there must equal our string.

Usage: check_strings.py [object.o ...]   (default: every object under build/<ver>/src and build/<ver>/libs)
"""
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).parent))
from check_calls import ROOT, load_symbols, matched_functions, module_bytes, module_of  # noqa: E402
from project import VERSION  # noqa: E402  (tools/project.py)


def cstring(data, off, limit=256):
    end = data.find(b"\0", off, off + limit)
    return None if end < 0 else data[off:end]


def main():
    tables = load_symbols()
    matched = matched_functions()
    images = {}

    def image_for(addr, own):
        # overlays share load addresses: try the function's own module, then main and the TCMs
        for mod in [own, "main", "itcm", "dtcm"] + [m for m in tables if m not in (own, "main", "itcm", "dtcm")]:
            if mod not in tables and mod not in ("itcm", "dtcm"):
                continue
            if mod not in images:
                try:
                    images[mod] = module_bytes(mod)
                except Exception:
                    images[mod] = (0, b"")
            base, blob = images[mod]
            if base <= addr < base + len(blob):
                return base, blob
        return None

    objs = [Path(p).resolve() for p in sys.argv[1:]] or sorted(
        [*(ROOT / f"build/{VERSION}/src").rglob("*.o"), *(ROOT / f"build/{VERSION}/libs").rglob("*.o")])
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
                     and s["st_size"] and s.name in local and s.name in matched]
            for sec in elf.iter_sections():
                if not isinstance(sec, RelocationSection) or not sec.name.startswith(".rel"):
                    continue
                text = elf.get_section(sec["sh_info"])
                tdata = text.data()
                for r in sec.iter_relocations():
                    if r["r_info_type"] != 2:  # R_ARM_ABS32: pool words
                        continue
                    fn = next((f for f in funcs if f["st_shndx"] == sec["sh_info"]
                               and f["st_value"] <= r["r_offset"] < f["st_value"] + f["st_size"]), None)
                    if fn is None:
                        continue
                    sym = syms[r["r_info_sym"]]
                    if not isinstance(sym["st_shndx"], int):
                        continue  # external: checked by name through symbols.txt
                    tsec = elf.get_section(sym["st_shndx"])
                    if tsec.name not in (".data", ".rodata") or tsec["sh_type"] == "SHT_NOBITS":
                        continue
                    # RELA entries carry the addend; REL ones keep it in the pool word.
                    addend = r["r_addend"] if r.is_RELA() else struct.unpack_from("<I", tdata, r["r_offset"])[0]
                    ours = cstring(tsec.data(), sym["st_value"] + addend)
                    if not ours or len(ours) < 3 or not all(32 <= c < 127 for c in ours):
                        continue  # only printable strings
                    site = local[fn.name] + r["r_offset"] - fn["st_value"]
                    if not base <= site < base + len(blob) - 3:
                        continue
                    target = struct.unpack_from("<I", blob, site - base)[0]
                    img = image_for(target, module)
                    if img is None:
                        continue
                    theirs = cstring(img[1], target - img[0])
                    if theirs != ours:
                        print(f"{obj.relative_to(ROOT)}: {fn.name}+{r['r_offset'] - fn['st_value']:#x}: "
                              f"ours {ours!r}, the original {theirs!r}")
                        problems += 1
    print(f"{problems} string(s) differ")
    sys.exit(1 if problems else 0)


if __name__ == "__main__":
    main()
