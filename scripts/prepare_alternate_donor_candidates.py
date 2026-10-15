"""Compile alternate pure-C donor drafts, without trusting donor matching claims.

Run prepare_mkds_candidates.py first, then this script with the same donor path.
Pass build/mkds-extra/config.json to verify_sdk_sources.py for fresh byte checks.
"""
from pathlib import Path
import concurrent.futures
import hashlib
import json
import os
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
donor = Path(sys.argv[1]).resolve()
assert subprocess.check_output(['git', '-C', str(donor), 'rev-parse', 'HEAD'], text=True).strip() == 'c6e18fa4b346643b74c402b605a84b43cba16c01'
assert not subprocess.check_output(['git', '-C', str(donor), 'status', '--porcelain'], text=True).strip()
config = json.loads((ROOT / 'build/mkds-candidates/config.json').read_text())
known = {v['source'] for v in config['objects'].values()}
paths = []
for source in donor.rglob('*.c'):
    relative = str(source.relative_to(donor))
    if relative in known:
        continue
    clean = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"', '', source.read_text(errors='replace'), flags=re.S)
    if re.search(r'\b(?:asm|__asm|__asm__)\b|^\s*#\s*include', clean, re.M):
        continue
    if re.search(r'\[[^\]]*\]\s*=\s*\{', clean):
        continue
    paths.append(relative)
out = ROOT / 'build/mkds-extra'
out.mkdir(parents=True, exist_ok=True)
flags = ['-O4,p', '-enum', 'int', '-lang', 'c99', '-char', 'signed', '-interworking', '-proc', 'arm946e', '-gccext,on', '-msgstyle', 'gcc']


def compile_source(path):
    name = hashlib.sha256(path.encode()).hexdigest()[:16] + '.o'
    obj = out / name
    obj.unlink(missing_ok=True)
    result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *flags, '-c', str(donor / path), '-o', str(obj)], capture_output=True, timeout=30)
    return name, dict(source=path, flags=flags), result.returncode


with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    results = list(pool.map(compile_source, paths))
objects = {name: value for name, value, code in results if code == 0}
(out / 'config.json').write_text(json.dumps(dict(object_directory='build/mkds-extra', objects=objects, complete_translation_unit=True, target_modules=['arm9']), indent=2) + '\n')
summary = dict(candidate_sources=len(paths), compiled_objects=len(objects), full_rom_link_verified=False)
(out / 'build-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary))
