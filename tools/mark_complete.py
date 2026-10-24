#!/usr/bin/env python3
"""Adds or removes the `complete` line of units in delinks.txt.

  mark_complete.py src/Main/Some/Unit.c ...        (mark)
  mark_complete.py --undo src/Main/Some/Unit.c ... (unmark)
"""
import argparse
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)

CFG = Path(__file__).resolve().parent.parent / f"config/{VERSION}/arm9"

ap = argparse.ArgumentParser()
ap.add_argument("units", nargs="+")
ap.add_argument("--undo", action="store_true")
args = ap.parse_args()
todo = set(args.units)
for path in CFG.rglob("delinks.txt"):
    lines = path.read_text().splitlines(keepends=True)
    out = []
    i = 0
    changed = False
    while i < len(lines):
        line = lines[i]
        out.append(line)
        head = line.rstrip("\n")
        if head.endswith(":") and head[:-1] in todo:
            todo.discard(head[:-1])
            has = i + 1 < len(lines) and lines[i + 1].strip() == "complete"
            if args.undo and has:
                i += 1
                changed = True
            elif not args.undo and not has:
                out.append("    complete\n")
                changed = True
        i += 1
    if changed:
        path.write_text("".join(out))
for u in sorted(todo):
    print("not found:", u)
