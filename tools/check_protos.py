#!/usr/bin/env python3
"""Lists calls in src/ to functions with no declaration in scope.

The build compiles with -w off, and the compiler then accepts a call to an undeclared function without a word
(an implicit int declaration). That hides a missing #include whenever a declaration moves to its own file's
header. This compiles each src/ object once more with -requireprotos into a scratch file and lists the result.
"""
import json
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def check(cmd, tmp, n):
    cmd = cmd.replace(" -w off ", " -w on -requireprotos ").replace(" -MD ", " ")
    cmd = re.sub(r" -o \S+", f" -o {tmp}/check{n}.o", cmd)
    run = subprocess.run(cmd, shell=True, cwd=ROOT, capture_output=True, text=True)
    return re.findall(r"^(\S+?):(\d+): function has no prototype", run.stdout + run.stderr, re.M)


def main():
    db = json.loads(subprocess.run(["ninja", "-t", "compdb"], cwd=ROOT, capture_output=True, text=True).stdout)
    cmds = [e["command"] for e in db if re.match(r"build/\w+/src/.*\.o$", e.get("output", ""))]
    found = 0
    with tempfile.TemporaryDirectory() as tmp, ThreadPoolExecutor(os.cpu_count()) as pool:
        for hits in pool.map(check, cmds, [tmp] * len(cmds), range(len(cmds))):
            for path, n in hits:
                line = (ROOT / path.replace("\\", "/")).read_text().split("\n")[int(n) - 1].strip()
                print(f"{path}:{n}: no declaration in scope: {line}")
                found += 1
    print(f"{found} call(s) without a declaration", file=sys.stderr)
    sys.exit(1 if found else 0)


if __name__ == "__main__":
    main()
