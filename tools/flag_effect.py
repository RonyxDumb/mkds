#!/usr/bin/env python3
"""Shows whether a compiler flag changes any object: compiles each source with its build settings and with one flag
replaced (or removed), and compares every code/data section and relocation.

A flag that changes nothing in any file is "not separated" by the code so far; a file whose object changes, while the
build's setting links and matches, is evidence for that setting.

  flag_effect.py "-char signed" "-char unsigned" [paths...]     replace a flag
  flag_effect.py "-str reuse" "" libs/                          remove it (compiler default)

Paths default to src/ and libs/; directories are searched for .c and .cpp files.
"""
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
from probe_compilers import INCLUDES, MWCC_ROOT, WIBO  # noqa: E402
from project import MWCC_VERSION, VERSION, source_flags  # noqa: E402  (tools/project.py)

ROOT = Path(__file__).resolve().parent.parent


def signature(obj):
    out = {}
    with open(obj, "rb") as f:
        elf = ELFFile(f)
        for i, sec in enumerate(elf.iter_sections()):
            if sec.name.startswith((".text", ".data", ".rodata", ".bss", ".init", ".ctor")):
                out[(sec.name, i)] = sec.data() if sec["sh_type"] != "SHT_NOBITS" else sec["sh_size"]
            elif isinstance(sec, RelocationSection) and not sec.name.startswith(".rel.debug"):
                syms = elf.get_section(sec["sh_link"])
                out[("rel", sec.name, i)] = tuple((r["r_offset"], r["r_info_type"], syms.get_symbol(r["r_info_sym"]).name,
                                                   r.entry.get("r_addend", 0)) for r in sec.iter_relocations())
    return out


def compile_with(src, flags, out):
    version, _ = source_flags(str(src))
    cmd = [str(WIBO), str(MWCC_ROOT / (version or MWCC_VERSION) / "mwccarm.exe"), *flags,
           *(w for d in INCLUDES for w in ("-i", d)), "-d", f"version_{VERSION.upper()}", "-c", str(src), "-o", str(out)]
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True).returncode == 0


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    old, new, paths = sys.argv[1], sys.argv[2], sys.argv[3:] or ["src", "libs"]
    srcs = sorted({f.relative_to(ROOT) for p in paths for f in ([ROOT / p] if (ROOT / p).is_file() else
                   (ROOT / p).rglob("*")) if f.suffix in (".c", ".cpp")})
    changed = 0
    with tempfile.TemporaryDirectory(dir=ROOT / "build") as tmp:
        for src in srcs:
            _, flags = source_flags(str(src))
            line = " ".join(flags)
            if old not in line:
                print(f"{str(src):50} (flag not used)")
                continue
            variant = " ".join(line.replace(old, new).split())
            a, b = Path(tmp) / "a.o", Path(tmp) / "b.o"
            if not (compile_with(src, line.split(), a) and compile_with(src, variant.split(), b)):
                print(f"{str(src):50} COMPILE ERROR")
                continue
            same = signature(a) == signature(b)
            changed += not same
            print(f"{str(src):50} {'same' if same else 'differs'}")
    print(f"{changed} of {len(srcs)} file(s) change with {new or 'no flag'!r} instead of {old!r}", file=sys.stderr)


if __name__ == "__main__":
    main()
