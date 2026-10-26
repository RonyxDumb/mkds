#!/usr/bin/env python3
"""Lists calls in src/ and libs/ to functions with no declaration in scope.

The build compiles with -w off, and the compiler then accepts a call to an undeclared function without a word
(an implicit int declaration). That hides a missing #include whenever a declaration moves to its own file's
header. `ninja protos` compiles each src/ and libs/ file once more with -requireprotos and writes what it finds to
build/<ver>/protos/<path>.txt; ninja reruns a file only when it or a header it includes changes. This runs that
target and prints the results.

  check_protos.py                          run `ninja protos` and list every call without a declaration
  check_protos.py --one OUT DEP -- CMD...  (used by the build) run one compile, write its findings to OUT and
                                           its ninja depfile to DEP
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def one(out, dep, cmd):
    run = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    log = run.stdout + run.stderr
    lines = []
    for m in re.finditer(r"^(\S+?):(\d+): function has no prototype", log, re.M):
        line = (ROOT / m[1].replace("\\", "/")).read_text().split("\n")[int(m[2]) - 1].strip()
        lines.append(f"{m[1]}:{m[2]}: no declaration in scope: {line}\n")
    if run.returncode and not lines:
        # Some other error: fail the edge so it isn't recorded as clean.
        sys.stderr.write(log)
        sys.exit(run.returncode)
    if run.returncode:
        # A failed compile writes no depfile; compile once more without -requireprotos to get one, so a fix in a
        # header still reruns this file.
        plain = [a for a in cmd if a != "-requireprotos"]
        plain[plain.index("-w") + 1] = "off"
        subprocess.run(plain, cwd=ROOT, capture_output=True, check=True)
    subprocess.run([sys.executable, str(ROOT / "tools/transform_dep.py"), dep, dep], cwd=ROOT, check=True)
    Path(out).write_text("".join(lines))


def main():
    if sys.argv[1:2] == ["--one"]:
        return one(sys.argv[2], sys.argv[3], sys.argv[5:])
    build = subprocess.run(["ninja", "protos"], cwd=ROOT, capture_output=True, text=True)
    if build.returncode:
        sys.exit(build.stdout + build.stderr)
    query = subprocess.run(["ninja", "-t", "query", "protos"], cwd=ROOT, capture_output=True, text=True).stdout
    found = 0
    for path in re.findall(r"^\s{4}(\S+\.txt)$", query, re.M):
        text = (ROOT / path).read_text()
        sys.stdout.write(text)
        found += text.count("\n")
    print(f"{found} call(s) without a declaration", file=sys.stderr)
    sys.exit(1 if found else 0)


if __name__ == "__main__":
    main()
