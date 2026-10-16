#!/usr/bin/env python3
"""Freshly compile, independently audit and register exact batch candidates.

Search summaries are untrusted suggestions: source and object bytes are never
accepted solely because a summary or cache reports a match. Prior proofs remain
unchanged. Checkpoint metadata is left for the caller to update deliberately.
"""
import argparse
import csv
import importlib
import json
import os
from pathlib import Path
import subprocess
import hashlib
from batch_matching import ROOT, MatchingContext, Candidate, Search, atomic_json, digest
from proof_span import validate_span
from matching_compiler import compiler_record


def write_proof_json(path, value):
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n')
    temporary.replace(path)


def write_registry(path, rows):
    temporary = path.with_suffix('.tmp')
    with temporary.open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=rows[0], delimiter='\t', lineterminator='\n')
        writer.writeheader()
        writer.writerows(rows)
    temporary.replace(path)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('summaries', type=Path, nargs='+')
    parser.add_argument('--audit-name', default='batch-matching-audit.json')
    args = parser.parse_args()
    if Path(args.audit_name).name != args.audit_name or not args.audit_name.endswith('.json'):
        parser.error('audit name must be a JSON filename')
    audit_path = ROOT / 'verification' / args.audit_name
    if audit_path.exists():
        parser.error('Audit already exists; choose a new filename to preserve historical proofs')
    os.environ.setdefault('MKDS_BASELINE', str(ROOT / 'baseline'))
    os.environ.setdefault('WIBO', str(ROOT / 'tools/wibo'))
    os.environ.setdefault('MWCCARM', str(ROOT / 'tools/mwccarm/1.2/sp2p3/mwccarm.exe'))
    context = MatchingContext(ROOT, Path(os.environ['MKDS_BASELINE']))
    independent = importlib.import_module('audit_resolved_calls')
    runner = Search(context, os.environ['MWCCARM'], os.environ['WIBO'], ROOT / 'build/batch-accept', ['-O4,p'])
    paths = [ROOT / 'verification' / name for name in ['local-byte-exact.tsv', 'local-linked-byte-exact.tsv']]
    registries = [list(csv.DictReader(path.open(), delimiter='\t')) for path in paths]
    known = {(r['module'], int(r['address'], 16)) for rows in registries for r in rows}
    entries = json.loads((ROOT / 'verification/hash-only-proofs.json').read_text())
    batch_path = ROOT / 'verification/batch-source-proofs.json'
    batch_proofs = json.loads(batch_path.read_text()) if batch_path.exists() else {}
    compiler_variant = compiler_record(ROOT)
    new = []
    audit = {'new_matches': new, 'total_functions': 0, 'full_rom_link_verified': False,
             'scope': 'Fresh targeted compilation of this batch only; earlier proofs retain their own audits.',
             'compiler_sha256': digest(runner.compiler.read_bytes()),
             'fresh_audits': {'resolved': {'tested': 0, 'passed': 0}, 'unrelocated': {'tested': 0, 'passed': 0}}}
    # Validate every candidate before changing either registry.
    pending = []
    for summary in args.summaries:
        for item in json.loads(summary.read_text())['exact']:
            module, address = item['module'], int(item['address'], 16)
            if (module, address) in known:
                continue
            name, mode, size = context.inventory[module, address]
            if (item['name'], item['mode'], item['size']) != (name, mode, size):
                raise ValueError('Candidate no longer agrees with reference inventory')
            source = Path(item['source']).read_text()
            original = context.original(module, address, size)
            candidate = Candidate(module, name, mode, address, size, item['variant'], source, original)
            result = runner.compile(candidate, item['optimization'], use_cache=False)
            if result['outcome'] != 'exact':
                raise ValueError('Fresh compilation rejected ' + candidate.tag)
            pending.append((candidate, result))
            known.add((module, address))
    for candidate, result in pending:
        module, address, name = candidate.module, candidate.address, candidate.name
        path = ROOT / 'src' / module / f'{address:08x}_{name}.c'
        previous = path.read_bytes()
        backup = ROOT / 'verification/previous_drafts' / module / path.name
        backup.parent.mkdir(parents=True, exist_ok=True)
        if not backup.exists():
            backup.write_bytes(previous)
        path.write_text('/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */\n' + candidate.source)
        relocs = result['relocations']
        row = dict(module=module, name=name, mode=candidate.mode, address=f'0x{address:08x}', size=str(candidate.size),
                   sha256=digest(candidate.original), source_sha256=digest(path.read_bytes()), relocations=str(len(relocs)),
                   optimization=result['optimization'], processor='arm7tdmi' if module == 'arm7' else 'arm946e',
                   status='EXACT_LOCAL_LINKED_BYTES' if relocs else 'EXACT_LOCAL_BYTES')
        if not relocs:
            row['kind'] = 'mw_batch_draft'
        metadata = {'flags': result['flags'], 'source_sha256': row['source_sha256']}
        if compiler_variant is not None:
            metadata['compiler'] = compiler_variant
        independent.overrides[candidate.tag] = metadata
        try:
            independent.verify(row)
            index = ROOT / 'baseline/pseudocode' / module / 'index.tsv'
            inventory_row = next(r for r in csv.DictReader(index.open(), delimiter='\t') if int(r['address'], 16) == address)
            inventory_size = int(inventory_row['bytes'])
            validate_span(candidate.original, address, candidate.mode, inventory_size)
        except BaseException:
            path.write_bytes(previous)
            raise
        if relocs:
            write_proof_json(ROOT / 'verification/resolved-calls' / (candidate.tag+'.relocations.json'), relocs)
        registries[1 if relocs else 0].append(row)
        new.append(row)
        bucket = audit['fresh_audits']['resolved' if relocs else 'unrelocated']
        bucket['tested'] += 1
        bucket['passed'] += 1
        audit['total_functions'] += 1
        entries[candidate.tag] = {**{key: row[key] for key in ['sha256', 'source_sha256']}, 'size': candidate.size, 'audit': args.audit_name}
        if inventory_size != candidate.size:
            entries[candidate.tag]['inventory_size']=inventory_size
            audit.setdefault('span_checks',{})[candidate.tag]={
                'validator':'proof_span.validate_span','inventory_size':inventory_size,
                'span_size':candidate.size,'sha256':row['sha256'],'validated':True}
        batch_proofs[candidate.tag] = metadata
        # Each completed proof is independently resumable. Never lose prior successes.
        write_proof_json(audit_path, audit)
        write_proof_json(ROOT / 'verification/hash-only-proofs.json', entries)
        write_proof_json(batch_path, batch_proofs)
        for registry, rows in zip(paths, registries):
            write_registry(registry, rows)
        print('ACCEPTED', candidate.tag, candidate.size, len(relocs), flush=True)
    if not pending:
        print('No unregistered candidates')
    else:
        print(json.dumps({'functions': len(new), 'bytes': sum(int(r['size']) for r in new)}))


if __name__ == '__main__':
    main()
