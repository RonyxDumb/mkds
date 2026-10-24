#!/usr/bin/env python3
"""Turns mwcc "multidef" definitions (binding 13) in a compiled object into mwld weak definitions (binding 14).

In C++ code, function-local statics of inline functions (singleton instances and their guards,
`_ZZ...`/`_ZGVZ...`) are emitted by every file that uses them, and the original link keeps one copy. dsd writes
that copy as weak (14), and mwld prefers a multidef copy over a weak one, so without this a decompiled file would
take over the object and every reference to it would move. As weak definitions, the first one in link order (the
original's) wins. The same goes for functions every user emits (virtual thunks, inline methods): against the
original's copy, still delinked as a global, a multidef copy is a duplicate-definition error, while a weak one
is dropped.

Usage: demote_multidef.py <object.o>...
"""
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

STB_MW_MULTIDEF = 13
STB_MW_WEAK = 14

for path in map(Path, sys.argv[1:]):
    data = bytearray(path.read_bytes())
    with open(path, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            continue
        base, size = symtab["sh_offset"], symtab["sh_entsize"]
        for i, sym in enumerate(symtab.iter_symbols()):
            p = base + i * size + 12  # st_info
            if data[p] >> 4 == STB_MW_MULTIDEF and sym["st_shndx"] != "SHN_UNDEF":
                data[p] = (STB_MW_WEAK << 4) | (data[p] & 0xF)
    path.write_bytes(data)
