#!/usr/bin/env python3
"""Works out the declaration order that gives a unit's .bss (or .data/.rodata) objects their original layout.

How mwcc lays out a file's objects (one list for .bss, .data and .rodata together; see docs/decompiling.md, "1.12
Data layout, sections, link order"):
  * Objects are collected in declaration order and the list is built by prepending, so it ends up reversed.
  * In C++ code, each *used* singleton accessor (`static T &Get() { static T instance; ... }`) contributes three
    objects at the point where its inline function is parsed (i.e. where its header is included): the guard
    (4 bytes), the destructor-chain node `@N` (12 bytes) and the instance. File-level statics contribute themselves.
  * The list is heapsorted by size (max-heap, strict comparisons), giving ascending sizes with a scrambled order
    among equal sizes. Then the weak objects (guards, instances) move to their own sections; the rest is the
    layout.

The tool reads the compiled object, maps each `@N` node to its singleton, finds the original order of the
unit's objects (from relocations in matching functions, as data_ranges.py does), and searches the orders of
singletons (include order) and statics (definition order) for ones that reproduce it.

  data_order.py src/Main/Some/Unit.c
"""
import itertools
import subprocess
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from data_ranges import BUILD, ELFFile, RelocationSection, find_unit, load_symbols, matched_functions, \
    module_bytes  # noqa: E402
from probe_compilers import INCLUDES  # noqa: E402
from project import MWCC_VERSION, VERSION, source_flags  # noqa: E402  (tools/project.py)


def heapsort(items, key):
    a = list(items)
    n = len(a)

    def sift(i, n):
        while True:
            c = 2 * i + 1
            if c >= n:
                return
            if c + 1 < n and key(a[c + 1]) > key(a[c]):
                c += 1
            if key(a[c]) > key(a[i]):
                a[c], a[i] = a[i], a[c]
                i = c
            else:
                return

    for i in range(n // 2 - 1, -1, -1):
        sift(i, n)
    for end in range(n - 1, 0, -1):
        a[0], a[end] = a[end], a[0]
        sift(0, end)
    return a


def layout(decl, sizes):
    """decl: declaration sequence of object names. Returns the layout order."""
    return heapsort(decl[::-1], sizes.get)


def analyse(src):
    module, _, _ = find_unit(src)
    syms = load_symbols(module)
    mbase, blob = module_bytes(module)
    good = matched_functions(src)
    with (BUILD / Path(src).with_suffix(".o")).open("rb") as fh:
        elf = ELFFile(fh)
        secs = list(elf.iter_sections())
        st = list(elf.get_section_by_name(".symtab").iter_symbols())
        objs = [s for s in st if s["st_info"]["type"] == "STT_OBJECT" and isinstance(s["st_shndx"], int)]
        func_addr = {s["st_shndx"]: syms[s.name] for s in st if s["st_info"]["type"] == "STT_FUNC"
                     and s.name in good and s.name in syms and s["st_value"] == 0}
        orig = {}  # object name -> original address
        node_owner = {}  # @N -> instance symbol name (closest instance reference in the same function)
        for sec in secs:
            if not isinstance(sec, RelocationSection):
                continue
            tgt = sec["sh_info"]
            if secs[tgt].name != ".text":
                continue
            data = secs[tgt].data()
            refs = []
            for r in sec.iter_relocations():
                sym = st[r["r_info_sym"]]
                if not isinstance(sym["st_shndx"], int):
                    if sym.name.startswith("_ZZ"):
                        refs.append((r["r_offset"], sym.name))
                    continue
                name = sym.name
                addend = struct.unpack_from("<I", data, r["r_offset"])[0]
                if sym["st_info"]["type"] == "STT_SECTION":
                    hit = [o for o in objs if o["st_shndx"] == sym["st_shndx"]
                           and o["st_value"] <= addend < o["st_value"] + max(o["st_size"], 1)]
                    if not hit:
                        continue
                    name, addend = hit[0].name, addend - hit[0]["st_value"]
                refs.append((r["r_offset"], name))
                if tgt in func_addr:
                    w = struct.unpack_from("<I", blob, func_addr[tgt] + r["r_offset"] - mbase)[0]
                    orig.setdefault(name, w - addend)
            for off, name in refs:
                if name.startswith("@"):
                    inst = [(abs(o - off), n) for o, n in refs if n.startswith("_ZZ") and n.endswith("instance")]
                    if inst:
                        node_owner.setdefault(name, min(inst)[1])
    return secs, objs, orig, node_owner


def parse_order_owners(src, objs):
    """Maps each `@N` destructor-chain node to its singleton's instance symbol: nodes are numbered in parse
    order, so the i-th node (by N) belongs to the i-th singleton (in preprocessed source order) that this file
    uses and whose type has a destructor (the registration passes the destructor, so the object references it)."""
    root = Path(__file__).resolve().parent.parent
    version, flags = source_flags(src)  # preprocess exactly as the build compiles this file
    pp = subprocess.run(["tools/bin/wibo", f"tools/mwccarm/{version or MWCC_VERSION}/mwccarm.exe", "-E", *flags,
                         *(w for d in INCLUDES for w in ("-i", d)), "-d", f"version_{VERSION.upper()}", src],
                        cwd=root, capture_output=True, text=True).stdout
    order = []
    for m in re.finditer(r"static\s+(\w+)\s*&\s*Get\s*\(\s*\)\s*\{\s*static\s+\1\s+instance", pp):
        if m.group(1) not in order:
            order.append(m.group(1))
    obj = BUILD / Path(src).with_suffix(".o")
    with obj.open("rb") as fh:
        elf = ELFFile(fh)
        names = {s.name for s in elf.get_section_by_name(".symtab").iter_symbols()}
        bss = {i for i, sec in enumerate(elf.iter_sections()) if sec.name == ".bss"}
    insts = {o.name for o in objs}
    with_node = [c for c in order if f"_ZZN{len(c)}{c}3GetEvE8instance" in insts
                 and f"_ZN{len(c)}{c}D1Ev" in names]
    nodes = sorted((o.name for o in objs if re.fullmatch(r"@\d+", o.name) and o["st_shndx"] in bss
                    and o["st_size"] == 12), key=lambda n: int(n[1:]))
    if len(nodes) != len(with_node):
        print(f"warning: {len(nodes)} nodes but {len(with_node)} singletons with destructors: {with_node}")
    return {n: f"_ZZN{len(c)}{c}3GetEvE8instance" for n, c in zip(nodes, with_node)}, order


ROOT = Path(__file__).resolve().parent.parent


def main():
    src = sys.argv[1]
    secs, objs, orig, _ = analyse(src)
    node_owner, parse_order = parse_order_owners(src, objs)
    size = {o.name: o["st_size"] for o in objs}
    by_sec = {}
    for o in objs:
        by_sec.setdefault(o["st_shndx"], []).append(o)
    for idx, members in sorted(by_sec.items()):
        sec = secs[idx]
        local = [o for o in members if o["st_info"]["bind"] == "STB_LOCAL" or o["st_info"]["bind"] == "STB_GLOBAL"]
        local = [o for o in local if o["st_info"]["bind"] == "STB_LOCAL" or not o.name.startswith(("_ZZ", "_ZGVZ"))]
        if len(local) < 2 or not sec["sh_flags"] & 2:
            continue
        cur = [o.name for o in sorted(local, key=lambda o: o["st_value"])]
        if any(n not in orig for n in cur):
            print(f"{sec.name}#{idx}: not every object is placed: {[n for n in cur if n not in orig]}")
            continue
        want = sorted(cur, key=lambda n: orig[n])
        if want == cur:
            continue
        print(f"{sec.name}#{idx}: layout {cur}\n   original {want}")
        # Declaration units: every used singleton (guard, node if any, instance; .bss only) and each static.
        is_bss = sec["sh_type"] == "SHT_NOBITS"
        node_of = {inst: n for n, inst in node_owner.items()}
        singles = [c for c in parse_order if f"_ZZN{len(c)}{c}3GetEvE8instance" in size] if is_bss else []
        statics = [n for n in cur if n not in node_owner]
        text = (ROOT / src).read_text()
        statics.sort(key=lambda n: (m.start() if (m := re.search(r"\b" + re.escape(n) + r"\b", text)) else 0))
        units = {}
        for c in singles:
            inst = f"_ZZN{len(c)}{c}3GetEvE8instance"
            guard = "_ZGVZ" + inst[3:]
            size.setdefault(guard, 4)
            units[c] = [guard] + ([node_of[inst]] if inst in node_of else []) + [inst]
        for n in statics:
            units[n] = [n]
        nodes = singles
        cur_decl = [x for u in units for x in units[u]]
        model_now = [x for x in layout(cur_decl, size) if x in cur]
        print(f"   model {'reproduces' if model_now == cur else 'does NOT reproduce'} the current layout"
              + ("" if model_now == cur else f" (predicts {model_now})"))
        if len(units) > 9:
            print("   too many declaration units to search")
            continue
        found = []
        for perm in itertools.permutations(list(units)):
            decl = [x for u in perm for x in units[u]]
            out = [x for x in layout(decl, size) if x in cur]
            if out == want:
                found.append(perm)
        if not found:
            print("   no declaration order reproduces it (other objects in the list?)")
            continue
        # Prefer orders that keep singletons before statics (includes come first in a file).
        found.sort(key=lambda p: (sum(1 for i, u in enumerate(p) if u in statics
                                      and any(v in nodes for v in p[i + 1:])), p))
        for perm in found[:3]:
            print("   declare: " + ", ".join(f"{u}::Get (header)" if u in nodes else u for u in perm))
        if len(found) > 3:
            print(f"   ... {len(found)} orders in all")


if __name__ == "__main__":
    main()
