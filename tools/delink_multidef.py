#!/usr/bin/env python3
"""Gives weak symbols in delinked objects mwld's "multidef" binding.

mwcc emits function-local statics of inline functions (and similar shared definitions) with a
processor-specific binding (13) that mwld resolves to the first definition it sees. Every source file that
uses such an inline emits its own copy, and the linker keeps the first one it sees. Delinked objects carry
the kept copy, which dsd writes as an ordinary weak symbol. mwld would prefer a compiled multidef copy over
a weak symbol, so this rewrites STB_WEAK to 13. The delinked objects come first in link order, so their
copies win, as in the original build.

Mark such symbols `weak` in symbols.txt; run on the delinked objects after `dsd delink`.
"""
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

STB_WEAK = 2
STB_MW_MULTIDEF = 13

for path in map(Path, sys.argv[1:]):
    data = bytearray(path.read_bytes())
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            continue
        base, size = symtab["sh_offset"], symtab["sh_entsize"]
        for i, sym in enumerate(symtab.iter_symbols()):
            if sym["st_info"]["bind"] == "STB_WEAK" and sym["st_shndx"] != "SHN_UNDEF":
                p = base + i * size + 12  # st_info
                data[p] = (STB_MW_MULTIDEF << 4) | (data[p] & 0xF)
    path.write_bytes(data)
