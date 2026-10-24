#!/usr/bin/env python3
"""Converts an mwcc -MD depfile (Windows paths, as seen through wibo/wine) to POSIX paths for ninja."""
import re
import sys
from pathlib import Path

src, dst = Path(sys.argv[1]), Path(sys.argv[2])
out = []
for line in src.read_text(errors="replace").splitlines():
    cont = line.rstrip().endswith(" \\")
    body = line.rstrip()[:-2] if cont else line.rstrip()
    body = re.sub(r"\b[A-Za-z]:\\", "/", body).replace("\\", "/")
    out.append(body + (" \\" if cont else ""))
dst.write_text("\n".join(out) + "\n")
