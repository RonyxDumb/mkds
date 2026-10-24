#!/usr/bin/env python3
"""Renames symbols in config/<ver>/arm9/**/symbols.txt to the names used by compiled source.

Source refers to other code by its real name (mangled, in C++ code), but symbols.txt starts out with
address-based names. Once a function matches, every relocation in its compiled object sits exactly where
the original has a branch or literal, so the referenced address can be read from the ROM. This tool:

  1. finds each compiled function in the module by exact (relocation-masked) byte match,
  2. renames the function's own symbol to the compiled name,
  3. for every relocation against a named symbol, reads the target address from the original code and
     renames the symbol at that address.

Existing non-address names are never overwritten, and a name that already belongs to another symbol (in any
module) is never given out a second time; both are reported as conflicts. Dry run unless --write.

  sync_symbols.py build/<ver>/src/Main/Some/Unit.o ov001 [--write]
"""
import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from probe_compilers import ROOT, module_bytes, thumb_branch_target  # noqa: E402

from elftools.elf.elffile import ELFFile  # noqa: E402
from elftools.elf.relocation import RelocationSection  # noqa: E402
from project import PLACEHOLDER, VERSION, main_end, module_base, tcm_module  # noqa: E402  (tools/project.py)

CFG = ROOT / f"config/{VERSION}/arm9"
LINE = re.compile(r"^(\S+) (kind:\S+) addr:(0x[0-9a-f]+)(.*)$")
FORCE = False  # set by --force: replace existing non-address names (after a signature change in a header)
ADDRESS_NAME = PLACEHOLDER  # func_/data_ placeholders, tagged with a version or not (tools/project.py)


def symbols_path(module: str) -> Path:
    if module == "main":
        return CFG / "symbols.txt"
    if module in ("itcm", "dtcm"):
        return CFG / module / "symbols.txt"
    return CFG / "overlays" / module / "symbols.txt"


def module_of(addr: int, current: str) -> str:
    if tcm := tcm_module(addr):
        return tcm
    if module_base("main") <= addr < main_end():
        return "main"
    return current  # overlay space is shared; assume the module being synced


LOADED: dict[str, "Symbols"] = {}  # module -> its symbols.txt, as edited so far in this run


def all_modules() -> list[str]:
    mods = ["main"] + [m for m in ("itcm", "dtcm") if (CFG / m / "symbols.txt").is_file()]
    return mods + sorted(p.parent.name for p in (CFG / "overlays").glob("*/symbols.txt"))


def name_taken(name: str, module: str, addr: int):
    """Where `name` already names a symbol other than the one at `addr` in `module` (every module is checked:
    overlays share one address space and one link), or None."""
    for mod in all_modules():
        lines = LOADED[mod].lines if mod in LOADED else symbols_path(mod).read_text().splitlines()
        for line in lines:
            if line.startswith(name + " ") and (m := LINE.match(line)):
                where = int(m.group(3), 16)
                if (mod, where) != (module, addr):
                    return f"{mod} {where:#010x}"
    return None


class Symbols:
    def __init__(self, module: str):
        LOADED[module] = self
        self.module = module
        self.path = symbols_path(module)
        self.lines = self.path.read_text().splitlines()
        self.by_addr: dict[int, list[int]] = {}
        for i, line in enumerate(self.lines):
            if m := LINE.match(line):
                self.by_addr.setdefault(int(m.group(3), 16), []).append(i)
        self.changed = False
        self.retarget: list[tuple[int, int]] = []

    def address_of(self, name: str):
        for line in self.lines:
            if line.startswith(name + " ") and (m := LINE.match(line)):
                return int(m.group(3), 16)
        return None

    def functions(self):
        for line in self.lines:
            if (m := LINE.match(line)) and m.group(2).startswith("kind:function"):
                size = int(re.search(r"size=(0x[0-9a-f]+)", m.group(2)).group(1), 16)
                yield m.group(1), int(m.group(3), 16), size

    def rename(self, addr: int, new: str, want_function: bool | None) -> str:
        """want_function: True/False to require a kind, None to take whichever symbol is there."""
        for i in self.by_addr.get(addr, []):
            m = LINE.match(self.lines[i])
            name, kind = m.group(1), m.group(2)
            if name.startswith(".L") or (want_function is not None and kind.startswith("kind:function") != want_function):
                continue
            if name == new:
                return "ok"
            if not ADDRESS_NAME.match(name) and not FORCE:
                return f"CONFLICT: {addr:#010x} is already '{name}', source says '{new}' (use --force to rename)"
            if other := name_taken(new, self.module, addr):
                return f"CONFLICT: '{new}' already names the symbol at {other}; rename that one first"
            self.lines[i] = f"{new} {kind} addr:{m.group(3)}{m.group(4)}"
            self.changed = True
            return f"rename {name} -> {new}"
        return f"MISSING: no symbol at {addr:#010x} for '{new}'"

    def insert_vtable(self, addr: int, new: str, interior: int) -> str:
        """C++ vtable symbols start 8 bytes before the address code uses; dsd only knows the latter."""
        if addr in self.by_addr:
            return self.rename(addr, new, None)
        idx = None
        for i in self.by_addr.get(interior, []):
            m = LINE.match(self.lines[i])
            if not m.group(2).startswith("kind:function") and ADDRESS_NAME.match(m.group(1)):
                idx = i
        if idx is None:
            return f"MISSING: no data symbol at {interior:#010x} to anchor vtable '{new}'"
        if other := name_taken(new, self.module, addr):
            return f"CONFLICT: '{new}' already names the symbol at {other}; rename that one first"
        kind = LINE.match(self.lines[idx]).group(2)
        self.lines[idx] = f"{new} {kind} addr:{addr:#010x}"
        self.changed = True
        self.retarget.append((interior, addr))
        return f"vtable {new} placed at {addr:#010x} (replaces interior symbol at {interior:#010x})"

    def mark_weak(self, addr: int, name: str):
        for i in self.by_addr.get(addr, []):
            line = self.lines[i]
            if line.startswith(name + " ") and not line.endswith(" weak"):
                self.lines[i] = line + " weak"
                self.changed = True

    def save(self):
        if self.changed:
            self.path.write_text("\n".join(self.lines) + "\n")


def tu_text_range(obj: Path, module: str):
    """Finds the .text range of the delinks.txt entry that produces obj (build/<ver>/<source>.o)."""
    parts = obj.with_suffix("").parts
    if "build" not in parts:
        return None
    rel = Path(*parts[parts.index("build") + 2:])
    delinks = symbols_path(module).with_name("delinks.txt")
    entry = None
    for line in delinks.read_text().splitlines():
        if line and not line[0].isspace() and line.rstrip().endswith(":"):
            entry = Path(line.rstrip()[:-1]).with_suffix("")
        elif entry == rel and (m := re.match(r"\s+\.text\s+start:(0x[0-9a-f]+) end:(0x[0-9a-f]+)", line)):
            return int(m.group(1), 16), int(m.group(2), 16)
    return None


def reloc_targets(field: str, module: str) -> bool:
    """True if a relocs.txt `module:` field names exactly `module` (main, itcm, dtcm or ovNNN)."""
    if module.startswith("ov"):
        return field == f"overlay({int(module[2:])})"
    return field == module


def retarget_relocs(interior: int, start: int, module: str) -> int:
    """Points relocations at `interior` in `module` to `start` with an addend instead, in every module's relocs.txt.

    Overlays share one address range, so only relocations whose `module:` field names `module` are touched.
    """
    pattern = re.compile(rf"to:{interior:#010x}(?: add:(0x[0-9a-f]+))? module:(\S+)")
    count = 0

    def fix(m: re.Match) -> str:
        nonlocal count
        if not reloc_targets(m.group(2), module):
            return m.group(0)
        count += 1
        add = int(m.group(1), 16) if m.group(1) else 0
        return f"to:{start:#010x} add:{add + interior - start:#x} module:{m.group(2)}"

    for path in CFG.rglob("relocs.txt"):
        text = path.read_text()
        new = pattern.sub(fix, text)
        if new != text:
            path.write_text(new)
    return count


def branch_target(word: int, pc: int) -> int:
    off = word & 0xFFFFFF
    if off & 0x800000:
        off -= 1 << 24
    target = pc + 8 + off * 4
    if (word >> 28) == 0xF:  # blx imm: H bit adds 2
        target += ((word >> 24) & 1) * 2
    return target


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("obj", type=Path)
    ap.add_argument("module")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--assume-embedded", action="store_true",
                    help="also assume every function whose name embeds its address (func_<addr>, func_ovNNN_<addr>) "
                         "lives at that address")
    ap.add_argument("--assume", action="append", default=[], metavar="NAME=ADDR",
                    help="place a non-matching function at ADDR, or pick ADDR among identical candidates. With the same size its "
                         "relocations are read too (only safe when the mismatch doesn't shift code); with a "
                         "different size only the function is renamed")
    ap.add_argument("--force", action="store_true",
                    help="rename symbols that already have a non-address name (review the dry run first)")
    a = ap.parse_args()
    global FORCE
    FORCE = a.force

    base, blob = module_bytes(a.module)
    tables = LOADED
    Symbols(a.module)

    def table(mod):
        if mod not in tables:
            Symbols(mod)
        return tables[mod]

    with open(a.obj, "rb") as fh:
        elf = ELFFile(fh)
        symtab = elf.get_section_by_name(".symtab")
        relocs: dict[int, list] = {}
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                relocs.setdefault(sec["sh_info"], []).extend(sec.iter_relocations())

        rom_funcs = list(tables[a.module].functions())
        report = []
        # In C++ code mwcc emits identical base-object (C2/D2) and complete-object (C1/D1) structors; a ROM keeps one
        # copy, referenced under the complete-object name.
        names = {s.name for s in symtab.iter_symbols()}
        for sym in symtab.iter_symbols():
            if sym["st_info"]["type"] != "STT_FUNC" or not isinstance(sym["st_shndx"], int) or sym["st_size"] == 0:
                continue
            if re.search(r"[CD]2E", sym.name) and re.sub(r"([CD])2E", r"\g<1>1E", sym.name) in names:
                continue
            data = elf.get_section(sym["st_shndx"]).data()
            value, size = sym["st_value"] & ~1, sym["st_size"]
            code = data[value:value + size]
            rels = [r for r in relocs.get(sym["st_shndx"], []) if value <= r["r_offset"] < value + size]
            # Per byte: a Thumb bl pair can straddle a word boundary.
            mask = {r["r_offset"] - value + k for r in rels for k in range(4)}
            hits = []
            for _, addr, rsize in rom_funcs:
                if rsize != size:
                    continue
                orig = blob[addr - base: addr - base + size]
                if all(i in mask or code[i] == orig[i] for i in range(size)):
                    hits.append(addr)
            assumed = {n: int(v, 16) for n, v in (x.split("=") for x in a.assume)}
            if a.assume_embedded and sym.name not in assumed:
                if (m := PLACEHOLDER.match(sym.name)) and m.group(1) == "func":
                    assumed[sym.name] = int(m.group(4), 16)
            only_name = False
            if sym.name in assumed:
                want = assumed[sym.name]
                if want in hits:
                    hits = [want]  # several identical candidates (e.g. thunks): take the one given
                elif not hits and any(addr == want for _, addr, _ in rom_funcs):
                    hits = [want]
                    # The code differs, so its literal pool may be laid out differently even at the same size:
                    # rename the function only and leave the symbols it references alone.
                    only_name = True
                    report.append(f"{sym.name}: assumed at {want:#010x} (not an exact match: relocations not read)")
            if len(hits) > 1 and (rng := tu_text_range(a.obj, a.module)):
                hits = [h for h in hits if rng[0] <= h < rng[1]]
            if len(hits) > 1:
                # Identical code (e.g. this-adjusting thunks): keep the candidates whose branches go where the
                # source's call targets are already known to be. A second run resolves thunks of new names.
                def branches_agree(cand: int) -> bool:
                    for r in rels:
                        if r["r_info_type"] not in (1, 10, 28, 29):
                            continue
                        name = symtab.get_symbol(r["r_info_sym"]).name
                        known = tables[a.module].address_of(name)
                        if known is None:
                            known = table("main").address_of(name)
                        if known is None:
                            continue
                        off = r["r_offset"] - value
                        if r["r_info_type"] == 10:  # Thumb bl/blx pair
                            got = thumb_branch_target(blob, cand - base + off, cand + off)
                        else:
                            off &= ~3
                            got = branch_target(struct.unpack_from("<I", blob, cand - base + off)[0], cand + off)
                        if got != known & ~1:
                            return False
                    return True
                hits = [h for h in hits if branches_agree(h)] or hits
            if len(hits) != 1:
                report.append(f"{sym.name}: {'no' if not hits else 'ambiguous'} match in {a.module}, skipped")
                continue
            addr = hits[0]
            report.append(f"{sym.name} @ {addr:#010x}: {tables[a.module].rename(addr, sym.name, True)}")
            for r in ([] if only_name else rels):
                target_sym = symtab.get_symbol(r["r_info_sym"])
                name = target_sym.name
                if not name or target_sym["st_info"]["type"] == "STT_SECTION" or name.startswith(("@", "$")):
                    continue  # file-local data, handled by the translation unit itself
                off = r["r_offset"] - value
                rtype = r["r_info_type"]
                if rtype == 2:  # R_ARM_ABS32
                    target = struct.unpack_from("<I", blob, addr - base + off)[0] - r["r_addend"]
                    is_func = None
                    if target & 1:  # a Thumb function pointer carries the Thumb bit; its symbol is at the even address
                        mod = module_of(target & ~1, a.module)
                        if any(fa == target & ~1 for _, fa, _ in table(mod).functions()):
                            target, is_func = target & ~1, True
                elif rtype in (1, 28, 29):  # PC24 / CALL / JUMP24
                    off &= ~3
                    target = branch_target(struct.unpack_from("<I", blob, addr - base + off)[0], addr + off)
                    is_func = True
                elif rtype == 10:  # R_ARM_THM_CALL: Thumb bl/blx pair
                    target = thumb_branch_target(blob, addr - base + off, addr + off)
                    is_func = True
                else:
                    continue
                mod = module_of(target, a.module)
                if name.startswith("_ZTV") and r["r_addend"] == 8 and target_sym["st_shndx"] == "SHN_UNDEF":
                    report.append(f"  -> {name} @ {target:#010x} [{mod}]: "
                                  f"{table(mod).insert_vtable(target, name, target + 8)}")
                    continue
                multidef = target_sym["st_info"]["bind"] not in ("STB_LOCAL", "STB_GLOBAL", "STB_WEAK")
                if target_sym["st_shndx"] != "SHN_UNDEF" and mod == a.module and not multidef:
                    continue  # defined in this object; covered by its own entry
                report.append(f"  -> {name} @ {target:#010x} [{mod}]: {table(mod).rename(target, name, is_func)}")
                if multidef:  # inline-function statics: keep the original copy (see tools/delink_multidef.py)
                    table(mod).mark_weak(target, name)

    print("\n".join(report))
    if a.write:
        for t in tables.values():
            t.save()
            for interior, start in t.retarget:
                print(f"relocations retargeted for {interior:#010x}: {retarget_relocs(interior, start, t.module)}")
        print("symbols.txt updated" if any(t.changed for t in tables.values()) else "no changes")
    else:
        print("(dry run; pass --write to apply)")


if __name__ == "__main__":
    main()
