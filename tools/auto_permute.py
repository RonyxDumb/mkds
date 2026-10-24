#!/usr/bin/env python3
"""Tries every order of each run of local declarations in a near-matching function.

For each function given (or every non-matching function of the unit), finds runs of 2-6 consecutive declaration
lines in its body (`T name;` or `T name = ...;`, one per line), and probes every order of each run, keeping the
best, one run after another. Declarations are split onto their own lines first when a line holds several
(`int a; int b;`). Each candidate is compiled with the build's compiler and flags for the unit. A match is written to
build/probe/<unit>.<function>.match<suffix>; nothing in src/ changes.

  auto_permute.py src/Main/Some/Unit.c [function ...] [--jobs 8] [--max-run 6]
"""
import argparse
import itertools
import json
import os
import re
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from project import VERSION  # noqa: E402  (tools/project.py)
from probe_compilers import score_output, unit_flags  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
DECL = re.compile(r"^\s+(?:const\s+)?(?:unsigned\s+|signed\s+)?[A-Za-z_]\w*(?:\s*\*+\s*|\s+)\**\s*[A-Za-z_]\w*"
                  r"(?:\[[^\]]*\])*(?:\s*=\s*[^;]+)?;\s*$")
NOT_DECL = re.compile(r"^\s*(return|delete|goto|case|break|continue|else)\b")


def module_of(src):
    for path in [ROOT / f"config/{VERSION}/arm9/delinks.txt", *sorted((ROOT / f"config/{VERSION}/arm9/overlays").glob("*/delinks.txt")),
                 ROOT / f"config/{VERSION}/arm9/itcm/delinks.txt"]:
        if path.exists() and (src + ":") in path.read_text():
            return "main" if path.parent.name == "arm9" else path.parent.name
    return None


def symbols(module):
    p = ROOT / f"config/{VERSION}/arm9" / ("symbols.txt" if module == "main" else f"{module}/symbols.txt"
                                    if module in ("itcm", "dtcm") else f"overlays/{module}/symbols.txt")
    out = {}
    for line in p.read_text().splitlines():
        m = re.match(r"(\S+) kind:function\S* addr:(0x[0-9a-f]+)", line)
        if m:
            out[m.group(1)] = m.group(2)
    return out


def score(text, func, workdir, src, compiler):
    fd, path = tempfile.mkstemp(suffix=Path(src).suffix, dir=workdir)  # same language as the unit
    os.write(fd, text.encode())
    os.close(fd)
    env = dict(os.environ, PROBE_INCLUDE=":".join(filter(None, [str((ROOT / src).parent),
                                                                 os.environ.get("PROBE_INCLUDE")])))
    try:
        out = subprocess.run([sys.executable, str(ROOT / "tools/probe_compilers.py"), path, "--unit", src,
                              "--only", compiler, "--show", "-v"], cwd=ROOT, capture_output=True, text=True,
                             env=env).stdout
    finally:
        os.unlink(path)
    n = score_output(out, func)
    return 10 ** 6 if n is None else n


def body_range(lines, demangled):
    base = demangled.split("(")[0]
    short = base.split("::")[-1]
    for i, l in enumerate(lines):
        if l and not l[0].isspace() and re.search(r"\b" + re.escape(base if "::" in base else short) + r"\s*\(", l):
            j = i
            while j < len(lines) and "{" not in lines[j]:
                j += 1
            depth, k = 0, j
            for k in range(j, len(lines)):
                depth += lines[k].count("{") - lines[k].count("}")
                if depth == 0 and k > j:
                    break
            return j + 1, k
    return None


def split_decls(lines, lo, hi):
    """Puts each of several declarations on one line onto its own line."""
    out = lines[:lo]
    for l in lines[lo:hi]:
        parts = [p.strip() for p in l.split(";")[:-1]] if l.count(";") > 1 and "for" not in l and "(" not in l else None
        if parts and all(DECL.match("    " + p + ";") for p in parts):
            ind = l[:len(l) - len(l.lstrip())]
            out += [ind + p + ";" for p in parts]
        else:
            out.append(l)
    return out + lines[hi:], len(out) - lo


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("functions", nargs="*")
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--max-run", type=int, default=6)
    a = ap.parse_args()
    unit = a.src.rsplit(".", 1)[0]
    module = module_of(a.src)
    syms = symbols(module)
    report = json.loads((ROOT / f"build/{VERSION}/report.json").read_text())
    funcs = [(f["name"], f.get("metadata", {}).get("demangled_name") or f["name"]) for u in report["units"]
             if u["name"] == unit for f in u.get("functions", []) if f.get("fuzzy_match_percent", 0) < 100]
    if a.functions:
        funcs = [f for f in funcs if any(x in f[0] or x in f[1] for x in a.functions)]
    workdir = ROOT / "build/probe"
    workdir.mkdir(parents=True, exist_ok=True)
    compiler = unit_flags(a.src)[0]
    text = (ROOT / a.src).read_text()
    for mangled, dem in funcs:
        if mangled not in syms:
            print(f"{dem}: no address, skipped")
            continue
        lines = text.split("\n")
        r = body_range(lines, dem)
        if not r:
            print(f"{dem}: definition not found")
            continue
        lines, n = split_decls(lines, r[0], r[1])
        lo, hi = r[0], r[0] + n
        probe = f"// PROBE: {mangled} {module} {syms[mangled]}"
        cur = [probe] + lines
        runs, i = [], lo
        while i < hi:
            if DECL.match(lines[i]) and not NOT_DECL.match(lines[i]):
                j = i
                while j < hi and DECL.match(lines[j]) and not NOT_DECL.match(lines[j]):
                    j += 1
                if 2 <= j - i <= a.max_run:
                    runs.append((i + 1, j + 1))  # +1 for the probe line
                i = j
            else:
                i += 1
        best = score("\n".join(cur), mangled, workdir, a.src, compiler)
        print(f"{dem}: start {best}, {len(runs)} declaration runs", flush=True)
        with ThreadPoolExecutor(a.jobs) as pool:
            for s, e in runs:
                if best == 0:
                    break
                block = cur[s:e]
                cands = [cur[:s] + list(p) + cur[e:] for p in itertools.permutations(block)][1:]
                scores = list(pool.map(lambda c: score("\n".join(c), mangled, workdir, a.src, compiler), cands))
                k = min(range(len(scores)), key=scores.__getitem__) if scores else None
                if k is not None and scores[k] < best:
                    best, cur = scores[k], cands[k]
                    print(f"  run at line {s}: {best}", flush=True)
        if best == 0:
            out = workdir / f"{Path(unit).name}.{mangled}.match{Path(a.src).suffix}"
            out.write_text("\n".join(cur[1:]))
            print(f"  MATCH -> {out}", flush=True)


if __name__ == "__main__":
    main()
