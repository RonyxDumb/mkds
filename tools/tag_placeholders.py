#!/usr/bin/env python3
"""Tags a version's own placeholder names with the version: func_<addr> -> func_<ver>_<addr> (data and overlay names
likewise) in every config/<ver>/arm9/**/symbols.txt.

Placeholders carry the reference version's addresses (REFERENCE_VERSION in tools/project.py). Another
version's dsd init writes plain placeholders with its own addresses, which would collide with the reference names
that shared source brings in (sync_symbols.py refuses a name that already belongs to another symbol). configure.py
runs this after dsd init for every version but the reference; run it by hand on a config generated before.
Names that aren't placeholders, and placeholders already tagged, are left alone. Dry run unless --write.

  tag_placeholders.py <ver> [--write]
"""
import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import PLACEHOLDER, REFERENCE_VERSION, ROOT, VERSIONS  # noqa: E402  (tools/project.py)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("version", choices=VERSIONS)
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    if a.version == REFERENCE_VERSION:
        sys.exit(f"{a.version} is the reference version: its placeholders stay untagged")
    total = 0
    for path in sorted((ROOT / "config" / a.version / "arm9").rglob("symbols.txt")):
        lines = path.read_text().splitlines()
        changed = 0
        for i, line in enumerate(lines):
            name, sep, rest = line.partition(" ")
            m = PLACEHOLDER.match(name)
            if not m or m.group(2):
                continue
            ov = f"{m.group(3)}_" if m.group(3) else ""
            lines[i] = f"{m.group(1)}_{a.version}_{ov}{m.group(4)}{sep}{rest}"
            changed += 1
        if changed and a.write:
            path.write_text("\n".join(lines) + "\n")
        total += changed
        print(f"{path.relative_to(ROOT)}: {changed} placeholder(s)")
    print(f"{total} placeholder(s) tagged" + ("" if a.write else " (dry run; pass --write to apply)"))


if __name__ == "__main__":
    main()
