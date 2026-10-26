#!/usr/bin/env python3
"""Tries to link units from source, keeping every one that leaves the ROM matching.

Each unit first gets data_ranges.py --write (all units at once, on every core) and link_check.py (function order,
every data section has a range). The units that pass are then marked complete together and built once: `ninja`
(ROM SHA-1), sync_linked_symbols.py --write, `ninja check`. If that fails, the config files go back to their state
before the batch and each half is tried on its own, down to single units. So one build links the whole batch when it
matches, and a failing unit costs a few builds instead of every unit costing one. Run `ninja report` first so the
objects exist.

  try_link.py [units...]      (default: every fully matching game unit that isn't complete yet)
  try_link.py --libs          (every fully matching library unit)
"""
import json
import os
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
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


def snapshot(files):
    return {f: f.read_bytes() for f in files}


def restore(snap):
    # Rewrite only the files that changed, so ninja doesn't see the others as new.
    for f, data in snap.items():
        if f.read_bytes() != data:
            f.write_bytes(data)


def data_ranges(unit):
    r = run("python3", "tools/data_ranges.py", unit, "--write")
    if not r.returncode:
        return None
    reason = (r.stdout + r.stderr).strip().splitlines()
    return "data: " + next((l for l in reason if "conflict" in l or "not" in l), reason[-1])


def prepare(batch, base):
    """Data ranges (on every core) and one link_check for the batch; returns the ready units and the others with
    the reason. A failed data_ranges writes nothing; ranges of units that then fail link_check are taken out again."""
    with ThreadPoolExecutor(os.cpu_count()) as pool:
        whys = dict(zip(batch, pool.map(data_ranges, batch)))
    bad = [(u, w) for u, w in whys.items() if w]
    ready = [u for u in batch if not whys[u]]
    if not ready:
        return ready, bad
    lines = run("python3", "tools/link_check.py", *ready).stdout.splitlines()
    failed = []
    for unit in ready:
        at = next((i for i, l in enumerate(lines) if l.split()[1:2] == [unit]), None)
        if at is None or not lines[at].startswith("READY"):
            detail = ([lines[at].split()[0]] + [l.strip() for l in lines[at + 1:at + 4] if l.startswith(" ")]
                      if at is not None else ["not checked"])
            failed.append((unit, "link_check: " + " ".join(detail)[:300]))
    if failed:
        bad += failed
        ready = [u for u in ready if u not in dict(failed)]
        restore(base)
        with ThreadPoolExecutor(os.cpu_count()) as pool:
            list(pool.map(data_ranges, ready))
    return ready, bad


def build(units):
    """Marks the units complete and builds; returns None when the ROM and symbols still match."""
    run("python3", "tools/mark_complete.py", *units)
    r = run("ninja")
    if r.returncode:
        msg = [l for l in (r.stdout + r.stderr).splitlines() if "Error" in l or "FAILED" in l or "mwldarm.exe:" in l]
        return "build: " + " | ".join(msg[-3:])[:300]
    run("python3", "tools/sync_linked_symbols.py", "--write")
    # The sync only renames config symbols to the names the linked binary already has, so relinking for
    # `ninja check` would build the same binary: check the symbols against it directly. The final `ninja check`
    # in main() relinks once for everything that was kept.
    target = str((BUILD / "symbols.ok").relative_to(ROOT))
    cmd = run("ninja", "-t", "commands", target).stdout.strip().splitlines()[-1]
    r = subprocess.run(cmd.split(" && touch ")[0], shell=True, cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        msg = [l for l in (r.stdout + r.stderr).splitlines() if "ERROR" in l]
        return "check: " + " | ".join(msg[:2])[:300]
    return None


def main():
    args = [a for a in sys.argv[1:] if a != "--libs"]
    units = args or candidates(("libs/",) if "--libs" in sys.argv else ("src/",))
    files = [p for p in CFG.rglob("*.txt")]
    ok, bad = [], []
    base = snapshot(files)

    def attempt(batch):
        nonlocal base
        restore(base)
        ready, failed = prepare(batch, base)
        bad.extend(f for f in failed if f[0] not in dict(bad))
        if not ready:
            return
        why = build(ready)
        if not why:
            base = snapshot(files)
            ok.extend(ready)
            for unit in ready:
                print("LINKED", unit, flush=True)
            return
        restore(base)
        if len(ready) == 1:
            bad.append((ready[0], why))
            return
        half = len(ready) // 2
        attempt(ready[:half])
        attempt(ready[half:])

    final = None
    if units:
        attempt(units)
        restore(base)
        # Rebuild from the config that was kept and check it in full.
        r = run("ninja")
        if not r.returncode:
            r = run("ninja", "check")
        final = r if r.returncode else None
    for unit, why in bad:
        print("FAILED", unit, "--", why)
    print(f"{len(ok)} linked, {len(bad)} not")
    if final:
        sys.exit("final `ninja check` failed:\n" + (final.stdout + final.stderr)[-2000:])


if __name__ == "__main__":
    main()
