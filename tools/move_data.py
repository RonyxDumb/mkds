#!/usr/bin/env python3
"""Moves objects the original still provides into units' sources, and keeps a change only if the ROM still matches.

  move_data.py <unit source> <symbol> [<symbol> ...] [--type SYMBOL=TYPE] [--size SYMBOL=N] [--dry-run]
  move_data.py --plan <file> [--group N]

For each symbol (in the order given, which is the definition order): tools/data_init.py writes the definition
from the ROM (`const` for an object of .rodata, no initializer for one of .bss), and it goes into the unit after its
includes, with includes for the headers that declare what it points at. A string of .data that only this unit names,
once, becomes a literal (`"..."` or `L"..."`) where it is used, and its declaration goes. The symbol's `extern` declaration stays
where it is (made `const` for .rodata); moving declarations into the unit's header is a separate step. Then: data_ranges.py --write and link_check.py for the unit, `ninja` (ROM SHA-1),
sync_linked_symbols.py --write and `ninja check`. On a failure every file is put back and the reason is printed.

--plan reads lines `<unit source> <symbol> [<symbol> ...]`. Each unit is first checked on its own without a ROM build
(compile, data layout); the ones that pass move in groups of N units (default 16) with one build per group, and a group
that fails is halved until the unit that fails is found. With --commit each group that moves is committed (and
pushed to the refspecs given). Results go to stdout, one line per unit.
Run `ninja` first so the objects are current.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import CFG, delinks_files, parse_units  # noqa: E402
from rename_unit import header_of  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SYM = re.compile(r"^(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:(0x[0-9a-f]+)")


class Failed(Exception):
    pass


def run(*cmd):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)


def module_dir(module):
    return CFG if module == "main" else (CFG / module if module in ("itcm", "dtcm") else CFG / "overlays" / module)


def module_of(unit):
    for module, path in delinks_files():
        if any(u["file"] == unit for u in parse_units(path)):
            return module
    raise Failed(f"{unit} not in any delinks.txt")


def section_of(module, addr):
    head = (module_dir(module) / "delinks.txt").read_text().split("\n\n", 1)[0]
    for name, lo, hi in re.findall(r"^\s+(\.\w+)\s+start:(0x[0-9a-f]+) end:(0x[0-9a-f]+)", head, re.M):
        if int(lo, 16) <= addr < int(hi, 16):
            return name
    return None


def symbol_addr(module, name):
    for line in (module_dir(module) / "symbols.txt").read_text().splitlines():
        if (m := SYM.match(line)) and m.group(1) == name:
            return int(m.group(4), 16)
    raise Failed(f"{name}: not in {module}'s symbols.txt")


def find_extern(name):
    pat = re.compile(r"^\s*extern\s+.*\b" + re.escape(name) + r"\s*(\[[^\]]*\])*\s*;.*$")
    for h in list((ROOT / "include").rglob("*.h")) + list((ROOT / "libs").rglob("*.h")):
        lines = h.read_text().splitlines()
        for i, line in enumerate(lines):
            if pat.match(line):
                j = i  # a comment directly above belongs to the declaration
                while j > 0 and lines[j - 1].lstrip().startswith("//"):
                    j -= 1
                return h, j, i
    return None


def text_at(module, addr):
    """The C literal of the string at addr (plain or wide, `L"..."`), or None."""
    from probe_compilers import module_bytes  # noqa: E402
    base, blob = module_bytes(module)
    o = addr - base
    if o < 0 or o >= len(blob):
        return None
    end = blob.find(b"\0", o)
    raw = blob[o:end]
    if len(raw) >= 2 and all(32 <= c < 127 for c in raw):
        return c_literal(raw.decode(), "")
    chars, k = [], o
    while k + 1 < len(blob):
        c = blob[k] | blob[k + 1] << 8
        if c == 0:
            break
        if not 32 <= c < 127:
            return None
        chars.append(chr(c))
        k += 2
    return c_literal("".join(chars), "L") if len(chars) >= 2 else None


def c_literal(s, prefix):
    return prefix + '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def literal_use(unit, name):
    """True when the unit's source names `name` exactly once and no other source does."""
    word = re.compile(r"\b" + re.escape(name) + r"\b")
    if len(word.findall((ROOT / unit).read_text())) != 1:
        return False
    for p in list((ROOT / "src").rglob("*.c")) + list((ROOT / "libs").rglob("*.c")):
        if p != ROOT / unit and word.search(p.read_text()):
            return False
    return True


def definitions(unit, symbols, types=None, sizes=None):
    """Definitions for the symbols, in order; strings the unit uses once become literals at their use."""
    types, sizes = types or {}, sizes or {}
    module = module_of(unit)
    defs, moved, uses = [], [], []
    for name in symbols:
        addr = symbol_addr(module, name)
        section = section_of(module, addr)
        if section not in (".data", ".rodata", ".bss"):
            raise Failed(f"{name}: in {section}, not a data section")
        if section == ".data" and (lit := text_at(module, addr)) and literal_use(unit, name):
            moved.append((name, "literal", lit))
            continue
        cmd = ["python3", "tools/data_init.py", module, name] + ([types[name]] if name in types else [])
        if section == ".rodata":
            cmd.append("--const")
        if section == ".bss":
            cmd.append("--bss")
        if name in sizes:
            cmd += ["--size", sizes[name]]
        r = run(*cmd)
        if r.returncode:
            raise Failed(f"{name}: {(r.stdout + r.stderr).strip().splitlines()[-1]}")
        defs.append(r.stdout.strip())
        moved.append((name, section, None))
        for line in r.stderr.splitlines():
            if line.startswith("uses: "):
                for used in line[6:].split():
                    uses.append(used)
                    if used in symbols:
                        if symbols.index(used) > symbols.index(name):
                            raise Failed(f"{name} points at {used}, which is defined after it")
                    elif not find_extern(used) and not find_function_decl(used):
                        raise Failed(f"{name} points at {used}, which nothing declares")
    return defs, moved, uses


def find_function_decl(name):
    pat = re.compile(r"^[A-Za-z_][^;(]*\b" + re.escape(name) + r"\s*\(")
    for h in list((ROOT / "include").rglob("*.h")) + list((ROOT / "libs").rglob("*.h")):
        if any(pat.match(l) for l in h.read_text().splitlines()):
            return h
    return None


def header_declaring(name):
    found = find_extern(name)
    return found[0] if found else find_function_decl(name)


def include_name(h):
    parts = h.relative_to(ROOT).parts
    return "/".join(parts[parts.index("include") + 1:])


def apply(unit, defs, moved, uses=()):
    """Writes the definitions after the unit's includes, makes the declarations of .rodata objects const and includes
    the headers that declare what the definitions point at. The declarations stay where they are."""
    src = ROOT / unit
    s = src.read_text().splitlines()
    have = {l for l in s if l.startswith("#include")}
    extra = []
    for used in uses:
        h = header_declaring(used)
        line = f'#include "{include_name(h)}"' if h else None
        if line and line not in have and line not in extra:
            extra.append(line)
    last_inc = max((i for i, l in enumerate(s) if l.startswith("#include")), default=-1)
    s[last_inc + 1:last_inc + 1] = extra + ([""] + defs if defs else [])
    text = "\n".join(s) + "\n"
    for name, section, lit in moved:
        if section == "literal":
            text = re.sub(r"\b" + re.escape(name) + r"\b", lambda m: lit, text)
    src.write_text(text)
    for name, section, lit in moved:
        found = find_extern(name)
        if found and section == "literal":
            h, j, i = found
            lines = h.read_text().splitlines()
            del lines[j:i + 1]
            h.write_text("\n".join(lines) + "\n")
            continue
        if not found or section != ".rodata":
            continue
        h, j, i = found
        lines = h.read_text().splitlines()
        if "const" not in lines[i].split(name)[0]:
            lines[i] = re.sub(r"^(\s*extern\s+)", r"\1const ", lines[i])
            h.write_text("\n".join(lines) + "\n")


CALL = re.compile(r"\b([A-Za-z_]\w*)\s*\(")


def split_args(text, start):
    """The arguments of the call whose '(' is at text[start]; returns ([(begin, end)], end index)."""
    depth, args, begin = 0, [], start + 1
    for k in range(start, len(text)):
        c = text[k]
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= 1
            if depth == 0:
                args.append((begin, k))
                return args, k
        elif c == "," and depth == 1:
            args.append((begin, k))
            begin = k + 1
    return args, len(text)


def make_param_const(func, index):
    """Adds const to parameter `index` of every declaration and definition of func. Returns the files changed."""
    pat = re.compile(r"^([A-Za-z_][\w\s\*]*?\b" + re.escape(func) + r")\s*\(")
    changed = []
    for f in [p for d in ("src", "include", "libs") for p in (ROOT / d).rglob("*") if p.suffix in (".c", ".h")]:
        text = f.read_text()
        out, pos, hit = [], 0, False
        for m in re.finditer(r"(?m)^[A-Za-z_][^;{}\n]*?\b" + re.escape(func) + r"\s*\(", text):
            if text[m.start():m.end()].lstrip().startswith(("return", "if", "else")):
                continue
            args, end = split_args(text, m.end() - 1)
            if index >= len(args):
                continue
            b, e = args[index]
            param = text[b:e]
            if "const" in param or "*" not in param:
                continue
            new = re.sub(r"^(\s*)", r"\1const ", param, count=1)
            out.append(text[pos:b] + new)
            pos, hit = e, True
        if hit:
            out.append(text[pos:])
            f.write_text("".join(out))
            changed.append(f)
    return changed


def fix_const_errors(errors):
    """errors: (file, line) of `illegal implicit conversion from 'const ...'`. Finds the innermost call with an
    argument on that line and makes the parameters there const. Returns True when it changed something."""
    done = False
    for path, line in errors:
        f = ROOT / path
        lines = f.read_text().splitlines()
        first = max(0, line - 8)
        text = "\n".join(lines[first:line + 3])
        lo = sum(len(l) + 1 for l in lines[first:line - 1])
        hi = lo + len(lines[line - 1])
        best = None
        for m in CALL.finditer(text):
            func = m.group(1)
            if func in ("if", "while", "for", "switch", "return", "sizeof"):
                continue
            args, end = split_args(text, m.end() - 1)
            for k, (b, e) in enumerate(args):
                if b < hi and e > lo and (best is None or b >= best[2]):
                    best = (func, k, b, len(args))
        if not best:
            continue
        # the compiler names the statement's line, not the argument's: the argument on the line first, then the
        # call's other arguments
        func, k, _, n = best
        for index in [k] + [i for i in range(n) if i != k]:
            if make_param_const(func, index):
                done = True
                break
    return done

def snapshot():
    files = list((ROOT / "src").rglob("*.[ch]")) + list((ROOT / "include").rglob("*.h")) + \
        list((ROOT / "libs").rglob("*.[ch]")) + list(CFG.rglob("*.txt"))
    return {f: f.read_bytes() for f in files}


def restore(snap):
    for f, b in snap.items():
        if f.read_bytes() != b:
            f.write_bytes(b)


def verify(units):
    """data_ranges and link_check for each unit, then one ROM build and the symbol check. Raises Failed."""
    for unit in units:
        compile_with_const_fixes(unit)
    # other objects that include a changed header must still compile: the full build below covers them
    for unit in units:
        r = run("python3", "tools/data_ranges.py", unit, "--write")
        if r.returncode:
            raise Failed(f"{unit}: data_ranges: " + (r.stdout + r.stderr).strip().splitlines()[-1])
        r = run("python3", "tools/link_check.py", "--all", unit)
        if not re.search(r"^READY\s+" + re.escape(unit) + r"$", r.stdout, re.M):
            raise Failed(f"{unit}: link_check: " + r.stdout.strip().replace("\n", " | ")[:400])
    for attempt in range(6):
        r = run("ninja")
        if not r.returncode:
            break
        out = (r.stdout + r.stderr).splitlines()
        conv = [(m.group(1).replace("\\", "/"), int(m.group(2))) for l in out
                if "illegal implicit conversion from 'const" in l and (m := re.match(r"^(\S+?\.[ch]):(\d+):", l))]
        if not conv or not fix_const_errors(conv):
            raise Failed("build: " + " | ".join(out[-3:])[:400])
    else:
        raise Failed("build: const parameters still conflict")
    run("python3", "tools/sync_linked_symbols.py", "--write")
    r = run("ninja", "check")
    if r.returncode:
        raise Failed("check: " + " | ".join((r.stdout + r.stderr).strip().splitlines()[-3:])[:400])


def compile_with_const_fixes(unit):
    obj = f"build/{CFG.parent.name}/{Path(unit).with_suffix('.o')}"
    for attempt in range(6):
        r = run("ninja", obj)
        if not r.returncode:
            return
        out = (r.stdout + r.stderr).splitlines()
        conv = [(m.group(1).replace("\\", "/"), int(m.group(2))) for l in out
                if "illegal implicit conversion from 'const" in l and (m := re.match(r"^(\S+?\.[ch]):(\d+):", l))]
        if not conv or not fix_const_errors(conv):
            errs = [l for l in out if re.search(r"\.[ch]:\d+:", l)]
            raise Failed(f"{unit}: compile: " + " | ".join(errs[:3])[:400])
    raise Failed(f"{unit}: compile: const parameters still conflict")


def precheck(unit, symbols):
    """Applies one unit's move, compiles it and checks its data layout, then puts everything back: cheap (no ROM
    build). Returns None or the reason."""
    snap = snapshot()
    try:
        defs, moved, uses = definitions(unit, symbols)
        apply(unit, defs, moved, uses)
        compile_with_const_fixes(unit)
        r = run("python3", "tools/data_ranges.py", unit)
        if r.returncode or "differs" in r.stdout or "not placed" in r.stdout or "DIFFER" in r.stdout:
            lines = [l.strip() for l in r.stdout.splitlines() if "differs" in l or "not placed" in l or "DIFFER" in l]
            raise Failed(f"{unit}: data_ranges: " + "; ".join(lines[:2] or [(r.stdout + r.stderr).strip()[-200:]]))
        return None
    except Failed as e:
        return str(e)
    finally:
        restore(snap)


def move_group(items):
    """items: [(unit, symbols)]. Applies all, verifies once; returns None or the reason. Restores on failure."""
    snap = snapshot()
    try:
        for unit, symbols in items:
            defs, moved, uses = definitions(unit, symbols)
            apply(unit, defs, moved, uses)
        verify([u for u, _ in items])
        return None
    except Failed as e:
        restore(snap)
        run("ninja")
        return str(e)


def move_plan(items, group, commit=()):
    """Prechecks every item, then moves the ones that pass in groups, halving a group that fails."""
    ok = []
    for unit, symbols in items:
        why = precheck(unit, symbols)
        if why:
            print(f"FAILED {unit}: {why}", flush=True)
        else:
            ok.append((unit, symbols))
    run("ninja")

    def attempt(batch):
        why = move_group(batch)
        if why is None:
            for unit, symbols in batch:
                print(f"MOVED {unit} {' '.join(symbols)}", flush=True)
            if commit:
                run("git", "add", "-A", "src", "include", "libs", "config")
                run("git", "commit", "-q", "-m", f"Define the data of {len(batch)} unit(s) in their sources")
                for ref in commit:
                    run("git", "push", "-q", "origin", ref)
        elif len(batch) == 1:
            print(f"FAILED {batch[0][0]}: {why}", flush=True)
        else:
            attempt(batch[:len(batch) // 2])
            attempt(batch[len(batch) // 2:])

    for k in range(0, len(ok), group):
        attempt(ok[k:k + group])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit", nargs="?")
    ap.add_argument("symbols", nargs="*")
    ap.add_argument("--type", action="append", default=[])
    ap.add_argument("--size", action="append", default=[])
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--plan")
    ap.add_argument("--group", type=int, default=16)
    ap.add_argument("--commit", nargs="*", metavar="REFSPEC",
                    help="commit after each group that moves, and push these refspecs (e.g. HEAD:main)")
    a = ap.parse_args()
    if a.plan:
        items = []
        for line in Path(a.plan).read_text().splitlines():
            if line.strip() and not line.startswith("#"):
                unit, *symbols = line.split()
                items.append((unit, symbols))
        move_plan(items, a.group, a.commit or ())
        return
    types = dict(x.split("=", 1) for x in a.type)
    sizes = dict(x.split("=", 1) for x in a.size)
    try:
        defs, moved, uses = definitions(a.unit, a.symbols, types, sizes)
    except Failed as e:
        raise SystemExit(f"FAILED {a.unit}: {e}")
    if a.dry_run:
        print("\n".join(defs))
        return
    snap = snapshot()
    try:
        apply(a.unit, defs, moved, uses)
        verify([a.unit])
    except Failed as e:
        restore(snap)
        run("ninja")
        raise SystemExit(f"FAILED {a.unit}: {e}")
    print(f"MOVED {len(moved)} object(s) into {a.unit}")


if __name__ == "__main__":
    main()
