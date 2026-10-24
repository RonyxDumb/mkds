#!/usr/bin/env python3
"""Lists calls in src/ to functions with no declaration in scope.

The build compiles with -w off, and the compiler then accepts a call to an undeclared function without a word
(an implicit int declaration). That hides a missing #include whenever a declaration moves to its own file's
header. This compiles each src/ object once more with -requireprotos into a scratch file and lists the result.
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    objs = re.findall(r"^build (build/\w+/src/[^:]*\.o)", (ROOT / "build.ninja").read_text(), re.M)
    found = 0
    with tempfile.TemporaryDirectory() as tmp:
        for obj in objs:
            cmd = subprocess.run(["ninja", "-t", "commands", obj], cwd=ROOT, capture_output=True, text=True)
            cmd = cmd.stdout.strip().split("\n")[-1]
            cmd = cmd.replace(" -w off ", " -w on -requireprotos ").replace(" -MD ", " ")
            cmd = re.sub(r" -o \S+", f" -o {tmp}/check.o", cmd)
            run = subprocess.run(cmd, shell=True, cwd=ROOT, capture_output=True, text=True)
            for m in re.finditer(r"^(\S+?):(\d+): function has no prototype", run.stdout + run.stderr, re.M):
                src = ROOT / m[1].replace("\\", "/")
                line = src.read_text().split("\n")[int(m[2]) - 1].strip()
                print(f"{m[1]}:{m[2]}: no declaration in scope: {line}")
                found += 1
    print(f"{found} call(s) without a declaration", file=sys.stderr)
    sys.exit(1 if found else 0)


if __name__ == "__main__":
    main()
