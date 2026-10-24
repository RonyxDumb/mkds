#!/usr/bin/env python3
"""Removes `// non-matching` notes (and their continuation lines) above functions that now match.

Reads build/<ver>/report.json; for every function at 100% in a src/ or libs/ unit, deletes the comment block
directly above its definition if that block starts with `// non-matching`. Run `ninja report` first.

  clean_notes.py [--since old_report.json] [--write]
"""
import json
import re
import sys
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
report = json.loads((ROOT / f"build/{VERSION}/report.json").read_text())
write = "--write" in sys.argv
since = None
if "--since" in sys.argv:  # only functions that were below 100% in this older report
    old = json.loads(Path(sys.argv[sys.argv.index("--since") + 1]).read_text())
    since = {(u["name"], f["name"]) for u in old["units"] for f in u.get("functions", [])
             if f.get("fuzzy_match_percent", 0) < 100}
total = 0
for unit in report["units"]:
    name = unit["name"]
    if not name.startswith(("src/", "libs/")):
        continue
    path = next((ROOT / (name + ext) for ext in (".cpp", ".c") if (ROOT / (name + ext)).exists()), None)
    if path is None:
        continue
    done = [f.get("metadata", {}).get("demangled_name") or f["name"] for f in unit.get("functions", [])
            if f.get("fuzzy_match_percent", 0) >= 100 and (since is None or (name, f["name"]) in since)]
    lines = path.read_text().split("\n")
    removed = 0
    for full in done:
        base = re.sub(r"\(.*", "", full).split("::")[-1]
        qual = re.sub(r"\(.*", "", full)
        for i, ln in enumerate(lines):
            if ln is None or not ln or ln[0].isspace() or not ln.rstrip().endswith("{"):
                continue
            head = ln.split("(")[0]
            if not (head.endswith(" " + qual) or head.endswith("::" + base) and qual.endswith(base) or head.endswith(" " + base)):
                continue
            j = i
            while j > 0 and lines[j - 1] is not None and lines[j - 1].startswith("//"):
                j -= 1
            if j < i and lines[j].startswith("// non-matching"):
                for k in range(j, i):
                    lines[k] = None
                removed += 1
            break
    if removed:
        total += removed
        print(f"{path.relative_to(ROOT)}: {removed}")
        if write:
            path.write_text("\n".join(l for l in lines if l is not None))
print(f"{total} notes" + ("" if write else " (dry run)"))
