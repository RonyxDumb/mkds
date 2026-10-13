"""Search current C drafts with MW; preserve proofs and checkpoint each exact match."""
from pathlib import Path
import concurrent.futures
import csv
import hashlib
import json
import os
import subprocess

root = Path(__file__).resolve().parents[1]
# Reuse only the candidate preparation and independently audited relocation resolver.
namespace = {'__file__': str(root / 'scripts/verify_large_drafts.py')}
generator = (root / 'scripts/verify_large_drafts.py').read_text().split("print('Candidates'")[0]
generator = generator.replace('size<=2048 or size>32768', 'size>32768')
exec(compile(generator, 'draft-candidates', 'exec'), namespace)
resolver = {'__file__': str(root / 'scripts/verify_resolved_calls.py')}
exec(compile((root / 'scripts/verify_resolved_calls.py').read_text().split("out=root/'verification/resolved-calls'")[0], 'resolver', 'exec'), resolver)
unlinked_path = root / 'verification/local-byte-exact.tsv'
linked_path = root / 'verification/local-linked-byte-exact.tsv'
unlinked = list(csv.DictReader(unlinked_path.open(), delimiter='\t'))
linked = list(csv.DictReader(linked_path.open(), delimiter='\t'))
known = {(r['module'], int(r['address'], 16)) for r in unlinked + linked}
candidates = sorted((f for f in namespace['funcs'] if (f['module'], f['address']) not in known), key=lambda f: -f['size'])
temporary = root / 'build/mw-all-drafts'
temporary.mkdir(parents=True, exist_ok=True)

def search(f):
    tag = f"{f['module']}_{f['address']:08x}"
    source, obj = temporary / (tag + '.c'), temporary / (tag + '.o')
    source.write_text(f['source'])
    processor = 'arm7tdmi' if f['module'] == 'arm7' else 'arm946e'
    for opt in ['-O4,p', '-O2', '-O3', '-O4,s', '-O1', '-O0']:
        args = [os.environ['WIBO'], os.environ['MWCCARM'], opt, '-enum', 'int', '-lang', 'c99',
                '-char', 'signed', '-interworking', '-proc', processor, '-gccext,on']
        if f['mode'] == 'thumb': args += ['-thumb']
        try:
            result = subprocess.run(args + ['-c', str(source), '-o', str(obj)], capture_output=True, timeout=30)
        except subprocess.TimeoutExpired:
            continue
        if result.returncode: continue
        try:
            code, relocs = resolver['linked'](obj.read_bytes(), f['module'], f['name'], f['address'])
        except (ValueError, StopIteration, KeyError):
            continue
        if code == f['original']:
            return f, code, relocs, opt, processor, obj.read_bytes()
    return None

def checkpoint(path, rows):
    temporary_path = path.with_suffix('.tmp')
    with temporary_path.open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]), delimiter='\t')
        writer.writeheader(); writer.writerows(rows)
    temporary_path.replace(path)

accepted = 0
print('Candidates', len(candidates), flush=True)
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    for i, result in enumerate(pool.map(search, candidates), 1):
        if result:
            f, code, relocs, opt, processor, obj = result
            tag = f"{f['module']}_{f['address']:08x}"
            dest = root / 'src' / f['module'] / f"{f['address']:08x}_{f['name']}.c"
            backup = root / 'verification/previous_drafts' / f['module'] / dest.name
            backup.parent.mkdir(parents=True, exist_ok=True)
            if not backup.exists(): backup.write_bytes(dest.read_bytes())
            dest.write_text('/* MW build 82: entire local function bytes verified. Full ROM and caller ABI remain unverified. */\n' + f['source'])
            row = dict(module=f['module'], name=f['name'], mode=f['mode'], address=f"0x{f['address']:08x}", size=f['size'],
                       sha256=hashlib.sha256(code).hexdigest(), source_sha256=hashlib.sha256(dest.read_bytes()).hexdigest(),
                       relocations=len(relocs), optimization=opt, processor=processor,
                       status='EXACT_LOCAL_LINKED_BYTES' if relocs else 'EXACT_LOCAL_BYTES')
            if relocs:
                evidence = root / 'verification/resolved-calls'
                (evidence / (tag + '.linked.hex')).write_text(code.hex() + '\n')
                (evidence / (tag + '.relocations.json')).write_text(json.dumps(relocs, indent=2) + '\n')
                linked.append(row); checkpoint(linked_path, linked)
            else:
                evidence = root / 'verification/leafs'
                (evidence / (tag + '.original.hex')).write_text(code.hex() + '\n')
                (evidence / (tag + '.c')).write_text(f['source'])
                row['kind'] = 'mw_current_draft'
                unlinked.append(row); checkpoint(unlinked_path, unlinked)
            (evidence / (tag + '.o')).write_bytes(obj)
            accepted += 1
            print('MATCH', tag, len(code), opt, flush=True)
        if i % 100 == 0: print('Checked', i, 'new matches', accepted, flush=True)
print(json.dumps(dict(tested=len(candidates), new_matches=accepted)), flush=True)
