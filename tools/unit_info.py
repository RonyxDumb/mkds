#!/usr/bin/env python3
"""Lists, for each source unit, what can name it: its functions (named ones first), the global data it defines and the
strings it uses (file paths, message files). Reads the compiled objects, so run `ninja report` (or `ninja`) first.

  unit_info.py [unit-substring ...] [--unknown] [--json]

--unknown limits the list to units still called `code_<address>`.
"""
import argparse
import json
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).parent))
from link_check import BUILD, delinks_files, parse_units  # noqa: E402
from project import PLACEHOLDER  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent
PRINTABLE = re.compile(rb"^[\x20-\x7e]{3,}$")


def info(src: str):
    obj = BUILD / Path(src).with_suffix(".o")
    if not obj.exists():
        return None
    funcs, data, strings = [], [], []
    with obj.open("rb") as fh:
        elf = ELFFile(fh)
        secs = list(elf.iter_sections())
        for s in elf.get_section_by_name(".symtab").iter_symbols():
            if not isinstance(s["st_shndx"], int) or not s.name or s.name.startswith(("$", ".")):
                continue
            sec = secs[s["st_shndx"]]
            if s["st_info"]["type"] == "STT_FUNC":
                funcs.append(s.name)
            elif s["st_info"]["type"] == "STT_OBJECT" and not s.name.startswith("@"):
                data.append(s.name)
            if s["st_info"]["type"] != "STT_FUNC" and sec.name in (".data", ".rodata") and sec["sh_type"] != "SHT_NOBITS":
                size = s["st_size"] or sec["sh_size"] - s["st_value"]
                raw = sec.data()[s["st_value"]:s["st_value"] + size].split(b"\0")[0]
                if PRINTABLE.match(raw):
                    strings.append(raw.decode())
    named = sorted(f for f in funcs if not PLACEHOLDER.match(f))
    return {"unit": src, "functions": len(funcs), "named": named,
            "placeholders": sorted(f for f in funcs if PLACEHOLDER.match(f)),
            "data": sorted(data), "strings": sorted(set(strings))}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("filters", nargs="*")
    ap.add_argument("--unknown", action="store_true")
    ap.add_argument("--json", action="store_true")
    a = ap.parse_args()
    out = []
    for _, path in delinks_files():
        for unit in parse_units(path):
            src = unit["file"]
            if a.filters and not any(f in src for f in a.filters):
                continue
            if a.unknown and not Path(src).stem.startswith("code_"):
                continue
            i = info(src)
            if i:
                out.append(i)
    if a.json:
        print(json.dumps(out, indent=1))
        return
    for i in out:
        print(f"{i['unit']}: {len(i['named'])}/{i['functions']} functions named")
        for key in ("named", "data", "strings"):
            if i[key]:
                print(f"  {key}: " + ", ".join(i[key][:12]) + (" ..." if len(i[key]) > 12 else ""))


if __name__ == "__main__":
    main()
