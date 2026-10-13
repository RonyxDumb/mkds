#!/usr/bin/env python3
"""Export a conservative objdiff v2 report from MKDS local byte-exact proofs."""
import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MODULES = {'arm9', 'arm9_ov000', 'arm9_ov001', 'arm9_ov003', 'arm7'}


def measures(total, matched, functions, matched_functions, units=0):
    assert 0 <= matched <= total and 0 <= matched_functions <= functions
    return {
        'total_code': str(total), 'matched_code': str(matched),
        'matched_code_percent': 100 * matched / total if total else 0,
        'fuzzy_match_percent': 100 * matched / total if total else 0,
        'total_functions': functions, 'matched_functions': matched_functions,
        'matched_functions_percent': 100 * matched_functions / functions if functions else 0,
        'total_units': units,
    }


def generate(root, report_input):
    progress = json.loads(report_input.read_text(encoding='utf-8'))
    if progress.get('full_rom_link_verified') is not False:
        raise ValueError('Unexpected verification scope')
    with (root / 'verification/local-byte-exact.tsv').open(encoding='utf-8', newline='') as f:
        proofs = {(r['module'], int(r['address'], 16)): r for r in csv.DictReader(f, delimiter='\t')}
    linked_file = root / 'verification/local-linked-byte-exact.tsv'
    if linked_file.exists():
        with linked_file.open(encoding='utf-8', newline='') as f:
            for r in csv.DictReader(f, delimiter='\t'):
                key = (r['module'], int(r['address'], 16))
                if key in proofs:
                    raise ValueError('Duplicate proof ' + str(key))
                proofs[key] = r
    used, seen, units, categories = set(), set(), [], []
    code = matched = count = matching_count = 0
    for module in progress['modules']:
        name, rows = module['name'], module['functions']
        if name not in MODULES or any(cat['id'] == name for cat in categories):
            raise ValueError('Duplicate or unexpected module: ' + name)
        m_code = m_matched = m_matching_count = 0
        for start in range(0, len(rows), 64):
            entries, u_code, u_matched, u_matched_count = [], 0, 0, 0
            for fname, size, status, address in rows[start:start + 64]:
                size, addr = int(size), int(address, 16)
                key = (name, addr)
                if key in seen or size <= 0 or status not in (0, 1, 2):
                    raise ValueError('Invalid or repeated inventory entry ' + str(key))
                seen.add(key)
                verified = status == 0
                proof = proofs.get(key)
                if verified != (proof is not None):
                    raise ValueError('Missing or unexpected proof ' + str(key))
                if verified:
                    if int(proof['size']) != size or proof['status'] not in ('EXACT_LOCAL_BYTES', 'EXACT_LOCAL_LINKED_BYTES'):
                        raise ValueError('Invalid proof ' + str(key))
                    if proof['status'] == 'EXACT_LOCAL_BYTES':
                        if int(proof['relocations']) != 0:
                            raise ValueError('Unexpected relocation ' + str(key))
                        archived = root / 'verification/leafs' / f'{name}_{addr:08x}.original.hex'
                    else:
                        audit_dir = root / 'verification/resolved-calls'
                        archived = audit_dir / f'{name}_{addr:08x}.linked.hex'
                        relocations = json.loads((audit_dir / f'{name}_{addr:08x}.relocations.json').read_text())
                        if len(relocations) != int(proof['relocations']) or not relocations:
                            raise ValueError('Relocation audit mismatch ' + str(key))
                    original_bytes = bytes.fromhex(archived.read_text())
                    if len(original_bytes) != size or hashlib.sha256(original_bytes).hexdigest() != proof['sha256']:
                        raise ValueError('Archived code proof mismatch ' + str(key))
                    source = root / 'src' / name / f'{addr:08x}_{fname}.c'
                    if hashlib.sha256(source.read_bytes()).hexdigest() != proof['source_sha256']:
                        raise ValueError('Source SHA-256 does not match proof: ' + str(source))
                    used.add(key)
                entries.append({'name': fname, 'size': str(size), 'address': str(addr),
                                'fuzzy_match_percent': 100 if verified else 0})
                u_code += size
                u_matched += size if verified else 0
                u_matched_count += int(verified)
            units.append({'name': f'{name}/{start // 64:04d}',
                          'measures': measures(u_code, u_matched, len(entries), u_matched_count),
                          'functions': entries,
                          'metadata': {'module_name': name, 'progress_categories': [name]}})
            m_code += u_code
            m_matched += u_matched
            m_matching_count += u_matched_count
        if (m_code != module['bytes'] or m_matched != module['exact_bytes'] or
                len(rows) != module['function_count'] or m_matching_count != module['exact_functions']):
            raise ValueError('Module totals mismatch: ' + name)
        categories.append({'id': name, 'name': name.upper(),
                           'measures': measures(m_code, m_matched, len(rows), m_matching_count)})
        code += m_code
        matched += m_matched
        count += len(rows)
        matching_count += m_matching_count
    if used != set(proofs):
        raise ValueError('Some proof records were not represented')
    if (code != progress['identified_function_bytes'] or
            matched != progress['local_byte_exact_bytes'] or
            count != progress['identified_functions'] or
            matching_count != progress['local_byte_exact_functions']):
        raise ValueError('Progress aggregate totals mismatch')
    return {'version': 2, 'measures': measures(code, matched, count, matching_count, len(units)),
            'units': units, 'categories': categories}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=Path, default=ROOT / 'reports/progress-measured.json')
    parser.add_argument('--output', type=Path, default=Path('build/decomp-report/report.json'))
    args = parser.parse_args()
    result = generate(ROOT, args.input)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, separators=(',', ':')) + '\n', encoding='utf-8')
    m = result['measures']
    print(f"Local byte-exact: {m['matched_code']}/{m['total_code']} bytes "
          f"({m['matched_code_percent']:.4f}%), "
          f"{m['matched_functions']}/{m['total_functions']} functions, "
          f"{len(result['units'])} treemap units")
    print('Note: Ghidra-inventory local matching only, NOT whole-ROM completion.')


if __name__ == '__main__':
    main()
