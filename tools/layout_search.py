#!/usr/bin/env python3
"""Searches static definition order (and, in C++ code, singleton include order) for the original data layout, offline.

mwcc collects every object of a file into one list (.bss, .data and .rodata together), by prepending as they are
declared, heapsorts it by size and emits it in that order (see docs/decompiling.md, "1.12 Data layout, sections,
link order"). The participants:
  * each file-level static, where it is defined, preceded by the string literals of its initializer;
  * in C++ code, each used singleton accessor, where its header is first parsed: guard (4), destructor-chain node @N
    (12, only for classes with a destructor) and instance, as node, guard, instance or guard, node, instance;
  * in C++ code, the file's vtables, at the end.
Literals used inside functions are emitted afterwards in creation order and don't take part.

The tool reads the compiled object, rebuilds that list for the current source and calibrates the per-singleton object
order until the model reproduces the compiled order exactly (it stops if it can't). Then it searches singleton
orders and static orders for ones whose output puts the unit's objects in their original address order (taken from
relocations in matching functions, as data_ranges.py does), and prints the closest few.

  layout_search.py src/Main/Some/Unit.c [--max-statics 8] [--climb 300]
"""
import argparse
import itertools
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).parent))
from data_order import analyse, heapsort, parse_order_owners  # noqa: E402
from data_ranges import find_unit, module_bytes  # noqa: E402
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
ref_off = {}  # string literal -> (table that points at it, offset of the pointer in the table)


def read_object(src):
    elf = ELFFile((ROOT / f"build/{VERSION}" / Path(src).with_suffix(".o")).open("rb"))
    secs = list(elf.iter_sections())
    syms = list(elf.get_section_by_name(".symtab").iter_symbols())
    objs = [s for s in syms if s["st_info"]["type"] == "STT_OBJECT" and isinstance(s["st_shndx"], int)
            and secs[s["st_shndx"]]["sh_flags"] & 2]
    # String literals referenced from data (initializers), per referencing object, in offset order.
    refs = {}
    ref_off.clear()
    for rs in secs:
        if not isinstance(rs, RelocationSection) or secs[rs["sh_info"]].name not in (".data", ".rodata"):
            continue
        owners = [o for o in objs if o["st_shndx"] == rs["sh_info"]]
        for r in sorted(rs.iter_relocations(), key=lambda r: r["r_offset"]):
            tgt = syms[r["r_info_sym"]]
            own = [o for o in owners if o["st_value"] <= r["r_offset"] < o["st_value"] + o["st_size"]]
            if not own:
                continue
            if tgt.name and tgt.name not in ref_off and tgt["st_info"]["type"] == "STT_OBJECT":
                ref_off[tgt.name] = (own[0].name, r["r_offset"] - own[0]["st_value"])
            if tgt.name.startswith("@") and tgt.name not in refs.get(own[0].name, []):
                refs.setdefault(own[0].name, []).append(tgt.name)
    order = sorted(objs, key=lambda s: (s["st_shndx"], s["st_value"]))
    return objs, order, refs, {o.name: secs[o["st_shndx"]].name for o in objs}


def climb(singles, statics, restarts, emitted, predict, build, triv, placed, kind, orig, cost):
    """Random-restart hill climb over singleton order, static order and split, for files with too many statics to
    permute. Scores an order by how many placed objects are out of their original order."""
    import random

    random.seed(1)

    def bad(so, st, split):
        out = emitted(predict(build(so, triv, list(st), split)))
        n = 0
        for k in set(kind[x] for x in placed):
            got = [x for x in out if x in placed and kind[x] == k]
            n += sum(1 for x, y in zip(got, sorted(got, key=lambda x: orig[x])) if x != y)
        return n

    hits, seen = [], set()
    for _ in range(restarts):
        so, st = list(singles), list(statics)
        random.shuffle(so)
        random.shuffle(st)
        split = random.randint(0, len(so))
        c = bad(so, st, split)
        for _ in range(4000):
            if c == 0:
                break
            nso, nst, nsp = so[:], st[:], split
            r = random.random()
            if r < 0.3 and len(nso) > 1:
                i, j = random.sample(range(len(nso)), 2)
                nso[i], nso[j] = nso[j], nso[i]
            elif r < 0.85 and len(nst) > 1:
                i, j = random.sample(range(len(nst)), 2)
                nst.insert(j, nst.pop(i))
            else:
                nsp = random.randint(0, len(nso))
            nc = bad(nso, nst, nsp)
            if nc <= c:
                so, st, split, c = nso, nst, nsp, nc
        key = (tuple(so), tuple(st), split)
        if c == 0 and key not in seen:
            seen.add(key)
            hits.append((cost(so, st, split), tuple(so), tuple(st), split))
    return hits


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src")
    ap.add_argument("--max-statics", type=int, default=8, help="most statics to permute (8! orders)")
    ap.add_argument("--show", type=int, default=5)
    ap.add_argument("--weak", action="store_true",
                    help="also place the singleton guards and instances that lie in the unit's own ranges")
    ap.add_argument("--climb", type=int, default=0, metavar="RESTARTS",
                    help="hill-climb with this many restarts instead of permuting (for many statics)")
    a = ap.parse_args()
    src = a.src

    objs, order, refs, objs_secname = read_object(src)
    size = {o.name: o["st_size"] for o in objs}
    node_owner, parse = parse_order_owners(src, objs)
    node_of = {inst: n for n, inst in node_owner.items()}
    singles = [c for c in parse if f"_ZZN{len(c)}{c}3GetEvE8instance" in size]
    table_strs = {s for v in refs.values() for s in v}
    text = (ROOT / src).read_text()

    def pos(name):
        m = re.search(r"\b" + re.escape(name) + r"\s*(\[[^\]]*\])*\s*=", text)
        return m.start() if m else None

    statics = [o.name for o in objs if not o.name.startswith(("@", "_ZGVZ", "_ZZ", "_ZTV")) and pos(o.name) is not None]
    statics.sort(key=pos)
    vtables = [o.name for o in objs if o.name.startswith("_ZTV")]
    vtables.sort(key=lambda n: text.find(n[4:].lstrip("0123456789")), reverse=True)

    def triple(c, trivial):
        inst = f"_ZZN{len(c)}{c}3GetEvE8instance"
        g = "_ZGVZ" + inst[3:]
        n = [node_of[inst]] if inst in node_of else []
        return (n + [g] if trivial else [g] + n) + [inst]

    def build(sing_order, triv, stat_order, split=None):
        """split: how many singleton headers come before the statics (default: all of them)."""
        split = len(sing_order) if split is None else split
        d = []
        for c in sing_order[:split]:
            d += triple(c, triv[c])
        for s in stat_order:
            d += refs.get(s, []) + [s]
        for c in sing_order[split:]:
            d += triple(c, triv[c])
        return d + vtables

    participants = set(build(singles, {c: 0 for c in singles}, statics))
    actual = [o.name for o in order if o.name in participants]
    section = {o.name: o["st_shndx"] for o in objs}

    def predict(decl):
        return heapsort(decl[::-1], size.get)

    def emitted(pred):
        """The emission order a predicted list gives: each section at the place of its first member, members in order."""
        seen, out = set(), []
        for n in pred:
            if section[n] in seen:
                continue
            seen.add(section[n])
            out += [m for m in pred if section[m] == section[n]]
        return out

    def same_as_actual(pred):
        e = emitted(pred)
        secs_e = [section[n] for i, n in enumerate(e) if i == 0 or section[e[i - 1]] != section[n]]
        secs_a = [section[n] for i, n in enumerate(actual) if i == 0 or section[actual[i - 1]] != section[n]]
        return e == actual or (secs_e == secs_a and all(
            [m for m in e if section[m] == x] == [m for m in actual if section[m] == x] for x in set(secs_a)))

    # Calibrate: which singletons put the node before the guard.
    triv = None
    for combo in itertools.product([1, 0], repeat=len(singles)):
        t = dict(zip(singles, combo))
        if same_as_actual(predict(build(singles, t, statics))):
            triv = t
            break
    if triv is None:
        print("model does not reproduce the current layout; participants:")
        print("  singletons", singles, "\n  statics", statics, "\n  vtables", vtables)
        print("  actual   ", actual)
        print("  predicted", predict(build(singles, {c: 1 for c in singles}, statics)))
        sys.exit(1)
    print("model reproduces the current layout; node first for:", [c for c in singles if triv[c]] or "none")

    # Target: original address order of the unit's own (non-weak) objects that matching code places.
    _, _, orig, _ = analyse(src)
    # Literals only a table points at: read the pointer from the original table.
    module, _, _ = find_unit(src)
    mbase, blob = module_bytes(module)
    for lit, (tab, off) in ref_off.items():
        if tab in orig and lit not in orig:
            orig[lit] = struct.unpack_from("<I", blob, orig[tab] + off - mbase)[0]
    weak_owned = set()
    if a.weak:
        # Singleton guards and instances this unit's copy provides in the original link: their symbols.txt
        # addresses lie inside the unit's own ranges (set those by hand first).
        _, _, unit = find_unit(src)
        cfg = ROOT / f"config/{VERSION}/arm9" / ("symbols.txt" if module == "main" else f"overlays/{module}/symbols.txt")
        for ln in cfg.read_text().splitlines():
            m = re.match(r"(_ZGVZ\S+|_ZZ\S+) kind:(bss|data)\S* addr:(0x[0-9a-f]+)", ln)
            if m and m.group(1) in size:
                addr = int(m.group(3), 16)
                if any(lo <= addr < hi for lo, hi in unit["ranges"].values()):
                    orig[m.group(1)] = addr
                    weak_owned.add(m.group(1))
    placed = [n for n in actual if n in orig and (n in weak_owned or not n.startswith(("_ZGVZ", "_ZZ")))]
    kind = {o.name: objs_secname[o.name] for o in objs}

    def matches(out):
        """Within each section kind, the emitted order of placed objects is their original address order."""
        for k in set(kind[n] for n in placed):
            got = [n for n in out if n in placed and kind[n] == k]
            if got != sorted(got, key=lambda n: orig[n]):
                return False
        return True

    if matches(actual):
        print("current layout already matches the original")
        return
    print(f"{len(placed)} placed objects; searching...")
    def cost(so, st, split):
        return (sum(1 for i, c in enumerate(so) if c != singles[i])
                + sum(1 for i, s in enumerate(st) if s != statics[i]) + (len(so) - split))

    hits = []
    if a.climb:
        hits = climb(singles, statics, a.climb, emitted, predict, build, triv, placed, kind, orig, cost)
        fixed = []
    else:
        movable = statics if len(statics) <= a.max_statics else statics[:a.max_statics]
        fixed = [s for s in statics if s not in movable]
        for so in itertools.permutations(singles):
            for st in itertools.permutations(movable):
                for split in range(len(so), -1, -1):
                    out = emitted(predict(build(so, triv, list(st) + fixed, split)))
                    if matches(out):
                        hits.append((cost(so, list(st) + fixed, split), so, st, split))
    if not hits:
        print("no order found (other participants, or statics beyond --max-statics)")
        sys.exit(1)
    hits.sort()
    print(f"{len(hits)} orders; closest:")
    for cost, so, st, split in hits[:a.show]:
        print(f"  [{cost}] headers first: {', '.join(so[:split]) or '-'}; then statics: {', '.join(st + tuple(fixed))}"
              + (f"; then headers: {', '.join(so[split:])}" if split < len(so) else ""))


if __name__ == "__main__":
    main()
