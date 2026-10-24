#!/usr/bin/env python3
"""Tries to link units from source, one at a time, keeping each one that leaves the ROM matching.

For each unit: data_ranges.py --write, link_check.py (function order, every data section has a range), mark
complete, `ninja` (ROM SHA-1), then sync_linked_symbols.py --write and `ninja check`. On any failure the config files
are restored to their state before that unit. Run `ninja report` first so the objects exist.

  try_link.py [units...]      (default: every fully matching game unit that isn't complete yet)
  try_link.py --libs          (every fully matching library unit)
"""
import json
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import BUILD, CFG, delinks_files, parse_units  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent


def run(*cmd):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)


def candidates(prefixes=("src/",)):
    done = {u["file"] for _, p in delinks_files() for u in parse_units(p) if u["complete"]}
    report = json.loads((BUILD / "report.json").read_text())
    out = []
    for unit in report["units"]:
        m = unit.get("measures", {})
        if not unit["name"].startswith(prefixes) or not m.get("total_functions"):
            continue
        if m["total_functions"] != m.get("matched_functions"):
            continue
        for ext in (".cpp", ".c"):
            src = unit["name"] + ext
            if (ROOT / src).exists() and src not in done:
                out.append(src)
    return out


def link_one(unit, files, backup):
    """Links one unit; returns None on success or the reason it failed (the config is then restored)."""
    for f in files:
        dst = backup / f.relative_to(CFG)
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(f, dst)

    def restore(rebuild=False):
        for f in files:
            shutil.copy(backup / f.relative_to(CFG), f)
        if rebuild:
            run("ninja")

    r = run("python3", "tools/data_ranges.py", unit, "--write")
    if r.returncode:
        reason = (r.stdout + r.stderr).strip().splitlines()
        restore()
        return "data: " + next((l for l in reason if "conflict" in l or "not" in l), reason[-1])
    r = run("python3", "tools/link_check.py", unit)
    lines = r.stdout.splitlines()
    at = next((i for i, l in enumerate(lines) if l.split()[1:2] == [unit]), None)
    if at is None or not lines[at].startswith("READY"):
        detail = ([lines[at].split()[0]] + [l.strip() for l in lines[at + 1:at + 4] if l.startswith(" ")]
                  if at is not None else ["not checked"])
        restore()
        return "link_check: " + " ".join(detail)[:300]
    run("python3", "tools/mark_complete.py", unit)
    r = run("ninja")
    if r.returncode:
        msg = [l for l in (r.stdout + r.stderr).splitlines() if "Error" in l or "FAILED" in l or "mwldarm.exe:" in l]
        restore(rebuild=True)
        return "build: " + " | ".join(msg[-3:])[:300]
    run("python3", "tools/sync_linked_symbols.py", "--write")
    r = run("ninja", "check")
    if r.returncode:
        msg = [l for l in (r.stdout + r.stderr).splitlines() if "ERROR" in l]
        restore(rebuild=True)
        return "check: " + " | ".join(msg[:2])[:300]
    return None


def main():
    args = [a for a in sys.argv[1:] if a != "--libs"]
    units = args or candidates(("libs/",) if "--libs" in sys.argv else ("src/",))
    files = [p for p in CFG.rglob("*.txt")]
    ok, bad = [], []
    for unit in units:
        with tempfile.TemporaryDirectory(prefix="try_link") as tmp:
            why = link_one(unit, files, Path(tmp))
        if why:
            bad.append((unit, why))
        else:
            ok.append(unit)
            print("LINKED", unit, flush=True)
    for unit, why in bad:
        print("FAILED", unit, "--", why)
    print(f"{len(ok)} linked, {len(bad)} not")


if __name__ == "__main__":
    main()
