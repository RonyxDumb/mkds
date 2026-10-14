"""Compile Nitro library candidates; assembly functions are excluded by the byte verifier."""
from pathlib import Path
import argparse
import concurrent.futures
import hashlib
import json
import os
import re
import shutil
import subprocess

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('sdk', type=Path)
parser.add_argument('system', type=Path)
parser.add_argument('--component', choices=['sdk', 'system'], required=True)
args = parser.parse_args()
sdk, system = args.sdk.resolve(), args.system.resolve()
for name, donor in [('nitrosdk', sdk), ('nitrosystem', system)]:
    dest = root / 'vendor' / name
    for directory in ['include', 'libraries']:
        for source in (donor / directory).rglob('*'):
            if source.is_file() and source.suffix in ['.h', '.inc', '.def']:
                target = dest / source.relative_to(donor)
                target.parent.mkdir(parents=True, exist_ok=True)
                text = source.read_text()
                if name == 'nitrosdk' and source.relative_to(donor).as_posix() == 'include/nitro/math/math.h':
                    text, replaced = re.subn(r'SDK_INLINE u32 MATH_CountLeadingZerosInline\s*\([^)]*\)\s*\{.*?return x;\s*\}',
                                           'extern u32 MATH_CountLeadingZerosInline(u32 x);', text, flags=re.S)
                    assert replaced == 1, 'Unexpected inline CLZ definition'
                expected = text.encode()
                if target.exists(): assert target.read_bytes() == expected, 'Changed pinned header'
                else: target.write_bytes(expected)
constant_header = root / 'vendor/nitrosdk/include/nitro/fx/fx_const.h'
if not constant_header.exists():
    subprocess.run(['python', str(sdk / 'gen/nitro/fx/gen_fx_const.py'),
                    str(sdk / 'gen/nitro/fx/fx_const.csv'), str(constant_header)], check=True)
headers = {str(p.relative_to(root)): hashlib.sha256(p.read_text().encode()).hexdigest()
           for p in sorted((root / 'vendor').rglob('*'))
           if p.is_file() and p.suffix in ['.h', '.inc', '.def']}
manifest = root / 'verification/sdk-header-manifest.json'
previous = json.loads(manifest.read_text())
assert all(headers.get(k) == v for k, v in previous.items()), 'Existing SDK headers changed'
manifest.write_text(json.dumps(headers, indent=2) + '\n')
donor = sdk if args.component == 'sdk' else system
out = root / 'build' / ('nitro-' + args.component + '-candidates'); out.mkdir(exist_ok=True)
flags = ['-enum', 'int', '-lang', 'c99', '-char', 'signed', '-interworking', '-proc', 'arm946e',
         '-gccext,on', '-inline', 'on,noauto', '-gccinc', '-fp', 'soft',
         '-DSDK_CW_FORCE_EXPORT_SUPPORT', '-DSDK_TS', '-DSDK_4M', '-DSDK_ARM9',
         '-DSDK_CW', '-DSDK_FINALROM', '-DSDK_CODE_ARM', '-DNNS_FINALROM']
for directory in ['vendor/nitrosystem/include', 'vendor/nitrosdk/include',
                  'vendor/nitro-stdinc',
                  'vendor/pokediamond/include-mw', 'vendor/pokediamond/arm9/lib/MSL_C/include',
                  'vendor/nitrosystem/libraries', 'vendor/nitrosdk/libraries']:
    flags += ['-ir', directory]
sources = [p for p in (donor / 'libraries').rglob('*.c') if 'ARM7' not in p.parts]

def compile_source(job):
    source, opt = job
    tag = hashlib.sha256(str(source.relative_to(donor)).encode()).hexdigest()[:12]
    name = source.stem + '.' + tag + '.' + opt[1:].replace(',', '_') + '.o'
    current = [opt, *flags]; obj = out / name
    if obj.exists(): obj.unlink()
    try:
        result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *current,
                                 '-c', str(source), '-o', str(obj)], cwd=root,
                                capture_output=True, timeout=30)
        status = result.returncode
        error = (result.stdout + result.stderr).decode(errors='replace')[:1500]
    except subprocess.TimeoutExpired:
        status, error = 124, 'Compiler timed out'
    return name, dict(source=str(source.relative_to(donor)), flags=current, returncode=status, error=error)

jobs = [(p, opt) for p in sources for opt in ['-O4,p', '-O4,s', '-O2']]
results = []
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    for i, result in enumerate(pool.map(compile_source, jobs), 1):
        results.append(result)
        if i % 100 == 0: print('Compiled variants', i, flush=True)
objects = {name: {k: v for k, v in result.items() if k in ['source', 'flags']}
           for name, result in results if result['returncode'] == 0}
config = dict(object_directory=str(out.relative_to(root)), objects=objects)
(out / 'config.json').write_text(json.dumps(config, indent=2) + '\n')
(out / 'build-results.json').write_text(json.dumps(dict(results), indent=2) + '\n')
print(json.dumps(dict(sources=len(sources), variants=len(jobs), compiled=len(objects))))
