#!/usr/bin/env python3
"""Reject lost exact proofs, changed reference inventories and stale source hashes."""
import argparse
import csv
import hashlib
import io
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[1]
REGISTRIES = ('verification/local-byte-exact.tsv', 'verification/local-linked-byte-exact.tsv')

def git_bytes(ref, path):
    return subprocess.check_output(['git', 'show', f'{ref}:{path}'], cwd=ROOT)

def rows(data):
    return list(csv.DictReader(io.StringIO(data.decode()), delimiter='\t'))

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--base', required=True, help='Immutable previous commit SHA')
    args = parser.parse_args()
    base = subprocess.check_output(['git', 'rev-parse', args.base + '^{commit}'], cwd=ROOT, text=True).strip()
    previous, current = {}, {}
    for path in REGISTRIES:
        for row in rows(git_bytes(base, path)):
            key = (row['module'], row['address'])
            if key in previous:
                raise ValueError(f'Duplicate previous proof: {key}')
            previous[key] = row
        for row in rows((ROOT / path).read_bytes()):
            key = (row['module'], row['address'])
            if key in current:
                raise ValueError(f'Duplicate current proof: {key}')
            current[key] = row
    missing = previous.keys() - current.keys()
    if missing:
        raise ValueError(f'Lost exact proofs: {sorted(missing)}')
    for key, old in previous.items():
        for field in ('sha256', 'size', 'mode'):
            if old[field] != current[key][field]:
                raise ValueError(f'Changed reference proof: {key} {field}')
    for row in current.values():
        source = ROOT / 'src' / row['module'] / f"{int(row['address'], 16):08x}_{row['name']}.c"
        if hashlib.sha256(source.read_bytes()).hexdigest() != row['source_sha256']:
            raise ValueError(f'Stale source proof: {source}')
    fuzzy_path = 'verification/fuzzy-candidates.json'
    old_fuzzy = json.loads(git_bytes(base, fuzzy_path))['candidates']
    fuzzy = json.loads((ROOT / fuzzy_path).read_text())['candidates']
    fuzzy_keys = {(r['module'], int(r['address'], 16)) for r in fuzzy}
    exact_keys = {(module, int(address, 16)) for module, address in current}
    if len(fuzzy_keys) != len(fuzzy) or fuzzy_keys & exact_keys:
        raise ValueError('Duplicate fuzzy entries or fuzzy counted as exact')
    for row in old_fuzzy:
        key = row['module'], int(row['address'], 16)
        if key not in fuzzy_keys | exact_keys:
            raise ValueError(f'Lost fuzzy candidate: {key}')
    for row in fuzzy:
        if hashlib.sha256((ROOT / row['source']).read_bytes()).hexdigest() != row['source_sha256']:
            raise ValueError('Stale fuzzy source hash')
    inventories = ['baseline/manifest.json'] + [str(p.relative_to(ROOT)) for p in sorted((ROOT / 'baseline/pseudocode').glob('*/index.tsv'))]
    for path in inventories:
        if git_bytes(base, path) != (ROOT / path).read_bytes():
            raise ValueError(f'Reference inventory changed: {path}')
    body_sizes = {}
    for path in inventories[1:]:
        module = Path(path).parent.name
        for row in rows((ROOT / path).read_bytes()):
            body_sizes[module, int(row['address'], 16)] = int(row['bytes'])
    exact_bytes = sum(body_sizes[module, int(address, 16)] for module, address in current)
    measured = json.loads((ROOT / 'reports/progress-measured.json').read_text())
    progress = json.loads((ROOT / 'PROGRESSO.json').read_text())
    total = sum(body_sizes.values())
    for record, count_key, bytes_key, percent_key in (
        (measured, 'local_byte_exact_functions', 'local_byte_exact_bytes', 'local_byte_exact_percent'),
        (progress, 'local_byte_exact_functions', 'local_byte_exact_code_bytes', 'local_byte_exact_percent_by_function_body_bytes'),
    ):
        if record[count_key] != len(current) or record[bytes_key] != exact_bytes or record['identified_function_bytes'] != total:
            raise ValueError('Progress metadata disagrees with proof inventory')
        if abs(record[percent_key] - 100 * exact_bytes / total) > 1e-9:
            raise ValueError('Progress percentage disagrees with proof inventory')
    print(json.dumps(dict(base_commit=base, previous_exact=len(previous), current_exact=len(current), added=len(current)-len(previous), lost=0, reference_inventory_unchanged=True, source_hashes_verified=True, fresh_byte_recompilation=False)))

if __name__ == '__main__':
    main()
