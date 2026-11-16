#!/usr/bin/env python3
"""Prepends a FORCE_ACTIVE block to the dsd-generated LCF.

Main reaches overlays that share a load address through calls to that address, which dsd records as an
ambiguous relocation and links against only the first overlay there. With -dead, overlays whose entry nothing
else references get stripped to nothing. Keeping each overlay's entry function active restores the original
reachability.

The entry symbol is looked up by address in each overlay's symbols.txt, so
renaming it there is picked up automatically.

It also keeps the data symbols listed in <config-dir>/force_active.txt (one per line, `#` comments): objects the
original link kept although nothing references them, which -dead would otherwise strip from a unit linked from
source.

It also applies <config-dir>/lcf_edits.txt (one edit per line, `#` comments), for what dsd's per-unit ranges can't say:
  place <stub>.o <function> <unit>.o   the stub unit's line becomes OBJECT(<function>, <unit>.o): one function of a
                                       unit placed apart from the rest of it
  alias <symbol> <base> <offset>       defines <symbol> = <base> + <offset>, for names other units use for a point
                                       inside an object of a linked unit (a field of a singleton instance)
  inner <symbol> <size>                aliases every symbols.txt name inside <symbol>'s <size> bytes to <symbol> +
                                       offset (names of fields of a big global that other units still use)

(mwldarm's -force_active flag would be simpler but segfaults under wibo.)
"""
import argparse
import re
from pathlib import Path
from project import LCF_SYMBOLS  # noqa: E402  (tools/project.py)

parser = argparse.ArgumentParser()
parser.add_argument("lcf_in", type=Path)
parser.add_argument("lcf_out", type=Path)
parser.add_argument("--config-dir", type=Path, required=True, help="config/<ver>/arm9")
args = parser.parse_args()

TEXT_START = re.compile(r"^\s*\.text\s+start:(0x[0-9a-fA-F]+)")
SYMBOL = re.compile(r"^(\S+)\s+kind:function\S*\s+addr:(0x[0-9a-fA-F]+)")

entries: list[str] = []
ov_root = args.config_dir / "overlays"
for ov_dir in sorted(ov_root.iterdir()) if ov_root.is_dir() else ():  # a game may have no overlays
    base = None
    for line in (ov_dir / "delinks.txt").read_text().splitlines():
        if m := TEXT_START.match(line):
            base = int(m.group(1), 16)
            break
    if base is None:  # an overlay without code (only .bss) has no entry function to keep
        continue
    for line in (ov_dir / "symbols.txt").read_text().splitlines():
        if (m := SYMBOL.match(line)) and int(m.group(2), 16) == base:
            entries.append(m.group(1))
            break
    else:
        raise SystemExit(f"{ov_dir}: no function symbol at overlay base {base:#010x}")

extra = args.config_dir / "force_active.txt"
if extra.exists():
    for line in extra.read_text().splitlines():
        name = line.split("#", 1)[0].strip()
        if name:
            entries.append(name)

lcf = args.lcf_in.read_text()
# Linker-defined constants the linker script has to provide (values read from the original's literal pools):
# overlay ids under their SDK names, and the values in LCF_SYMBOLS (tools/project.py).
sdk = [f"    SDK_OVERLAY_OV{n:03d}_ID = {n};" for n in range(lcf.count("_ID = "))]
# Aliases of main symbols go at the end of the ARM9 block, where their bases have addresses. mwldarm files a symbol
# that the script defines outside every block under the last section (the last overlay), which `dsd check symbols`
# then reports as that overlay's; inside the block it is filed under ARM9 like its base. Absolute aliases stay outside.
aliases = []  # (in ARM9 block, line)
main_syms = {}
for ln in (args.config_dir / "symbols.txt").read_text().splitlines():
    if m := re.match(r"(\S+) kind:\S+ addr:(0x[0-9a-fA-F]+)", ln):
        main_syms.setdefault(m.group(1), int(m.group(2), 16))
edits = args.config_dir / "lcf_edits.txt"
if edits.exists():
    for line in edits.read_text().splitlines():
        words = line.split("#", 1)[0].split()
        if not words:
            continue
        if words[0] == "place":
            stub, func, unit = words[1:]
            old = f"        {stub}(.text)\n"
            if old not in lcf:
                raise SystemExit(f"lcf_edits: no line for {stub} in the LCF")
            lcf = lcf.replace(old, f"        OBJECT({func}, {unit})\n", 1)
        elif words[0] == "alias":
            name, base, offset = words[1:]
            aliases.append((base in main_syms, f"    {name} = {base} + {offset};"))
        elif words[0] == "inner":
            base, size = words[1], int(words[2], 0)
            addrs = {}
            for ln in (args.config_dir / "symbols.txt").read_text().splitlines():
                m = re.match(r"(\S+) kind:(?:data|bss)\S* addr:(0x[0-9a-fA-F]+)", ln)
                if m:
                    addrs[m.group(1)] = int(m.group(2), 16)
            start = addrs[base]
            for name, addr in sorted(addrs.items(), key=lambda kv: kv[1]):
                if start < addr < start + size:
                    aliases.append((True, f"        {name} = {base} + {addr - start:#x};"))
        else:
            raise SystemExit(f"lcf_edits: unknown edit {words[0]!r}")
lcf = lcf.replace("SECTIONS {\n", "SECTIONS {\n" + "\n".join(sdk) + "\n", 1)
inside = [line.strip() for in_main, line in aliases if in_main]
inside += [f"{name} = {value};" for name, value in LCF_SYMBOLS.items()]
outside = [line for in_main, line in aliases if not in_main]
if inside:
    end = lcf.index("    } > ARM9\n")
    lcf = lcf[:end] + "".join(f"        {line}\n" for line in inside) + lcf[end:]
if outside:
    end = lcf.rstrip().rfind("}")
    lcf = lcf[:end] + "\n".join(outside) + "\n" + lcf[end:]
# mwldarm rejects an empty block (a game without overlays and force_active entries has none).
force = f"FORCE_ACTIVE {{ {', '.join(entries)} }}\n\n" if entries else ""
args.lcf_out.write_text(f"{force}{lcf}")
