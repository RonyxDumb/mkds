#!/usr/bin/env python3
"""Apply the reviewed local adapter patch to exactly the tested REA revision."""
import argparse
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
PIN = 'fffb0741936067530d1ce9777461cd53e87398c2'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path, nargs='?', default=ROOT / 'tools/rea-source')
    args = parser.parse_args()
    checkout = args.checkout.resolve(strict=True)
    revision = subprocess.check_output(['git', '-C', str(checkout), 'rev-parse', 'HEAD'], text=True).strip()
    if revision != PIN:
        raise SystemExit('REA revision differs from tested pin: ' + revision)
    patch = ROOT / 'scripts/rea/pid-namespace.patch'
    command = ['git', '-C', str(checkout), 'apply']
    if subprocess.run([*command, '--reverse', '--check', str(patch)], capture_output=True).returncode == 0:
        print('Patch already applied')
        return
    upgrade = ROOT / 'scripts/rea/upgrade-ds.patch'
    if subprocess.run([*command, '--check', str(upgrade)], capture_output=True).returncode == 0:
        subprocess.run([*command, str(upgrade)], check=True)
        verified = subprocess.run([*command, '--reverse', '--check', str(patch)], capture_output=True)
        if verified.returncode != 0:
            subprocess.run([*command, '--reverse', str(upgrade)], check=True)
            raise SystemExit('Upgrade did not produce the complete tested patch; upgrade reverted')
        print('Upgraded the earlier PID fix; rebuild REA with npm run build:cached')
        return
    subprocess.run([*command, '--check', str(patch)], check=True)
    subprocess.run([*command, str(patch)], check=True)
    print('Applied; run npm ci and npm run build:cached in the REA checkout')


if __name__ == '__main__':
    main()
