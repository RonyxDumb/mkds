#!/usr/bin/env python3
"""Random source mutation search for one near-matching function (register allocation and scheduling diffs).

Mark the region to mutate inside the function with lines `// MUTATE-BEGIN` and `// MUTATE-END`; put one statement
or declaration per line there. The tool hill-climbs over random edits of that region, scoring each variant with
tools/probe_compilers.py (number of differing instructions, plus a penalty for a size difference):
  * swap two adjacent lines that are simple statements or declarations,
  * split `T x = e;` into `T x;` + `x = e;` (and merge them back),
  * change the type of a local (int, s32, u32, u16, s16, u8, s8; only locals declared with one of these names,
    BOOL or signed/unsigned int are recognized, so a plain `short` or `char` is left alone),
  * swap the operands of a commutative operator,
  * add or drop an integer cast around an identifier,
  * rewrite `x++` / `x += 1` / `x = x + 1` (and the same for --),
  * replace a pointer local (`T *p = e;`) by its initializer at each use and drop the declaration.
Only byte-identical output counts as a match, so an edit that changes the meaning can only "win" if the original
compiled to the same thing. Review the result anyway (statement swaps can move side effects).

  mutate.py <probe source> [--unit PATH] [--function NAME] [--jobs 8] [--minutes 10] [--seed N]

The source needs the usual `// PROBE:` line. It is compiled with the build's compiler and flags for --unit (default: the
source's own path). The best variant is written to <src>.best<suffix> whenever it improves.
"""
import argparse
import os
import random
import re
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from probe_compilers import PROBE, score_output, unit_flags  # noqa: E402
TYPES = ["int", "s32", "u32", "u16", "s16", "u8", "s8"]
DECL = re.compile(r"^(\s*)(const\s+)?(int|s32|u32|u16|s16|u8|s8|BOOL|unsigned int|signed int)\s+(\w+)\s*(=\s*(.+))?;\s*$")
SIMPLE = re.compile(r"^\s*[^{}]*;\s*(//.*)?$")
COMM = re.compile(r"(\b[\w.\[\]>-]+\b)\s*([+*&|^]|==|!=)\s*(\b[\w.\[\]>-]+\b)")


def score(text, workdir, opts):
    # Same suffix as the source (C stays C); its directory goes on the include path for quoted includes.
    with tempfile.NamedTemporaryFile("w", suffix=Path(opts.src).suffix, dir=workdir, delete=False) as f:
        f.write(text)
        path = f.name
    env = dict(os.environ, PROBE_INCLUDE=":".join(filter(None, [str(Path(opts.src).resolve().parent),
                                                                 os.environ.get("PROBE_INCLUDE")])))
    try:
        cmd = [sys.executable, str(ROOT / "tools/probe_compilers.py"), path, "--unit", str(opts.unit), "--only",
               opts.compiler, "--show", "-v"] + ([f"--flags={opts.flags}"] if opts.flags else [])
        out = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, env=env).stdout
    finally:
        os.unlink(path)
    n = score_output(out, opts.function)
    return 10 ** 6 if n is None else n


def mutate(lines, rng):
    out = list(lines)
    for _ in range(rng.choice([1, 1, 1, 2, 3])):
        kind = rng.randrange(7)
        idx = list(range(len(out)))
        if kind == 0:  # swap adjacent simple lines
            cand = [i for i in idx[:-1] if SIMPLE.match(out[i]) and SIMPLE.match(out[i + 1])]
            if cand:
                i = rng.choice(cand)
                out[i], out[i + 1] = out[i + 1], out[i]
        elif kind == 1:  # split / merge declaration and initialisation
            cand = [i for i in idx if (m := DECL.match(out[i])) and m.group(6)]
            merge = [i for i in idx[:-1] if (m := DECL.match(out[i])) and not m.group(6)
                     and re.match(r"^\s*" + m.group(4) + r"\s*=\s*.+;\s*$", out[i + 1])]
            if cand and (not merge or rng.random() < 0.5):
                i = rng.choice(cand)
                m = DECL.match(out[i])
                out[i:i + 1] = [f"{m.group(1)}{m.group(2) or ''}{m.group(3)} {m.group(4)};",
                                f"{m.group(1)}{m.group(4)} = {m.group(6)};"]
            elif merge:
                i = rng.choice(merge)
                m = DECL.match(out[i])
                rhs = out[i + 1].split("=", 1)[1].strip().rstrip(";")
                out[i:i + 2] = [f"{m.group(1)}{m.group(2) or ''}{m.group(3)} {m.group(4)} = {rhs};"]
        elif kind == 2:  # retype a local
            cand = [i for i in idx if DECL.match(out[i])]
            if cand:
                i = rng.choice(cand)
                m = DECL.match(out[i])
                t = rng.choice([x for x in TYPES if x != m.group(3)])
                out[i] = out[i][:m.start(3)] + t + out[i][m.end(3):]
        elif kind == 3:  # swap commutative operands
            cand = [i for i in idx if COMM.search(out[i]) and not out[i].lstrip().startswith("//")]
            if cand:
                i = rng.choice(cand)
                ms = list(COMM.finditer(out[i]))
                m = rng.choice(ms)
                out[i] = out[i][:m.start()] + f"{m.group(3)} {m.group(2)} {m.group(1)}" + out[i][m.end():]
        elif kind == 5:  # increment forms
            cand = [i for i in idx if re.search(r"(\b[\w.\[\]>-]+)(\+\+|--|\s*[+-]=\s*1\b);", out[i])]
            if cand:
                i = rng.choice(cand)
                m = re.search(r"(\b[\w.\[\]>-]+)(\+\+|--|\s*([+-])=\s*1\b);", out[i])
                v, sign = m.group(1), "+" if ("+" in m.group(2)) else "-"
                forms = [f"{v}{sign}{sign};", f"{v} {sign}= 1;", f"{v} = {v} {sign} 1;"]
                out[i] = out[i][:m.start()] + rng.choice(forms) + out[i][m.end():]
        elif kind == 6:  # inline a pointer local
            cand = [i for i in idx if re.match(r"^\s*(?:const\s+)?\w+\s*\*\s*(\w+)\s*=\s*([^;]+);\s*$", out[i])]
            if cand:
                i = rng.choice(cand)
                m = re.match(r"^\s*(?:const\s+)?\w+\s*\*\s*(\w+)\s*=\s*([^;]+);\s*$", out[i])
                name, init = m.group(1), m.group(2).strip()
                rest = [re.sub(r"\b" + name + r"\b", f"({init})", l) for l in out[i + 1:]]
                out = out[:i] + rest
        else:  # add or drop a cast
            cand = [i for i in idx if SIMPLE.match(out[i])]
            if cand:
                i = rng.choice(cand)
                casts = list(re.finditer(r"\((?:u8|s8|u16|s16|u32|s32|int)\)\s*", out[i]))
                if casts and rng.random() < 0.5:
                    c = rng.choice(casts)
                    out[i] = out[i][:c.start()] + out[i][c.end():]
                else:
                    ids = [m for m in re.finditer(r"(?<![\w.>])([a-z_]\w*)(?![\w(])", out[i])
                           if m.group(1) not in ("return", "if", "for", "while", "do", "else") + tuple(TYPES)]
                    if ids:
                        m = rng.choice(ids)
                        out[i] = out[i][:m.start()] + f"({rng.choice(TYPES)}) " + out[i][m.start():]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--minutes", type=float, default=10)
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument("--unit", help="source path whose build settings to use (default: the source itself)")
    ap.add_argument("--function", help="the probed function to score (default: the first // PROBE: line's)")
    ap.add_argument("--compiler", help="default: the build's compiler for --unit")
    ap.add_argument("--flags", help="replace -O/-inline/-ipa of the build flags for --unit")
    opts = ap.parse_args()
    src = Path(opts.src).resolve()
    opts.unit = opts.unit or (src.relative_to(ROOT) if src.is_relative_to(ROOT) else src)
    opts.compiler = opts.compiler or unit_flags(opts.unit)[0]
    probes = PROBE.findall(src.read_text())
    if not probes:
        sys.exit("the source needs a // PROBE: line")
    opts.function = opts.function or probes[0][0]
    text = Path(opts.src).read_text()
    lines = text.split("\n")
    try:
        b = next(i for i, l in enumerate(lines) if l.strip() == "// MUTATE-BEGIN")
        e = next(i for i, l in enumerate(lines) if l.strip() == "// MUTATE-END")
    except StopIteration:
        sys.exit("mark the region with // MUTATE-BEGIN and // MUTATE-END lines")
    head, region, tail = lines[:b + 1], lines[b + 1:e], lines[e:]
    rng = random.Random(opts.seed)
    work = Path(tempfile.mkdtemp(prefix="mutate_", dir=ROOT / "build"))
    best_region, best = region, score(text, work, opts)
    print(f"start: {best}", flush=True)
    deadline = time.time() + opts.minutes * 60
    cur, cur_score = region, best
    with ThreadPoolExecutor(opts.jobs) as ex:
        while time.time() < deadline and best > 0:
            cands = [mutate(cur, rng) for _ in range(opts.jobs)]
            scores = list(ex.map(lambda r: score("\n".join(head + r + tail), work, opts), cands))
            for r, s in zip(cands, scores):
                if s < best:
                    best, best_region = s, r
                    Path(opts.src).with_suffix(".best" + Path(opts.src).suffix).write_text("\n".join(head + r + tail))
                    print(f"{time.strftime('%H:%M:%S')} best {s}", flush=True)
                if s <= cur_score or rng.random() < 0.05:
                    cur, cur_score = r, s
            if rng.random() < 0.02:
                cur, cur_score = best_region, best
    print(f"done: best {best}" + (" (MATCH)" if best == 0 else ""))


if __name__ == "__main__":
    main()
