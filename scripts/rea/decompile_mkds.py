#!/usr/bin/env python3
"""Decompile one inventoried MKDS function with an explicit DS CPU/ISA profile.

Outputs are analysis drafts, never byte-matching proofs. Each overlay is an
independent target; external data, callee bodies and literal pools outside the
inventoried span are unavailable and may reduce the quality of the result.
"""
import argparse
import csv
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[2]


def prepare(module, address, mode=None):
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    modules = {row['name']: row for row in manifest['modules']}
    if module not in modules:
        raise ValueError('Unknown module: ' + module)
    index = ROOT / 'baseline/pseudocode' / module / 'index.tsv'
    rows = [row for row in csv.DictReader(index.open(), delimiter='\t')
            if int(row['address'], 16) == address]
    if len(rows) != 1 or int(rows[0]['bytes']) <= 0:
        raise ValueError('Expected one nonempty inventoried function')
    row = rows[0]
    symbols = (ROOT / 'baseline/symbols' / (module + '.txt')).read_text()
    found = re.findall(r'kind:function\((arm|thumb),size=0x[0-9a-fA-F]+\) addr:0x0*' +
                       format(address, 'x') + r'(?:\s|$)', symbols)
    if len(set(found)) > 1:
        raise ValueError('Conflicting symbol ISA modes')
    if found:
        if mode is not None and mode != found[0]:
            raise ValueError('Explicit mode conflicts with the symbol map')
        mode = found[0]
    if mode is None:
        raise ValueError('No symbol ISA mode; supply --mode from verified disassembly')
    if address % (2 if mode == 'thumb' else 4):
        raise ValueError('Unaligned entry for selected ISA')
    size = int(row['bytes'])
    sections = [s for s in modules[module]['sections']
                if s['base'] <= address and address + size <= s['base'] + s['size']]
    if len(sections) != 1:
        raise ValueError('Function span must belong to one initialized section')
    section = sections[0]
    data = (ROOT / 'baseline/binaries' / section['file']).read_bytes()
    if len(data) != section['size']:
        raise ValueError('Reference section size differs from manifest')
    offset = address - section['base']
    code = data[offset:offset + size]
    return code, {'module': module, 'name': row['name'], 'address': hex(address),
                  'bytes': size, 'mode': mode,
                  'profile': 'nds-arm7' if module == 'arm7' else 'nds-arm9',
                  'reference_rom_sha1': manifest['sha1'],
                  'section': section['file'], 'section_offset': offset,
                  'section_sha256': hashlib.sha256(data).hexdigest(),
                  'sha256': hashlib.sha256(code).hexdigest(),
                  'limitations': ['Isolated inventory span; external memory and callees unavailable.',
                                  'Pseudocode is an analysis draft, not matching C.']}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('module')
    parser.add_argument('address', type=lambda value: int(value, 0))
    parser.add_argument('--mode', choices=['arm', 'thumb'])
    parser.add_argument('--output', type=Path, default=ROOT / 'build/rea-mkds')
    args = parser.parse_args()
    code, metadata = prepare(args.module, args.address, args.mode)
    output = args.output.resolve() / (args.module + '_' + format(args.address, '08x'))
    output.mkdir(parents=True, exist_ok=True)
    target = output / 'function.bin'
    target.write_bytes(code)
    environment = dict(os.environ, REA_GHIDRA_ARM_PROFILE=metadata['profile'],
                       REA_GHIDRA_ARM_MODE=metadata['mode'])
    command = ['sh', str(ROOT / 'scripts/rea/run.sh'), 'decompile', str(target),
               hex(args.address), '--provider', 'ghidra', '--target-format', 'raw-binary',
               '--architecture', 'arm', '--entry-point', hex(args.address), '--format', 'json']
    result = subprocess.run(command, env=environment, capture_output=True, text=True, timeout=240)
    (output / 'stderr.log').write_text(result.stderr)
    if result.returncode:
        raise SystemExit(result.stderr or result.stdout or 'REA failed without diagnostic')
    evidence = json.loads(result.stdout)
    parameters = evidence['analysis_profile']['parameters']
    expected_language = 'ARM:LE:32:v4t' if args.module == 'arm7' else 'ARM:LE:32:v5t'
    if (evidence['subject']['digest']['sha256'] != metadata['sha256'] or
            parameters['language_id'] != expected_language or
            parameters.get('arm_entry_mode') != metadata['mode'] or
            int(parameters['entry_point'], 16) != args.address or
            not isinstance(evidence.get('normalized_result'), str) or
            not evidence['normalized_result'].strip()):
        raise SystemExit('REA evidence does not attest the requested target/profile or has no pseudocode')
    (output / 'evidence.json').write_text(result.stdout)
    (output / 'metadata.json').write_text(json.dumps(metadata, indent=2) + '\n')
    (output / 'draft.c').write_text(evidence['normalized_result'])
    print(json.dumps({'output': str(output), **metadata}))


if __name__ == '__main__':
    main()
