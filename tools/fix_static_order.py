#!/usr/bin/env python3
"""Reorders a unit's file-level static definitions so its data sections get the original layout.

mwcc collects a section's objects in reverse declaration order and heapsorts them by size (see
docs/decompiling.md), so the layout of equal-sized objects depends on their definition order. For each data
section whose objects are out of the original order, this tool searches definition orders with that model,
rewrites the definitions (each moves as a whole, with the comment block above it) into the closest order that
works, recompiles and asks data_ranges.py. The file is restored if that doesn't settle it.

  fix_static_order.py src/Main/Some/Unit.c [--brute] [--dry-run]

C++ singleton objects aren't moved here (see fix_layout.py for include order).
"""
import itertools
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from data_order import analyse, layout  # noqa: E402
from reorder_functions import chunks  # noqa: E402
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent


def problems(src):
    out = subprocess.run(["python3", "tools/data_ranges.py", src], cwd=ROOT, capture_output=True, text=True).stdout
    return sum(1 for ln in out.splitlines() if (ln.startswith("conflict") and "outside the original" not in ln)
               or "order differs" in ln)


def main():
    src = sys.argv[1]
    dry = "--dry-run" in sys.argv
    path = ROOT / src
    original = path.read_text()
    obj = str(Path(f"build/{VERSION}") / Path(src).with_suffix(".o"))
    if problems(src) == 0:
        print(f"{src}: no layout problems")
        return
    secs, objs, orig, _ = analyse(src)
    size = {o.name: o["st_size"] for o in objs}
    text = original
    parts = chunks(text)

    def chunk_of(name):
        for i, (s, e, b) in enumerate(parts):
            head = text[s:b] if b is not None else text[s:e]
            head = re.sub(r"//[^\n]*", "", head)
            if re.search(r"\bstatic\b[^;{]*\b" + re.escape(name) + r"\s*(\[|=|;)", head):
                return i
        return None

    def move_part(i):
        s, e, _ = parts[i]
        lines = text[s:e].split("\n")
        head = next(j for j, ln in enumerate(lines) if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
        top = head
        while top > 0 and lines[top - 1].strip().startswith("//"):
            top -= 1
        return "\n".join(lines[:top]) + ("\n" if top else ""), "\n".join(lines[top:])

    def rewrite(order):
        out = []
        for i, (s, e, _) in enumerate(parts):
            if i in order:
                out.append(move_part(i)[0] + move_part(order[i])[1])
            else:
                out.append(text[s:e])
        return "".join(out)

    by_sec = {}
    for o in objs:
        by_sec.setdefault(o["st_shndx"], []).append(o)
    new_order = {}
    for idx, members in by_sec.items():
        names = [o.name for o in sorted(members, key=lambda o: o["st_value"])]
        if len(names) < 2 or any(n not in orig for n in names):
            continue
        want = sorted(names, key=lambda n: orig[n])
        if want == names:
            continue
        idxs = {n: chunk_of(n) for n in names}
        if any(v is None for v in idxs.values()):
            print(f"section {idx}: can't find every definition: {idxs}")
            continue
        cur_decl = sorted(names, key=lambda n: idxs[n])
        best = None
        cands = [p for p in itertools.permutations(cur_decl) if layout(list(p), size) == want]
        if "--brute" in sys.argv:
            # The model misses participants in real files: try every order, model's picks first.
            rest = [p for p in itertools.permutations(cur_decl) if p not in cands and p != tuple(cur_decl)]
            for perm in cands + rest:
                trial = rewrite({s: idxs[n] for s, n in zip(sorted(idxs.values()), perm)})
                path.write_text(trial)
                if subprocess.run(["ninja", obj], cwd=ROOT, capture_output=True).returncode == 0 \
                        and problems(src) == 0:
                    print(f"section {idx}: works when defined as {', '.join(perm)}")
                    if dry:
                        path.write_text(original)
                    return
            print(f"section {idx}: no definition order works")
            path.write_text(original)
            subprocess.run(["ninja", obj], cwd=ROOT, capture_output=True)
            return
        for perm in cands:
            dist = sum(a != b for a, b in zip(perm, cur_decl))
            if best is None or dist < best[0]:
                best = (dist, perm)
        if best is None:
            print(f"section {idx}: no definition order gives {want}")
            continue
        print(f"section {idx}: define as {', '.join(best[1])}")
        slots = sorted(idxs[n] for n in names)
        for slot, n in zip(slots, best[1]):
            new_order[slot] = idxs[n]
    if not new_order:
        return

    path.write_text(rewrite(new_order))
    ok = subprocess.run(["ninja", obj], cwd=ROOT, capture_output=True).returncode == 0 and problems(src) == 0
    print("works" if ok else "didn't settle it; restored")
    if dry or not ok:
        path.write_text(original)
        subprocess.run(["ninja", obj], cwd=ROOT, capture_output=True)


if __name__ == "__main__":
    main()
