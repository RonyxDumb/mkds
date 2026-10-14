"""Compile public SDK C variants; the separate importer must prove every function byte."""
from pathlib import Path
import argparse
import concurrent.futures
import json
import os
import re
import subprocess

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('donor', type=Path)
parser.add_argument('--inline', dest='inline_mode', choices=['on,noauto', 'on,auto'], default='on,noauto')
args = parser.parse_args()
donor = args.donor.resolve()
out = root / 'build' / ('sdk-variants-' + args.inline_mode.replace(',', '-'))
out.mkdir(parents=True, exist_ok=True)
processed = out / 'processed'; processed.mkdir(exist_ok=True)
base_flags = ['-enum', 'int', '-lang', 'c99', '-char', 'signed', '-interworking',
              '-proc', 'arm946e', '-gccext,on', '-inline', args.inline_mode, '-gccinc', '-fp', 'soft']
for directory in ['include-mw', 'arm9/lib/MSL_C/include', 'arm9/lib/libnns/include', 'arm9/lib/NitroSDK/include']:
    base_flags += ['-ir', 'vendor/pokediamond/' + directory]
sources = [p for folder in ['arm9/lib/NitroSDK/src', 'arm9/lib/libnns/src', 'arm9/lib/syscall']
           for p in (donor / folder).rglob('*.c')]
assert len({p.name for p in sources}) == len(sources), 'Ambiguous donor filenames'
for source in sources:
    # This unrelated game header is not needed by the accepted C functions.
    # Any use of declarations lost here fails compilation instead of being stubbed.
    text = re.sub(r'^\s*#include\s*"main.h"[^\n]*\n', '', source.read_text(), flags=re.M)
    (processed / source.name).write_text(text)

def compile_source(job):
    source, opt = job; name = source.stem + '.' + opt[1:].replace(',', '_') + '.o'
    flags = [opt, *base_flags]; obj = out / name
    if obj.exists(): obj.unlink()
    result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *flags,
                             '-c', str(processed / source.name), '-o', str(obj)],
                            cwd=root, capture_output=True, timeout=30)
    return name, dict(source=str(source.relative_to(donor)), flags=flags, returncode=result.returncode,
                      error=(result.stdout + result.stderr).decode(errors='replace')[:1500])

jobs = [(source, opt) for source in sources for opt in ['-O4,p', '-O4,s', '-O2']]
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    results = list(pool.map(compile_source, jobs))
objects = {name: {k: v for k, v in result.items() if k in ['source', 'flags']}
           for name, result in results if result['returncode'] == 0}
config = dict(object_directory=str(out.relative_to(root)), objects=objects,
              drop_includes=['main.h'], complete_translation_unit=True)
(out / 'config.json').write_text(json.dumps(config, indent=2) + '\n')
(out / 'build-results.json').write_text(json.dumps(dict(results), indent=2) + '\n')
print(json.dumps(dict(sources=len(sources), variants=len(jobs), compiled=len(objects))))
