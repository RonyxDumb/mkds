#!/usr/bin/env python3
"""Prepare ROM-bound section targets and bounded melonDS GDB observations.

No runtime observations or matching claims are made by preparation alone.
"""
import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def prepare(rom, output, cpu, port):
    manifest = json.loads((ROOT / 'baseline/manifest.json').read_text())
    digest = hashlib.sha1(rom.read_bytes()).hexdigest()
    if digest != manifest['sha1']:
        raise ValueError('Wrong reference ROM SHA-1: ' + digest)
    modules = []
    for module in manifest['modules']:
        sections = []
        for section in module['sections']:
            path = ROOT / 'baseline/binaries' / section['file']
            data = path.read_bytes()
            if len(data) != section['size']:
                raise ValueError('Section size mismatch: ' + str(path))
            sections.append({**section, 'sha256': hashlib.sha256(data).hexdigest()})
        modules.append({**module, 'sections': sections,
                        'overlay': '_ov' in module['name']})
    proofs = set()
    for filename in ('local-byte-exact.tsv', 'local-linked-byte-exact.tsv'):
        with (ROOT / 'verification' / filename).open() as stream:
            for row in csv.DictReader(stream, delimiter='\t'):
                proofs.add((row['module'], int(row['address'], 16)))
    # Main CPU modules only: overlay identities require a runtime load check.
    candidates = []
    with (ROOT / 'baseline/pseudocode' / cpu / 'index.tsv').open() as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            if (cpu, int(row['address'], 16)) not in proofs:
                candidates.append({'address': row['address'], 'name': row['name'],
                                   'bytes': int(row['bytes'])})
    candidates.sort(key=lambda row: (-row['bytes'], row['address']))
    output.mkdir(parents=True, exist_ok=True)
    plan = {'rom_sha1': digest, 'modules': modules, 'cpu': cpu,
            'unmatched_targets': candidates[:30], 'runtime_observed': False,
            'full_rom_link_verified': False,
            'rea_raw_arm_language': 'ARM:LE:32:v7',
            'rea_raw_arm_suitable_for_ds_matching': False}
    (output / 'targets.json').write_text(json.dumps(plan, indent=2) + '\n')
    # No automatic continue: let the analyst select one target after observing
    # the stopped CPU. Do not install thousands of breakpoints or single-step
    # the entire game. Eight decoded instructions are an observation only.
    commands = [
        'set pagination off', 'set confirm off', 'set remotetimeout 10',
        'set architecture arm', f'target remote 127.0.0.1:{port}',
        'info registers', 'x/8i $pc',
        '# Select one address from targets.json:',
        '# hbreak *0xADDRESS', '# continue',
        '# At the stop, capture r0-r3, sp, lr, pc and cpsr; infer Thumb from CPSR.',
        '# Do not treat a runtime hit as a byte-matching proof.',
        '# For overlays verify loaded bytes before assigning a module name.',
    ]
    (output / f'{cpu}.gdb').write_text('\n'.join(commands) + '\n')
    return plan


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path)
    parser.add_argument('--cpu', choices=('arm9', 'arm7'), default='arm9')
    parser.add_argument('--port', type=int)
    parser.add_argument('--output', type=Path, default=ROOT / 'build/dynamic-analysis')
    args = parser.parse_args()
    port = args.port if args.port is not None else (3333 if args.cpu == 'arm9' else 3334)
    if not 1 <= port <= 65535:
        parser.error('Invalid TCP port')
    try:
        plan = prepare(args.rom, args.output, args.cpu, port)
    except (ValueError, OSError) as error:
        parser.exit(1, str(error) + '\n')
    print(f"Prepared {len(plan['modules'])} modules and {len(plan['unmatched_targets'])} targets; runtime not observed")


if __name__ == '__main__':
    main()
