#!/usr/bin/env python3
"""Moves objects the original still provides into units' sources, and keeps a change only if the ROM still matches.

  move_data.py <unit source> <symbol> [<symbol> ...] [--type SYMBOL=TYPE] [--size SYMBOL=N] [--dry-run]
  move_data.py --plan <file> [--group N]

For each symbol (in the order given, which is the definition order): tools/data_init.py writes the definition
from the ROM (`const` for an object of .rodata, no initializer for one of .bss), and it goes into the unit after its
includes, with includes for the headers that declare what it points at. The symbol's `extern` declaration stays
where it is (made `const` for .rodata); moving declarations into the unit's header is a separate step. Then: data_ranges.py --write and link_check.py for the unit, `ninja` (ROM SHA-1),
sync_linked_symbols.py --write and `ninja check`. On a failure every file is put back and the reason is printed.

--plan reads lines `<unit source> <symbol> [<symbol> ...]` and moves them in groups of N units (default 8) with one
build per group; a group that fails is tried again one unit at a time. Results go to stdout, one line per unit.
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


def definitions(unit, symbols, types=None, sizes=None):
    types, sizes = types or {}, sizes or {}
    module = module_of(unit)
    defs, moved, uses = [], [], []
    for name in symbols:
        addr = symbol_addr(module, name)
        section = section_of(module, addr)
        if section not in (".data", ".rodata", ".bss"):
            raise Failed(f"{name}: in {section}, not a data section")
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
        moved.append((name, section))
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
    s[last_inc + 1:last_inc + 1] = extra + [""] + defs
    src.write_text("\n".join(s) + "\n")
    for name, section in moved:
        found = find_extern(name)
        if not found or section != ".rodata":
            continue
        h, j, i = found
        lines = h.read_text().splitlines()
        if "const" not in lines[i].split(name)[0]:
            lines[i] = re.sub(r"^(\s*extern\s+)", r"\1const ", lines[i])
            h.write_text("\n".join(lines) + "\n")


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
        obj = f"build/{CFG.parent.name}/{Path(unit).with_suffix('.o')}"
        r = run("ninja", obj)
        if r.returncode:
            errs = [l for l in (r.stdout + r.stderr).splitlines() if re.search(r"\.c:\d+:", l)]
            raise Failed(f"{unit}: compile: " + " | ".join(errs[:3])[:400])
    for unit in units:
        r = run("python3", "tools/data_ranges.py", unit, "--write")
        if r.returncode:
            raise Failed(f"{unit}: data_ranges: " + (r.stdout + r.stderr).strip().splitlines()[-1])
        r = run("python3", "tools/link_check.py", "--all", unit)
        if not re.search(r"^READY\s+" + re.escape(unit) + r"$", r.stdout, re.M):
            raise Failed(f"{unit}: link_check: " + r.stdout.strip().replace("\n", " | ")[:400])
    r = run("ninja")
    if r.returncode:
        raise Failed("build: " + " | ".join((r.stdout + r.stderr).strip().splitlines()[-3:])[:400])
    run("python3", "tools/sync_linked_symbols.py", "--write")
    r = run("ninja", "check")
    if r.returncode:
        raise Failed("check: " + " | ".join((r.stdout + r.stderr).strip().splitlines()[-3:])[:400])


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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit", nargs="?")
    ap.add_argument("symbols", nargs="*")
    ap.add_argument("--type", action="append", default=[])
    ap.add_argument("--size", action="append", default=[])
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--plan")
    ap.add_argument("--group", type=int, default=8)
    a = ap.parse_args()
    if a.plan:
        items = []
        for line in Path(a.plan).read_text().splitlines():
            if line.strip() and not line.startswith("#"):
                unit, *symbols = line.split()
                items.append((unit, symbols))
        for k in range(0, len(items), a.group):
            group = items[k:k + a.group]
            why = move_group(group) if len(group) > 1 else "single"
            if why is None:
                for unit, symbols in group:
                    print(f"MOVED {unit} {' '.join(symbols)}", flush=True)
                continue
            for item in group:
                why = move_group([item])
                print(f"MOVED {item[0]} {' '.join(item[1])}" if why is None else f"FAILED {item[0]}: {why}",
                      flush=True)
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
