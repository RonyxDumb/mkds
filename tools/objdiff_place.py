#!/usr/bin/env python3
"""Adjusts the dsd-written objdiff.json: per-file scratch flags, and objects for functions placed apart.

dsd gives every unit's decomp.me scratch the same compiler and flags. Each unit with a source file gets that file's
own: its compiler's decomp.me id (DECOMP_ME_IDS) and flags (tools/project.py source_flags: per-path drops and
additions such as -thumb, and -lang=c or -lang=c++).

A `place <stub>.o <function> <unit>.o` edit leaves the stub unit's compiled object empty; its function is compiled in
<unit>. This makes objdiff compare the stub's original against <unit>'s object, so the function is scored where it is
really defined.

  objdiff_place.py objdiff.json config/<ver>/arm9/lcf_edits.txt
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from project import DECOMP_ME_IDS, MWCC_VERSION, source_flags  # noqa: E402  (tools/project.py)

cfg_path, edits_path = Path(sys.argv[1]), Path(sys.argv[2])
cfg = json.loads(cfg_path.read_text())
for unit in cfg["units"]:
    src = unit.get("metadata", {}).get("source_path")
    if src and "scratch" in unit:
        version, flags = source_flags(src)
        if (version or MWCC_VERSION) not in DECOMP_ME_IDS:  # no decomp.me id for this build (DSi): no scratch
            del unit["scratch"]
            continue
        unit["scratch"]["c_flags"] = " ".join(flags)
        unit["scratch"]["compiler"] = DECOMP_ME_IDS[version or MWCC_VERSION]
stem = lambda o: o.removesuffix(".o")
for line in edits_path.read_text().splitlines():
    words = line.split("#", 1)[0].split()
    if not words or words[0] != "place":
        continue
    stub, _, unit = words[1:]
    units = {Path(u["name"]).name: u for u in cfg["units"]}
    if stem(stub) in units and stem(unit) in units:
        units[stem(stub)]["base_path"] = units[stem(unit)]["base_path"]
cfg_path.write_text(json.dumps(cfg, indent=2) + "\n")
