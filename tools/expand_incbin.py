#!/usr/bin/env python3
"""Copies an assembly source with each `.incbin "file"[, offset[, length]]` line expanded into `.byte` lines.

mwasmarm reads .incbin input as text and turns a lone 0x0a byte into 0x0d, so binary data can't be included
directly. The files named here come from the user's own extracted ROM; the expanded copy lives under build/ only.
Paths are relative to the working directory (the repository root when run from ninja).
"""
import argparse
import re
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("src", type=Path)
parser.add_argument("out", type=Path)
args = parser.parse_args()

INCBIN = re.compile(r'^(\s*)\.incbin\s+"([^"]+)"\s*(?:,\s*([^,;\s]+)\s*(?:,\s*([^,;\s]+))?)?\s*(;.*)?$')

out = []
for line in args.src.read_text().splitlines():
    m = INCBIN.match(line)
    if not m:
        out.append(line)
        continue
    indent, path, offset, length = m.group(1), m.group(2), m.group(3), m.group(4)
    data = Path(path).read_bytes()
    start = int(offset, 0) if offset else 0
    end = start + int(length, 0) if length else len(data)
    if end > len(data):
        raise SystemExit(f"{args.src}: {path} is shorter than {end:#x} bytes")
    chunk = data[start:end]
    for i in range(0, len(chunk), 16):
        out.append(indent + ".byte " + ", ".join(f"{b:#04x}" for b in chunk[i:i + 16]))
args.out.parent.mkdir(parents=True, exist_ok=True)
args.out.write_text("\n".join(out) + "\n")
