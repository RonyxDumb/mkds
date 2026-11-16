#!/usr/bin/env python3
"""Renames or moves source units: the source file, its header, every include of the header, the unit's entry in each
version's delinks.txt, per-path settings in tools/project.py and the paths written in the docs.

  rename_unit.py <old source> <new source> [<old source> <new source> ...] [--write]

Sources are repository paths (`src/00/code_0218d818.c`, `libs/NitroSDK/os/src/code_0200eddc.c`). A unit's header is
`include/<path below src/>.h` for game code and `libs/<name>/include/<path below src/>.h` for library code. The
extension stays as it is (.c, .cpp or .s). Dry run unless --write; run `python3 tools/configure.py` afterwards so
build.ninja names the new paths.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def header_of(src: Path) -> Path:
    parts = src.parts
    if parts[0] == "src":
        return Path("include", *parts[1:]).with_suffix(".h")
    if parts[0] == "libs" and "src" in parts:
        i = parts.index("src")
        return Path(*parts[:i], "include", *parts[i + 1:]).with_suffix(".h")
    raise SystemExit(f"{src}: not under src/ or libs/<name>/src/")


def include_name(header: Path) -> str:
    """The path a header is included by: below include/ (game) or below libs/<name>/include/ (library)."""
    parts = header.parts
    i = parts.index("include")
    return Path(*parts[i + 1:]).as_posix()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("paths", nargs="+")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    if len(a.paths) % 2:
        raise SystemExit("give pairs of <old> <new>")
    pairs = [(Path(o), Path(n)) for o, n in zip(a.paths[::2], a.paths[1::2])]
    for old, new in pairs:
        if old.suffix != new.suffix:
            raise SystemExit(f"{old} -> {new}: the extension must stay the same")
        if not (ROOT / old).exists():
            raise SystemExit(f"{old} does not exist")
        if (ROOT / new).exists():
            raise SystemExit(f"{new} exists already")

    text_edits = {}  # path -> new text

    def edit(path: Path, fn):
        p = ROOT / path
        t = text_edits.get(path, p.read_text())
        u = fn(t)
        if u != t:
            text_edits[path] = u

    moves = []
    for old, new in pairs:
        moves.append((old, new))
        oh, nh = header_of(old), header_of(new)
        if (ROOT / oh).exists():
            moves.append((oh, nh))
            oi, ni = include_name(oh), include_name(nh)
            if oi != ni:
                inc = re.compile(r'(#include\s+")' + re.escape(oi) + '"')
                for p in [p for d in ("src", "include", "libs") for p in (ROOT / d).rglob("*")
                          if p.suffix in (".c", ".cpp", ".h", ".hpp")]:
                    edit(p.relative_to(ROOT), lambda t: inc.sub(lambda m: m.group(1) + ni + '"', t))
        # delinks entries, per-path settings and docs: the exact source path
        exact = re.compile(r"(?<![\w/])" + re.escape(old.as_posix()) + r"(?![\w.])")
        for p in list((ROOT / "config").rglob("delinks.txt")) + [ROOT / "tools/project.py"] + \
                 list((ROOT / "docs").rglob("*.md")) + [ROOT / f for f in ("README.md", "CONTRIBUTING.md", "INSTALL.md")]:
            if p.exists():
                edit(p.relative_to(ROOT), lambda t: exact.sub(new.as_posix(), t))
        if (ROOT / oh).exists():
            exact_h = re.compile(r"(?<![\w/])" + re.escape(oh.as_posix()) + r"(?![\w.])")
            for p in list((ROOT / "docs").rglob("*.md")) + [ROOT / "CONTRIBUTING.md"]:
                edit(p.relative_to(ROOT), lambda t: exact_h.sub(nh.as_posix(), t))

    for old, new in moves:
        print(f"move {old} -> {new}")
    for p in sorted(text_edits):
        print(f"edit {p}")
    if not a.write:
        return
    for old, new in moves:
        (ROOT / new).parent.mkdir(parents=True, exist_ok=True)
        r = subprocess.run(["git", "mv", old.as_posix(), new.as_posix()], cwd=ROOT, capture_output=True, text=True)
        if r.returncode:
            (ROOT / old).rename(ROOT / new)
    moved = dict(moves)
    for p, t in text_edits.items():
        (ROOT / moved.get(p, p)).write_text(t)


if __name__ == "__main__":
    main()
