#!/usr/bin/env python3
"""The compiler's data order for one file (the shared model), and searches for the declaration order that gives a
unit's data sections their layout in the ROM. docs/decompiling.md, "1.11 Data Layout, Sections and Link Order".

Model (mwcc 1.2 with the project's flags; layout_search.py and fix_static_order.py use it from here):
  * Every file-level object and every string literal is its own section.
  * While the file is parsed, data objects are queued: each definition with an initialiser where it stands (the
    string literals of its initialiser just before it), `= 0` / `= NULL` definitions the same way, a function's
    local initialiser (a local array's initialiser, a local static) where the function is defined, and at the end
    the definitions without an initialiser (`T *gX;`) in reverse definition order.
  * The queue is sorted once, by size only, with heapsort() below, and written in that order; each section
    receives its objects in that order. A file with no function is sorted the same way.
  * Literals used inside functions are not queued: they follow, function by function, in emission order.
  * In C++ code, each *used* singleton accessor (`static T &Get() { static T instance; ... }`) contributes three
    objects where its inline function is parsed (where its header is included): the guard (4 bytes), the
    destructor-chain node `@N` (12 bytes) and the instance.

  data_order.py src/Main/Some/Unit.c   search declaration orders for one unit (reads its compiled object and the
                                       report's matching functions, as data_ranges.py does)
  data_order.py --check [SRC..]        rebuild each unit's queue from its preprocessed source and say whether the
                                       model gives its compiled layout (default: every unit with data objects)
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
from link_check import delinks_files, parse_units  # noqa: E402
from probe_compilers import INCLUDES  # noqa: E402
from project import MWCC_VERSION, VERSION, source_flags  # noqa: E402  (tools/project.py)


def heapsort(items, key):
    """The compiler's sort: 1-based heapsort; the right child is taken only when strictly larger, a sift stops when
    the parent is not smaller; equal sizes keep no stable order."""
    a = list(items)
    n = len(a)
    if n < 2:
        return a
    k = [key(x) for x in a]
    lo, m = (n >> 1) + 1, n
    while True:
        if lo < 2:
            a[0], a[m - 1] = a[m - 1], a[0]
            k[0], k[m - 1] = k[m - 1], k[0]
            m -= 1
            if m == 1:
                return a
        else:
            lo -= 1
        if m < lo * 2:
            continue
        i = lo
        while True:
            j = i * 2
            if j < m and k[j - 1] < k[j]:
                j += 1
            if k[i - 1] >= k[j - 1]:
                break
            a[i - 1], a[j - 1] = a[j - 1], a[i - 1]
            k[i - 1], k[j - 1] = k[j - 1], k[i - 1]
            i = j
            if i * 2 > m:
                break


def queue(units, tentatives=()):
    """units: queued definition units in file order, each a list of names (initialiser literals first, the object
    last; a local initialiser is a unit at its function's place); tentatives: definitions without an initialiser,
    in definition order. Returns the queue."""
    return [n for u in units for n in u] + list(tentatives)[::-1]


def layout(decl, sizes, tentatives=()):
    """decl: queued objects in definition order (literals before their object); tentatives: definitions without an
    initialiser, in definition order. Returns the written order."""
    return heapsort(queue([decl], tentatives)[::-1], sizes.get)


def emit(units, tentatives, size):
    return layout([n for u in units for n in u], size, tentatives)


def by_section(order, sec):
    out = {}
    for n in order:
        out.setdefault(sec[n], []).append(n)
    return out


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


def _depths(text):
    """Brace and parenthesis depth at every position of preprocessed text (strings, chars and # lines skipped)."""
    brace, paren = [0] * (len(text) + 1), [0] * (len(text) + 1)
    b = q = 0
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        brace[i], paren[i] = b, q
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            for k in range(i, min(j + 1, n)):
                brace[k], paren[k] = b, q
            i = j + 1
            continue
        if c == "#" and (i == 0 or text[i - 1] == "\n"):
            j = text.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                brace[k], paren[k] = b, q
            i = j
            continue
        if c == "{":
            b += 1
        elif c == "}":
            b -= 1
        elif c == "(":
            q += 1
        elif c == ")":
            q -= 1
        i += 1
    brace[n], paren[n] = b, q
    return brace, paren


def _statement(text, i):
    """The declaration text from the previous `;`, `}` or `{` (or # line) up to position i."""
    j = max(text.rfind(";", 0, i), text.rfind("}", 0, i), text.rfind("{", 0, i), text.rfind("\n#", 0, i))
    return text[j + 1:i]


def preprocess(src):
    root = Path(__file__).resolve().parent.parent
    version, flags = source_flags(src)
    flags = [w for f in flags for w in f.split()]  # one argument per word, as the build passes them
    r = subprocess.run(["tools/bin/wibo", f"tools/mwccarm/{version or MWCC_VERSION}/mwccarm.exe", "-E", *flags,
                        *(w for d in INCLUDES for w in ("-i", d)), "-d", f"version_{VERSION.upper()}", src],
                       cwd=root, capture_output=True, text=True)
    return r.stdout if r.returncode == 0 else None


def check_unit(src, text=None):
    """Rebuilds the unit's queue from its preprocessed source and compares the model's order with the compiled
    object. Returns (status, detail): 'ok', 'differs' (the model gives another order) or 'unclassified' (an object
    the source reading cannot place; nothing is skipped silently)."""
    obj = BUILD / Path(src).with_suffix(".o")
    with obj.open("rb") as fh:
        elf = ELFFile(fh)
        secs = list(elf.iter_sections())
        st = list(elf.get_section_by_name(".symtab").iter_symbols())
        objs = [o for o in st if o["st_info"]["type"] == "STT_OBJECT" and isinstance(o["st_shndx"], int)
                and secs[o["st_shndx"]]["sh_flags"] & 2 and not secs[o["st_shndx"]]["sh_flags"] & 4]
        if not objs:
            return "none", ""
        funcs = [f for f in st if f["st_info"]["type"] == "STT_FUNC" and isinstance(f["st_shndx"], int)
                 and not f.name.startswith("$")]
        name_of = {}
        for o in objs:
            name_of[(o["st_shndx"], o["st_value"])] = o.name
        sec_kind = {o.name: secs[o["st_shndx"]].name for o in objs}
        size = {o.name: o["st_size"] for o in objs}
        place = {o.name: (o["st_shndx"], o["st_value"]) for o in objs}

        def target(r, sec_data):
            t = st[r["r_info_sym"]]
            if t["st_info"]["type"] == "STT_SECTION":
                if r.is_RELA():
                    add = r["r_addend"]
                else:
                    add = struct.unpack_from("<I", sec_data, r["r_offset"])[0] if sec_data else 0
                return name_of.get((t["st_shndx"], add))
            return t.name if t.name in size else None

        init_lits, text_refs = {}, {}  # object -> its initialiser's @N, in order; @N -> referencing function
        for rs in secs:
            if not isinstance(rs, RelocationSection):
                continue
            ts = secs[rs["sh_info"]]
            data = ts.data() if ts["sh_type"] != "SHT_NOBITS" else b""
            for r in sorted(rs.iter_relocations(), key=lambda r: r["r_offset"]):
                tg = target(r, data)
                if tg is None:
                    continue
                if ts["sh_flags"] & 4:
                    fn = [f.name for f in funcs if f["st_shndx"] == rs["sh_info"]
                          and f["st_value"] <= r["r_offset"] < f["st_value"] + max(f["st_size"], 1)]
                    fn = fn or [f.name for f in funcs if f["st_shndx"] == rs["sh_info"]][-1:]
                    text_refs.setdefault(tg, fn[0] if fn else None)
                    continue
                own = [o.name for o in objs if o["st_shndx"] == rs["sh_info"]
                       and o["st_value"] <= r["r_offset"] < o["st_value"] + o["st_size"]]
                if own and tg.startswith("@") and tg != own[0] and not any(tg in v for v in init_lits.values()):
                    init_lits.setdefault(own[0], []).append(tg)

        def is_string(o):
            sec = secs[o["st_shndx"]]
            if sec["sh_type"] == "SHT_NOBITS":
                return False
            b = sec.data()[o["st_value"]:o["st_value"] + o["st_size"]]
            if len(b) >= 2 and len(b) % 2 == 0 and b.endswith(b"\0\0") and not any(b[1::2]):  # wide string
                return all(32 <= c < 127 or c in (9, 10, 13) for c in b[:-2:2])
            return len(b) > 0 and b.endswith(b"\0") and all(32 <= c < 127 or c in (9, 10, 13) or c >= 0x80
                                                              for c in b[:-1])

        strings = {o.name for o in objs if is_string(o)}
    if text is None:
        text = preprocess(src)
    if text is None:
        return "unclassified", "preprocess failed"
    brace, paren = _depths(text)

    def func_pos(name):
        for m in re.finditer(r"\b" + re.escape(name) + r"\s*\(", text):
            if brace[m.start()] == 0 and paren[m.start()] == 0:
                k = m.end() - 1
                d = 0
                while k < len(text):
                    d += {"(": 1, ")": -1}.get(text[k], 0)
                    k += 1
                    if d == 0:
                        break
                if text[k:k + 200].lstrip().startswith("{"):
                    return k
        return None

    lits_of = {n for v in init_lits.values() for n in v}
    defs, tents, local, tail, bad = {}, {}, {}, [], []
    for o in objs:
        n = o.name
        if n in lits_of:
            continue
        found = None
        if not n.startswith("@"):
            for m in re.finditer(r"\b" + re.escape(n) + r"\b(?:\s*\[[^\]]*\])*(?:\s*\)\s*\([^()]*\))?\s*(=|;|,)",
                                 text):
                i = m.start()
                if brace[i] != 0 or paren[i] > 1 or paren[i] == 1 and not re.search(r"\(\s*\*\s*$", text[i - 12:i]):
                    continue
                head = _statement(text, i)
                if re.search(r"\b(extern|typedef)\b", head):
                    continue
                init = m.group(1) == "="
                if found is None or (init and not found[1]):
                    found = (i, init)
            if found:
                (defs if found[1] else tents)[n] = found[0]
                continue
        fn = text_refs.get(n)
        if n.startswith("@") and n in strings and fn is not None:
            tail.append(n)
            continue
        if fn is not None and (n.startswith("@") or "$" in n) and (fp := func_pos(fn)) is not None:
            local[n] = fp
            continue
        bad.append(n)
    if bad:
        return "unclassified", " ".join(sorted(bad))
    units = sorted([(p, 0, init_lits.get(n, []) + [n]) for n, p in defs.items()]
                   + [(p, int(re.sub(r"^.*[@$]", "", n) or 0), init_lits.get(n, []) + [n]) for n, p in local.items()])
    order = emit([u for _, _, u in units], sorted(tents, key=tents.get), size)
    got = {}
    for n in sorted(size, key=place.get):
        got.setdefault(sec_kind[n], []).append(n)
    want = by_section(order, sec_kind)
    diffs = []
    for k in sorted(set(got) | set(want)):
        g = [n for n in got.get(k, []) if n not in tail]
        if g != want.get(k, []):
            diffs.append(f"{k}: model {want.get(k, [])} compiled {g}")
        gt = got.get(k, [])
        if gt[:len(g)] != g:
            diffs.append(f"{k}: function literals among the sorted objects")
    return ("differs", "; ".join(diffs)) if diffs else ("ok", f"{len(order)} queued, {len(tail)} function literals")


def check_main(srcs):
    import concurrent.futures as cf
    if not srcs:
        srcs = sorted({u["file"] for _, path in delinks_files() for u in parse_units(path)
                       if u["file"].endswith(".c") and (BUILD / Path(u["file"]).with_suffix(".o")).exists()})
    counts = {}
    with cf.ProcessPoolExecutor() as ex:
        for src, (status, detail) in zip(srcs, ex.map(_check_one, srcs)):
            counts[status] = counts.get(status, 0) + 1
            if status not in ("ok", "none"):
                print(f"{status}\t{src}\t{detail}")
    print("summary: " + ", ".join(f"{k} {v}" for k, v in sorted(counts.items())))
    return 0 if set(counts) <= {"ok", "none"} else 1


def _check_one(src):
    try:
        return check_unit(src)
    except Exception as e:  # report, never skip
        return "unclassified", f"error {e}"


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
    if sys.argv[1:2] == ["--check"]:
        sys.exit(check_main(sys.argv[2:]))
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
