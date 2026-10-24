#!/usr/bin/env python3
"""Brings symbols.txt entries inside complete units in line with the linked binary, for `dsd check symbols`.

A unit marked `complete` is linked from its compiled object, so its symbols are the compiler's: named statics,
vtables, `@N` for string literals and other anonymous objects, weak inline functions. `dsd check symbols` looks
every symbols.txt entry up by address and name and compares local/weak flags, so after marking a unit complete run

  ninja && python3 tools/sync_linked_symbols.py [--write] && ninja

For each entry in a complete unit:
  - a name the check already accepts at that address is kept (`@N` matches any `@M`, `x$N` any `x$M`, as in dsd's
    check, so a renumbering after a source edit needs no resync); otherwise it is renamed to the linked name (a
    function only when its old name is nowhere in the linked binary, e.g. a C1 constructor the source emits as C2);
  - an address the linked binary has no symbol for, inside a linked object (e.g. dsd's vtable symbol 8 bytes in),
    is folded into that object and the relocations to it get an addend;
For every entry in a complete unit, functions too, the local/weak flags follow the linked symbol.

dsd delink refuses a relocation from one unit to a local symbol of another, so an entry is never made local while
a relocation from outside its unit targets it; those are listed as kept global (the check then reports them).
"""
import argparse
import re
from pathlib import Path

from elftools.elf.elffile import ELFFile

from link_check import CFG, delinks_files, parse_units
from sync_symbols import reloc_targets, retarget_relocs
from project import VERSION  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
LINE = re.compile(r"^(\S+) (kind:\S+) addr:(0x[0-9a-f]+)(.*)$")
RELOC = re.compile(r"^from:(0x[0-9a-f]+) kind:\S+ to:(0x[0-9a-f]+)(?: add:\S+)? module:(\S+)")
SECTION_OF = {"main": "ARM9", "itcm": "ITCM", "dtcm": "DTCM"}
STB_MW_WEAK = 14  # mwldarm's binding for weak definitions (what dsd's check reads as weak)


def symbols_path(module):
    if module == "main":
        return CFG / "symbols.txt"
    if module in ("itcm", "dtcm"):
        return CFG / module / "symbols.txt"
    return CFG / "overlays" / module / "symbols.txt"


def relocs_path(module):
    return symbols_path(module).with_name("relocs.txt")


def fuzzy_match(a: str, b: str) -> bool:
    """dsd check symbols' name comparison."""
    if a == b or (a.startswith("@") and b.startswith("@")):
        return True
    if "$" in a and "$" in b:
        return a.split("$", 1)[0] == b.split("$", 1)[0]
    return False


def scope_of(bind) -> str:
    if bind == "STB_LOCAL":
        return "local"
    if bind == "STB_GLOBAL":
        return "global"
    return "weak"  # pyelftools reports mwldarm's binding 14 as a number


def set_scope(attrs: str, scope: str) -> str:
    attrs = re.sub(r"\s*\b(local|weak)\b", "", attrs)
    return attrs + ("" if scope == "global" else f" {scope}")


def current_scope(attrs: str) -> str:
    return "local" if re.search(r"\blocal\b", attrs) else "weak" if re.search(r"\bweak\b", attrs) else "global"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--elf", default=f"build/{VERSION}/arm9.o")
    args = ap.parse_args()

    modules = list(delinks_files())
    with open(ROOT / args.elf, "rb") as fh:
        elf = ELFFile(fh)
        secname = {i: s.name for i, s in enumerate(elf.iter_sections())}
        at: dict[tuple[str, int], list] = {}
        addrs_of: dict[str, set] = {}
        spans = []
        ends: dict[tuple[str, int], int] = {}
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if not isinstance(s["st_shndx"], int) or not s.name or s.name.startswith(("$", ".")):
                continue
            if s["st_info"]["type"] not in ("STT_OBJECT", "STT_NOTYPE", "STT_FUNC"):
                continue
            mod = secname[s["st_shndx"]]
            addrs_of.setdefault(s.name, set()).add(s["st_value"])
            at.setdefault((mod, s["st_value"]), []).append((s.name, scope_of(s["st_info"]["bind"]), s["st_info"]["type"]))
            if s["st_size"] and s["st_info"]["type"] == "STT_OBJECT":
                spans.append((mod, s["st_value"], s["st_value"] + s["st_size"], s.name, scope_of(s["st_info"]["bind"])))
                ends[(mod, s["st_value"])] = max(ends.get((mod, s["st_value"]), 0), s["st_value"] + s["st_size"])

    # Who references each address: (target module, address) -> [(source module, from address)].
    refs: dict[tuple[str, int], list] = {}
    for module, _ in modules:
        for line in relocs_path(module).read_text().splitlines():
            if m := RELOC.match(line):
                for target, _ in modules:
                    if reloc_targets(m.group(3), target):
                        refs.setdefault((target, int(m.group(2), 16)), []).append((module, int(m.group(1), 16)))

    total = 0
    kept_global = []
    for module, delinks in modules:
        mod = SECTION_OF.get(module, module.upper())
        units = [u for u in parse_units(delinks) if u["complete"]]
        if not units:
            continue

        def unit_of(addr):
            return next((u for u in units if any(lo <= addr < hi for lo, hi in u["ranges"].values())), None)

        def outside_refs(addr, unit):
            # References into the object count too: folding an interior name points them at its start.
            end = ends.get((mod, addr), addr + 1)
            return [(m, f) for a in range(addr, end) for m, f in refs.get((module, a), [])
                    if m != module or not any(lo <= f < hi for lo, hi in unit["ranges"].values())]

        path = symbols_path(module)
        lines = path.read_text().splitlines()
        starts = {int(mm.group(3), 16) for ln in lines if (mm := LINE.match(ln))}
        names_here = {mm.group(1) for ln in lines if (mm := LINE.match(ln))}
        changed = 0
        for i, line in enumerate(lines):
            m = LINE.match(line)
            if not m:
                continue
            name, kind, addr, attrs = m.group(1), m.group(2), int(m.group(3), 16), m.group(4)
            unit = unit_of(addr)
            if unit is None or kind.startswith("kind:label"):
                continue
            is_func = kind.startswith("kind:function")
            cands = [c for c in at.get((mod, addr), []) if (c[2] == "STT_FUNC") == is_func or c[2] == "STT_NOTYPE"]
            same = next((c for c in cands if fuzzy_match(c[0], name)), None)
            if same is None and is_func and (name in addrs_of or len(cands) != 1):
                if cands:
                    print(f"{module}: function {name} at {addr:#x} is {cands[0][0]} in the linked binary (not renamed)")
                continue
            if same is None and addr in addrs_of.get(name, ()):
                # Defined at this address under another section (linker-script symbols); not a naming problem.
                print(f"{module}: {name} at {addr:#x} is in another section of the linked binary (not touched)")
                continue
            if same is None and not cands:
                inside = next(((n, lo, sc) for md, lo, hi, n, sc in spans if md == mod and lo < addr < hi), None)
                if inside is None:
                    print(f"{module}: {name} at {addr:#x}: nothing in the linked binary")
                    continue
                start = inside[1]
                if start in starts:
                    print(f"{module}: {name} at {addr:#x} is inside {inside[0]}: removed")
                    lines[i] = None
                else:
                    scope = inside[2]
                    if scope == "local" and outside_refs(start, unit_of(start) or unit):
                        scope = "global"
                    print(f"{module}: {name} at {addr:#x} is inside {inside[0]}: moved to its start")
                    lines[i] = f"{inside[0]} {kind} addr:{start:#010x}{set_scope(attrs, scope)}"
                    starts.add(start)
                changed += 1
                if args.write:
                    retarget_relocs(addr, start, module)
                continue
            if same is not None:
                new, scope = name, same[1]
            else:
                new, scope, _ = sorted(cands, key=lambda c: (c[1] == "local", c[0]))[0]
            if new != name and scope != "local" and new in names_here:
                print(f"{module}: {name} at {addr:#x} -> {new}: that name is already in symbols.txt (not renamed)")
                continue
            if scope == "local" and (out := outside_refs(addr, unit)):
                kept_global.append(f"{module}: {new} at {addr:#x} ({unit['file']}) is local but referenced from "
                                   + ", ".join(f"{m} {f:#x}" for m, f in out[:3]))
                scope = current_scope(attrs) if current_scope(attrs) != "local" else "global"
            new_attrs = set_scope(attrs, scope)
            if new == name and new_attrs == attrs:
                continue
            lines[i] = f"{new} {kind} addr:{m.group(3)}{new_attrs}"
            what = f"{name} -> {new}" if new != name else name
            print(f"{module}: {what} [{current_scope(attrs)} -> {scope}]")
            changed += 1
        if changed and args.write:
            path.write_text("\n".join(ln for ln in lines if ln is not None) + "\n")
        total += changed
    for k in kept_global:
        print(f"kept global: {k}")
    print(f"{total} changed" + ("" if args.write else " (dry run)") + f", {len(kept_global)} kept global")


if __name__ == "__main__":
    main()
