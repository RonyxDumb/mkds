#!/usr/bin/env python3
"""Copies an assembly source with each `.incbin "file"[, offset[, length]]` line expanded into `.byte` lines.

mwasmarm reads .incbin input as text and turns a lone 0x0a byte into 0x0d, so binary data can't be included
directly. The files named here come from the user's own extracted ROM; the expanded copy lives under build/ only.
Paths are relative to the working directory (the repository root when run from ninja).

Lines between `#ifdef version_<VER>` / `#ifndef version_<VER>`, `#else` and `#endif` are kept only for the version
given with --version (default: the configured one), so a version's branch only reads that version's ROM.
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import VERSION  # noqa: E402  (tools/project.py)

CONDITION = re.compile(r"^\s*#\s*(ifdef|ifndef|else|endif)\b\s*(\S*)")


def select_version(lines: list[str], ver: str) -> list[str]:
    """The lines of the active branches of #ifdef version_<ver> blocks (the directives themselves are dropped)."""
    out, stack = [], []  # stack of (branch active, block active when it opened)
    for line in lines:
        m = CONDITION.match(line)
        if not m:
            if all(active for active, _ in stack):
                out.append(line)
            continue
        kind, name = m.groups()
        if kind in ("ifdef", "ifndef"):
            stack.append(((name == f"version_{ver.upper()}") == (kind == "ifdef"), True))
        elif kind == "else":
            if not stack:
                raise SystemExit("#else without #ifdef")
            stack[-1] = (not stack[-1][0], True)
        else:
            if not stack:
                raise SystemExit("#endif without #ifdef")
            stack.pop()
    if stack:
        raise SystemExit("#ifdef without #endif")
    return out


INCBIN = re.compile(r'^(\s*)\.incbin\s+"([^"]+)"\s*(?:,\s*([^,;\s]+)\s*(?:,\s*([^,;\s]+))?)?\s*(;.*)?$')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("src", type=Path)
    parser.add_argument("out", type=Path)
    parser.add_argument("--version", default=VERSION)
    args = parser.parse_args()
    out = []
    for line in select_version(args.src.read_text().splitlines(), args.version):
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


if __name__ == "__main__":
    main()
