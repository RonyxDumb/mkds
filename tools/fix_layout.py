#!/usr/bin/env python3
"""Searches include orders for one that gives a unit's data its original layout.

In C++ code, a singleton accessor's objects (guard, destructor-chain node, instance) are numbered and placed where its
header is first parsed, and mwcc sorts a section's objects by size with an order among equal sizes that
depends on the declaration order (see docs/decompiling.md). So which singleton header comes first changes the
layout. This tool tries putting the headers of the singletons the unit uses at the top of the file (one, two,
then three of them, in every order), recompiles, and asks data_ranges.py whether every data section now lands
consistently. The first order that works is kept; with --dry-run nothing is kept.

  fix_layout.py src/Main/Some/Unit.c [--max 3] [--dry-run]
"""
import argparse
import itertools
import re
import subprocess
import sys
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent


def run(*cmd):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)


def conflicts(src):
    out = run("python3", "tools/data_ranges.py", src).stdout
    # Only layout problems count; sections no matching code references ("not placed") are another matter.
    return sum(1 for ln in out.splitlines() if (ln.startswith("conflict") and "outside the original" not in ln)
               or "order differs" in ln)


def singleton_headers(src):
    obj = ROOT / f"build/{VERSION}" / Path(src).with_suffix(".o")
    nm = run("arm-none-eabi-nm", str(obj)).stdout
    classes = re.findall(r"_ZZN\d+(\w+?)3GetEvE8instance", nm)
    headers = []
    for c in dict.fromkeys(classes):
        hit = run("grep", "-rlE", rf"static\s+{c}\s*&\s*Get\s*\(", "include").stdout.split()
        if hit:
            headers.append(hit[0][len("include/"):])
    return headers


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("--max", type=int, default=3)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    src = args.source
    path = ROOT / src
    original = path.read_text()
    obj = str(Path(f"build/{VERSION}") / Path(src).with_suffix(".o"))
    base = conflicts(src)
    print(f"{src}: {base} problem(s) now")
    if base == 0:
        return
    headers = singleton_headers(src)
    print("singleton headers:", ", ".join(headers))
    try:
        for k in range(1, min(args.max, len(headers)) + 1):
            for combo in itertools.permutations(headers, k):
                prefix = "".join(f'#include "{h}"\n' for h in combo)
                path.write_text(prefix + original)
                if run("ninja", obj).returncode:
                    continue
                n = conflicts(src)
                if n == 0:
                    print("works: " + " then ".join(combo) + " first")
                    if args.dry_run:
                        path.write_text(original)
                    else:
                        run("ninja", obj)
                    return
        print("no include order found")
        path.write_text(original)
        run("ninja", obj)
    except BaseException:
        path.write_text(original)
        raise


if __name__ == "__main__":
    main()
