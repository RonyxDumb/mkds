#!/usr/bin/env python3
"""Reproduce the published corpus and hybrid build from a private reference ROM.

Stops at the first failed stage, keeps logs and a machine-readable completion
record. A different physical hybrid ROM is an expected comparison result,
never a successful independent source reconstruction.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path)
    parser.add_argument('--setup-toolchain', action='store_true')
    args = parser.parse_args()
    rom = args.rom.resolve()
    if not rom.is_file():
        parser.error('Reference ROM does not exist')
    output = ROOT / 'build/checkpoint-validation'
    output.mkdir(parents=True, exist_ok=True)
    env = dict(os.environ)
    env.setdefault('MKDS_BASELINE', str(ROOT / 'baseline'))
    env.setdefault('WIBO', str(ROOT / 'tools/wibo'))
    env.setdefault('MWCCARM', str(ROOT / 'tools/mwccarm/1.2/sp2p3/mwccarm.exe'))
    steps = []
    if args.setup_toolchain:
        steps.append(('toolchain', 'setup_matching_toolchain.py', []))
    steps += [
        ('extract', 'prepare_rom.py', [str(rom)]),
        ('unrelocated', 'audit_current_unrelocated.py', []),
        ('linked', 'audit_resolved_calls.py', []),
        ('race-semantics', 'test_race_semantics.py', []),
        ('comparison-tests', 'test_compare_rom.py', []),
        ('hybrid', 'build_hybrid_rom.py', [str(rom)]),
        ('report', 'export_objdiff_report.py', ['--output', str(output / 'report.json')]),
    ]
    summary = {'completed': False, 'full_source_reconstruction_verified': False, 'stages': []}
    (output / 'status.json').write_text(json.dumps(summary, indent=2) + '\n')
    for name, script, arguments in steps:
        summary['current_stage'] = name
        (output / 'status.json').write_text(json.dumps(summary, indent=2) + '\n')
        print('Running ' + name + ' (log: ' + str(output / (name + '.log')) + ')', flush=True)
        with (output / (name + '.log')).open('w') as log:
            try:
                code = subprocess.run([sys.executable, str(ROOT / 'scripts' / script), *arguments],
                                      cwd=ROOT, env=env, stdout=log, stderr=subprocess.STDOUT).returncode
            except OSError as error:
                log.write(str(error) + '\n')
                code = 1
        summary['stages'].append({'stage': name, 'exit_code': code})
        (output / 'status.json').write_text(json.dumps(summary, indent=2) + '\n')
        if code:
            print('Failed: ' + name + '. See log; later stages were not run.', file=sys.stderr)
            return 1
    summary['completed'] = True
    summary['current_stage'] = None
    (output / 'status.json').write_text(json.dumps(summary, indent=2) + '\n')
    print('Published local corpus and hybrid checks passed; independent full-ROM build remains unverified.')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
