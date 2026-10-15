"""Compile pure-C donor candidates in the other instruction set for fresh checks.

Input manifests must be produced by prepare_mkds_candidates.py and
prepare_alternate_donor_candidates.py. This only prepares objects; acceptance
requires verify_sdk_sources.py, including complete relocation resolution.
"""
from pathlib import Path
import concurrent.futures
import hashlib
import json
import os
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]


def main():
    donor = Path(sys.argv[1]).resolve()
    commit = subprocess.check_output(
        ['git', '-C', str(donor), 'rev-parse', 'HEAD'], text=True).strip()
    assert commit == 'c6e18fa4b346643b74c402b605a84b43cba16c01'
    assert not subprocess.check_output(
        ['git', '-C', str(donor), 'status', '--porcelain'], text=True).strip()
    out = ROOT / 'build/mkds-opposite-isa'
    out.mkdir(parents=True, exist_ok=True)
    jobs = {}
    for argument in sys.argv[2:]:
        config = json.loads(Path(argument).read_text())
        assert config['complete_translation_unit'] is True
        for value in config['objects'].values():
            flags = list(value['flags'])
            if '-thumb' in flags:
                flags.remove('-thumb')
            else:
                flags.append('-thumb')
            key = value['source'] + '\0' + '\0'.join(flags)
            name = hashlib.sha256(key.encode()).hexdigest()[:24] + '.o'
            jobs[name] = dict(source=value['source'], flags=flags)

    def compile_one(item):
        name, value = item
        obj = out / name
        obj.unlink(missing_ok=True)
        result = subprocess.run(
            [os.environ['WIBO'], os.environ['MWCCARM'], *value['flags'],
             '-c', str(donor / value['source']), '-o', str(obj)],
            capture_output=True, timeout=30)
        return name, value, result.returncode

    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        results = list(pool.map(compile_one, jobs.items()))
    objects = {name: value for name, value, code in results if code == 0}
    config = dict(object_directory=str(out.relative_to(ROOT)), objects=objects,
                  complete_translation_unit=True, target_modules=['arm9'])
    (out / 'config.json').write_text(json.dumps(config, indent=2) + '\n')
    summary = dict(candidate_sources=len(jobs), compiled_objects=len(objects),
                   donor_commit=commit, full_rom_link_verified=False)
    (out / 'build-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary), flush=True)


if __name__ == '__main__':
    main()
