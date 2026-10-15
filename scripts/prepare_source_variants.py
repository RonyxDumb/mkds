"""Compile explicit SDK source hypotheses using an existing candidate manifest."""
from pathlib import Path
import concurrent.futures
import argparse
import json
import os
import subprocess
from sdk_source_variants import source_variant

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('donor', type=Path)
parser.add_argument('config', type=Path)
parser.add_argument('--output', type=Path, default=Path('build/source-variants'))
parser.add_argument('--transformation', action='append', choices=[
    'omit_simple_null_returns', 'unchecked_g3d_dict_accessors',
    'unchecked_g3d_dict_accessors_all_units'])
args = parser.parse_args()
donor = args.donor.resolve()
config = json.loads(args.config.read_text())
output = ROOT / args.output
output.mkdir(parents=True, exist_ok=True)
processed = output / 'sources'
transformations = args.transformation or ['omit_simple_null_returns']
for value in config['objects'].values():
    source = donor / value['source']
    dest = processed / value['source']
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(source_variant(source.read_text(), transformations))

def compile_one(item):
    name, value = item
    obj = output / name
    obj.unlink(missing_ok=True)
    result = subprocess.run([os.environ['WIBO'], os.environ['MWCCARM'], *value['flags'],
                             '-c', str(processed / value['source']), '-o', str(obj)],
                            cwd=ROOT, capture_output=True, timeout=30)
    return name, value, result.returncode

with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
    results = list(pool.map(compile_one, config['objects'].items()))
config['objects'] = {n: v for n, v, code in results if code == 0}
config.update(object_directory=str(output.relative_to(ROOT)), transformations=transformations,
              complete_translation_unit=True, allow_observed_call_targets=True)
(output / 'config.json').write_text(json.dumps(config, indent=2) + '\n')
print(json.dumps(dict(variants=len(results), compiled=len(config['objects']))))
