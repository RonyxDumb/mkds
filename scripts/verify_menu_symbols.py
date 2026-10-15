#!/usr/bin/env python3
"""Independently verify the reference evidence for new menu symbol bindings."""
from pathlib import Path
import csv
import hashlib
import json
from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM

ROOT = Path(__file__).resolve().parents[1]


def main():
    evidence = json.loads((ROOT / 'verification/menu-symbol-evidence.json').read_text())
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    section = next(s for m in manifest['modules'] if m['name'] == 'arm9'
                   for s in m['sections'] if s['file'] == evidence['reference_section'])
    data = (ROOT / 'baseline/binaries' / section['file']).read_bytes()
    assert hashlib.sha256(data).hexdigest() == evidence['reference_sha256']
    bindings = {(r['module'], r['name']): r for r in csv.DictReader(
        (ROOT / 'verification/sdk-extra-symbols.tsv').open(), delimiter='\t')}
    for entry in evidence['bindings']:
        address = int(entry['evidence_address'], 16)
        offset = address - section['base']
        value = data[offset:offset + 4]
        assert len(value) == 4
        target = int(entry['address'], 16)
        if entry['kind'] == 'literal':
            assert int.from_bytes(value, 'little') == target
        elif entry['kind'] == 'arm-blx':
            instructions = list(Cs(CS_ARCH_ARM, CS_MODE_ARM).disasm(value, address))
            assert len(instructions) == 1 and instructions[0].mnemonic == 'blx'
            assert int(instructions[0].op_str.lstrip('#'), 0) == target
        else:
            raise ValueError('Unknown evidence kind')
        binding = bindings[(entry['module'], entry['name'])]
        assert int(binding['address'], 16) == target
        assert (binding['thumb'] == '1') == entry['thumb']
    print('Verified', len(evidence['bindings']), 'menu symbol bindings against reference literals and ARM BLX')


if __name__ == '__main__':
    main()
