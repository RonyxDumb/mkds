"""Compile pure C donor files for a complete-byte search; never count build success as matching."""
from pathlib import Path
import argparse
import concurrent.futures
import hashlib
import json
import os
import re
import subprocess

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('donor', type=Path)
args = parser.parse_args()
donor = args.donor.resolve()
out = root / 'build/donor-candidates'
out.mkdir(parents=True, exist_ok=True)
header = root / 'vendor/sm64ds/include/types.h'
header.parent.mkdir(parents=True, exist_ok=True)
header.write_bytes((donor / 'include/types.h').read_bytes())
headers = {str(p.relative_to(root)): hashlib.sha256(p.read_text().encode()).hexdigest()
           for p in sorted((root / 'vendor').rglob('*'))
           if p.is_file() and p.suffix in ['.h', '.inc', '.def']}
manifest = root / 'verification/sdk-header-manifest.json'
previous = json.loads(manifest.read_text())
assert all(headers.get(k) == v for k, v in previous.items()), 'Existing SDK headers changed'
manifest.write_text(json.dumps(headers, indent=2) + '\n')

files = []
for source in sorted((donor / 'src').rglob('*.c')):
    text = source.read_text()
    clean = re.sub(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"', '', text, flags=re.S)
    if re.search(r'\b(?:asm|__asm|__asm__)\b', clean): continue
    includes = re.findall(r'^\s*#include\s*[<"]([^">]+)', text, re.M)
    if not set(includes) <= {'types.h'}: continue
    files.append(source)

base_flags = ['-enum', 'int', '-lang', 'c99', '-char', 'signed', '-interworking',
              '-proc', 'arm946e', '-gccext,on', '-inline', 'on,noauto', '-gccinc',
              '-fp', 'soft', '-ir', 'vendor/sm64ds/include']
jobs = [(source, mode, opt) for source in files for mode in ['arm', 'thumb']
        for opt in ['-O4,p', '-O4,s', '-O2']]

def compile_source(job):
    source, mode, opt = job
    source_tag = hashlib.sha256(str(source.relative_to(donor)).encode()).hexdigest()[:12]
    name = source.stem + '.' + source_tag + '.' + mode + '.' + opt[1:].replace(',', '_') + '.o'
    flags = [opt, *base_flags, *(['-thumb'] if mode == 'thumb' else [])]
    obj = out / name
    if obj.exists(): obj.unlink()
    result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *flags,
                             '-c', str(source), '-o', str(obj)], cwd=root,
                            capture_output=True, timeout=30)
    return name, dict(source=str(source.relative_to(donor)), flags=flags,
                      returncode=result.returncode,
                      error=(result.stdout + result.stderr).decode(errors='replace')[:1500])

with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    results = list(pool.map(compile_source, jobs))
objects = {name: {k: v for k, v in result.items() if k in ['source', 'flags']}
           for name, result in results if result['returncode'] == 0}
config = dict(object_directory=str(out.relative_to(root)), complete_translation_unit=True,
              include_rewrites={'types.h': '../../vendor/sm64ds/include/types.h'}, objects=objects)
(out / 'config.json').write_text(json.dumps(config, indent=2) + '\n')
(out / 'build-results.json').write_text(json.dumps(dict(results), indent=2) + '\n')
print(json.dumps(dict(pure_c_sources=len(files), variants=len(jobs), compiled=len(objects))))
