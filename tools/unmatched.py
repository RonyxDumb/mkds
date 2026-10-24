#!/usr/bin/env python3
"""Lists functions in decompiled units (src/ and libs/) that don't match yet, from build/<ver>/report.json (run
`ninja report` first). The `// non-matching:` comments in the source say what still differs."""
import json
import sys
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)

report = json.loads(Path(sys.argv[1] if len(sys.argv) > 1 else f"build/{VERSION}/report.json").read_text())
for unit in report["units"]:
    if not unit["name"].startswith(("src/", "libs/")):
        continue
    for fn in unit.get("functions", []):
        pct = fn.get("fuzzy_match_percent", 0)
        if pct < 100:
            name = fn.get("metadata", {}).get("demangled_name") or fn["name"]
            print(f"{pct:6.2f}%  {unit['name']:44} {name}")
