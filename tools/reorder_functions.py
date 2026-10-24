#!/usr/bin/env python3
"""Reorders the function definitions of a source file into the original address order.

mwcc 2.0 emits functions in source order and 1.2 in reverse (tools/project.py: emits_reversed); the linker keeps the
object's order, so a unit only links once its definitions follow the original addresses (descending under 1.2).
This tool splits the file into top-level chunks, finds each function definition's symbol in the compiled object
(by demangled name; overloads by order), and permutes the function chunks among the slots they already occupy.
Everything else (includes, declarations, data, comments between functions) stays where it is; a comment block
directly above a function moves with it. Free functions that end up used before their definition need a
prototype; the tool adds one above the first function slot when compiling fails.

  reorder_functions.py src/Main/Some/Unit.c [--write]
  reorder_functions.py --fix-decls <files...>   (after --write, until each file compiles)

Without --write it prints the old and new order. Functions emitted without a definition in this file (in C++,
inline methods from headers and implicit destructors) can't be moved by this tool; they are listed for manual work.
Verify afterwards: recompile, `ninja report` (matches unchanged) and `link_check.py`.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import BUILD, delinks_files, load_symbols, parse_units  # noqa: E402
from project import emits_reversed  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent


def chunks(text: str):
    """Splits into top-level chunks: (start, end, kind) with kind 'func' or 'other'."""
    out = []
    i, n = 0, len(text)
    start = 0
    depth = 0
    first_brace = None
    while i < n:
        c = text[i]
        if text.startswith("//", i):
            i = text.find("\n", i)
            i = n if i < 0 else i
            continue
        if text.startswith("/*", i):
            i = text.find("*/", i) + 2
            continue
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            i = j + 1
            continue
        if c == "#" and depth == 0 and (i == 0 or text[i - 1] == "\n"):
            while True:  # preprocessor line with continuations
                j = text.find("\n", i)
                j = n if j < 0 else j
                if text[j - 1] != "\\":
                    break
                i = j + 1
            i = j
            continue
        if c == "{":
            if depth == 0 and first_brace is None:
                first_brace = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                end = i + 1
                k = end
                while k < n and text[k] in " \t":
                    k += 1
                if k < n and text[k] == ";":
                    end = k + 1
                out.append((start, end, first_brace))
                start, first_brace = end, None
                i = end
                continue
        elif c == ";" and depth == 0:
            out.append((start, i + 1, None))
            start, first_brace = i + 1, None
        i += 1
    out.append((start, n, None))
    return out


HEAD_SKIP = re.compile(r"^\s*(class|struct|union|enum|namespace|typedef|extern\s+\"C\")\b")


def function_name(head: str):
    """Qualified name of a definition head (`void A::B::f(int x) const`), or None if not a function."""
    head = re.sub(r"//[^\n]*|/\*.*?\*/", " ", head, flags=re.S)
    if HEAD_SKIP.match(head) or "(" not in head or re.search(r"=\s*$", head.strip()):
        return None
    if re.search(r"\)\s*:", head):  # constructor initializer list
        head = head[: re.search(r"\)\s*:", head).start() + 1]
    m = re.search(r"((?:[A-Za-z_]\w*\s*::\s*)*~?[A-Za-z_]\w*|operator\s*\S+)\s*\(", head)
    return re.sub(r"\s+", "", m.group(1)) if m else None


def unit_module(src: str):
    for module, path in delinks_files():
        for unit in parse_units(path):
            if unit["file"] == src:
                return module, unit
    raise SystemExit(f"{src} not in any delinks.txt")


def object_functions(obj: Path):
    """[(section index, [mangled names])] in section order, plus demangled base names."""
    with obj.open("rb") as f:
        elf = ELFFile(f)
        by_sec = {}
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if s["st_info"]["type"] == "STT_FUNC" and isinstance(s["st_shndx"], int) and not s.name.startswith("$"):
                by_sec.setdefault(s["st_shndx"], []).append((s.name, s["st_info"]["bind"]))
    names = sorted({n for v in by_sec.values() for n, _ in v})
    dem = subprocess.run(["arm-none-eabi-c++filt"], input="\n".join(names), capture_output=True, text=True).stdout
    demangled = dict(zip(names, dem.splitlines()))
    return [(idx, v) for idx, v in sorted(by_sec.items())], demangled


def base_name(demangled: str):
    d = demangled.split("(")[0]
    return re.sub(r"\s+", "", d)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source")
    ap.add_argument("--write", action="store_true")
    args = ap.parse_args()
    src = args.source
    module, unit = unit_module(src)
    syms = load_symbols(module)
    obj = BUILD / Path(src).with_suffix(".o")
    text = (ROOT / src).read_text()
    parts = chunks(text)

    # Map definition chunks to object symbols.
    funcs, demangled = object_functions(obj)
    pool = {}  # base name -> list of (address or None, weak?) per definition, in object order
    weak_only = []
    # One definition of a constructor/destructor emits several variants (C1/C2, D0/D1/D2), each in its own
    # section and usually adjacent: merge adjacent sections whose names differ only in the variant.
    variant = re.compile(r"(?<=[A-Za-z0-9])([CD])[0-3](?=E)")
    merged = []
    for _, names in funcs:
        weak = all(b != "STB_GLOBAL" and b != "STB_LOCAL" for _, b in names)
        key = (variant.sub(r"\1X", names[0][0]), weak)
        prev = next((m for m in merged if m[0] == key), None) if variant.search(names[0][0]) else None
        if prev:
            prev[1].extend(names)
        else:
            merged.append((key, list(names)))
    for _, names in merged:
        addr = min((syms[n] for n, _ in names if n in syms), default=None)
        weak = all(b != "STB_GLOBAL" and b != "STB_LOCAL" for _, b in names)
        base = base_name(demangled[names[0][0]])
        pool.setdefault(base, []).append((addr, weak, [n for n, _ in names]))
    defs = []
    for i, (s, e, brace) in enumerate(parts):
        if brace is None:
            continue
        name = function_name(text[s:brace])
        if not name:
            continue
        # Match the definition's (possibly partly qualified) name to an object symbol.
        cands = [b for b in pool if b == name or b.endswith("::" + name)]
        cands = [b for b in cands if any(not w for _, w, _ in pool[b])]
        if len(cands) != 1:
            print(f"warning: can't place {name} ({len(cands)} candidates)", file=sys.stderr)
            continue
        entries = pool[cands[0]]
        k = next(j for j, (_, w, _) in enumerate(entries) if not w)
        addr, _, mangled = entries.pop(k)
        defs.append((i, name, addr, mangled))

    leftovers = [(b, a, m) for b, v in pool.items() for a, w, m in v]
    lo, hi = unit["ranges"].get(".text", (0, 0))
    for b, a, m in leftovers:
        if a is not None and lo <= a < hi:
            print(f"no definition here for {b} at {a:#x} ({', '.join(m)}): inline/implicit, move by hand",
                  file=sys.stderr)

    missing = [d for d in defs if d[2] is None]
    for d in missing:
        print(f"warning: {d[1]} has no address in symbols.txt; it keeps its relative place", file=sys.stderr)
    # Sort: known addresses ascending (descending for a compiler that emits in reverse); unknown ones stay glued
    # after their predecessor.
    rev = emits_reversed(src)
    keyed = []
    last = -1
    for d in defs:
        last = d[2] if d[2] is not None else last + (-0.001 if rev else 0.001)
        keyed.append((last, d))
    order = [d for _, d in sorted(keyed, key=lambda x: x[0], reverse=rev)]
    if [d[0] for d in order] == [d[0] for d in defs]:
        print("already in the emitted order")
        return

    def with_comment(i):
        """Chunk i split into the part that stays (blank lines, preprocessor lines, unrelated comments) and the
        part that moves (the comment block directly above the definition, and the definition)."""
        s, e, _ = parts[i]
        lines = text[s:e].split("\n")
        head = next(j for j, ln in enumerate(lines)
                    if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
        top = head
        while top > 0 and lines[top - 1].strip().startswith("//"):
            top -= 1
        return "\n".join(lines[:top]) + ("\n" if top else ""), "\n".join(lines[top:])

    slots = [d[0] for d in defs]
    moving = {d[0]: with_comment(d[0]) for d in defs}
    new_chunks = {}
    for slot, d in zip(slots, order):
        stay, _ = moving[slot]
        _, move = moving[d[0]]
        new_chunks[slot] = stay + move
    out = []
    for i, (s, e, _) in enumerate(parts):
        out.append(new_chunks.get(i, text[s:e]))
    new = "".join(out)
    print("new order: " + ", ".join(f"{d[1]}@{d[2]:#x}" if d[2] else d[1] for d in order))
    if args.write:
        (ROOT / src).write_text(new)




def fix_declarations(src: str, max_rounds: int = 60):
    """Compiles `src` and, for each `undefined identifier 'X'`, moves the top-level chunk that declares X above
    the first function definition (or, when X is a function defined later in the file, adds a prototype there).
    Data definitions moved this way are reported, since their order can matter for the data sections."""
    obj = str((BUILD / Path(src).with_suffix(".o")).relative_to(ROOT))
    moved = []
    for _ in range(max_rounds):
        r = subprocess.run(["ninja", obj], capture_output=True, text=True, cwd=ROOT)
        if r.returncode == 0:
            return moved
        out = r.stdout + r.stderr
        m = re.search(r"undefined identifier '([^']+)'", out)
        if not m:
            print(out[-2000:], file=sys.stderr)
            raise SystemExit(f"{src}: compile error the fixer doesn't handle")
        ident = m.group(1)
        text = (ROOT / src).read_text()
        parts = chunks(text)
        first_func = next(i for i, (s, e, b) in enumerate(parts) if b is not None and function_name(text[s:b]))
        word = re.compile(r"(?<![\w:])" + re.escape(ident) + r"\s*(\(|\[|;|=|,|\)|\{|:|$)")
        target = None
        for i, (s, e, b) in enumerate(parts):
            if i <= first_func:
                continue
            head = text[s:b] if b is not None else text[s:e]
            if b is not None and function_name(head) not in (None, ident):
                continue
            if word.search(re.sub(r"//[^\n]*", "", head)):
                target = i
                break
        if target is None:
            # A type defined after a declaration that uses it (one moved up earlier): move the type definition
            # above the chunk with the error.
            line = int(re.search(r"\.c(?:pp)?:(\d+):", out).group(1))
            err_pos = sum(len(ln) + 1 for ln in text.split("\n")[: line - 1])
            tdef = re.compile(r"^\s*(?:struct|class|union|enum)\s+" + re.escape(ident) + r"\b|typedef\b.*\b"
                              + re.escape(ident) + r"\s*;", re.M)
            j = next((i for i, (s, e, b) in enumerate(parts) if s > err_pos and tdef.search(text[s:e])), None)
            if j is None:
                raise SystemExit(f"{src}: can't find a declaration of {ident}")
            s, e, _ = parts[j]
            lines = text[s:e].split("\n")
            head_i = next(k for k, ln in enumerate(lines)
                          if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
            body = "\n".join(lines[head_i:]).strip() + "\n"
            text = text[:s] + "\n".join(lines[:head_i]) + ("\n" if head_i else "") + text[e:]
            ci = next(i for i, (s, e, b) in enumerate(chunks(text)) if s <= err_pos < e)
            cs, ce, _ = chunks(text)[ci]
            clines = text[cs:ce].split("\n")
            ch = next(k for k, ln in enumerate(clines)
                      if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
            at = cs + sum(len(ln) + 1 for ln in clines[:ch])
            text = text[:at] + body + "\n" + text[at:]
            (ROOT / src).write_text(text)
            moved.append(("moved type", body.split("\n")[0]))
            continue
        s, e, b = parts[target]
        lines = text[s:e].split("\n")
        head_i = next(j for j, ln in enumerate(lines)
                      if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
        is_func = b is not None and function_name(text[s:b]) is not None
        if is_func:  # a function defined later: prototype it
            proto = re.sub(r"\s*$", "", text[s:b].split("\n", head_i)[-1] if head_i else text[s:b]).strip()
            proto = re.sub(r"//[^\n]*\n", "", proto).strip()
            insert = proto + ";\n"
            kind = "prototype"
        else:
            insert = "\n".join(lines[head_i:]).strip() + "\n"
            text = text[:s] + "\n".join(lines[:head_i]) + ("\n" if head_i else "") + text[e:]
            kind = "moved"
            parts = chunks(text)
        # insert right above the first definition (after any includes/comments that start its chunk)
        fs, fe, _ = parts[first_func]
        flines = text[fs:fe].split("\n")
        fh = next(j for j, ln in enumerate(flines)
                  if ln.strip() and not ln.strip().startswith(("//", "/*", "*", "#")))
        while fh > 0 and flines[fh - 1].strip().startswith("//"):
            fh -= 1
        at = fs + sum(len(ln) + 1 for ln in flines[:fh])
        text = text[:at] + insert + "\n" + text[at:]
        (ROOT / src).write_text(text)
        moved.append((kind, insert.strip().split("\n")[0]))
    raise SystemExit(f"{src}: gave up after {max_rounds} rounds")


if __name__ == "__main__":
    if len(sys.argv) > 2 and sys.argv[1] == "--fix-decls":
        for f in sys.argv[2:]:
            for kind, what in fix_declarations(f):
                print(f"{f}: {kind}: {what}")
    else:
        main()
