#!/usr/bin/env python3
"""Launch melonDS and observe both CPUs within the same execution environment."""
import argparse
import json
from pathlib import Path
import subprocess
import time

from observe_gdb import observe

ROOT = Path(__file__).resolve().parents[1]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path)
    parser.add_argument('--output', type=Path, default=ROOT / 'build/gdb-observation')
    args = parser.parse_args()
    rom = args.rom.resolve(strict=True)
    args.output.mkdir(parents=True, exist_ok=True)
    # Popen owns this child handle; cleanup never guesses ownership from a PID.
    with (args.output / 'emulator.log').open('w') as log:
        process = subprocess.Popen([str(ROOT / 'tools/melonds-headless'),
                                    str(rom), '36000', '--gdb'],
                                   stdout=log, stderr=log, cwd=ROOT)
        try:
            for cpu, port in [('arm9', 3333), ('arm7', 3334)]:
                for attempt in range(50):
                    try:
                        result = observe(cpu, port)
                        break
                    except ConnectionRefusedError:
                        if process.poll() is not None:
                            raise RuntimeError('Emulator exited before GDB became available')
                        time.sleep(0.1)
                else:
                    raise RuntimeError('GDB did not open on port ' + str(port))
                (args.output / (cpu + '.json')).write_text(json.dumps(result, indent=2) + '\n')
                print(cpu, hex(result['pc']), result['detach_reply'], flush=True)
        finally:
            if process.poll() is None:
                process.terminate()
                try:
                    process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()


if __name__ == '__main__':
    main()
