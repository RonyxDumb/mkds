#!/usr/bin/env python3
"""Writes the C definition of an object the original still provides, from its bytes in the ROM and the type its
declaration gives, to move data into the source.

  data_init.py <module> <symbol> [<C type>] [--static]

The type defaults to the one of the symbol's `extern` declaration in include/ and libs/*/include/. Structs are
read from the headers, whose members carry their offsets (`/* 2c */ u8 mState;`); arrays, pointers, strings
(`char x[]` with text) and nested structs are filled in. A word the original relocates is written as the address of
the symbol at its target (`&name`, `name + 4`, or a function name). Bytes a struct doesn't name (padding) must be zero,
or the tool stops. Check the result: a member typed too loosely (a u8 array for a table of halfwords) gives correct but
unreadable values.
"""
import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from link_check import CFG  # noqa: E402
from probe_compilers import module_bytes  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
PRIM = {"u8": (1, "<B"), "s8": (1, "<b"), "char": (1, "<b"), "u16": (2, "<H"), "s16": (2, "<h"), "u32": (4, "<I"),
        "s32": (4, "<i"), "int": (4, "<i"), "BOOL": (4, "<i"), "f32": (4, "<f"), "u64": (8, "<Q"), "s64": (8, "<q"),
        "unsigned int": (4, "<I"), "unsigned char": (1, "<B"), "signed char": (1, "<b"), "short": (2, "<h"),
        "unsigned short": (2, "<H"), "long": (4, "<i"), "unsigned long": (4, "<I"), "fx32": (4, "<i"),
        "fx16": (2, "<h"), "vu8": (1, "<B"), "vu16": (2, "<H"), "vu32": (4, "<I")}
MEMBER = re.compile(r"^\s*/\*\s*([0-9a-fA-F]+)\s*\*/\s*(.+?)\s*;\s*(//.*)?$")
SYM = re.compile(r"^(\S+) kind:(\w+)(?:\(([^)]*)\))? addr:(0x[0-9a-f]+)")
RELOC = re.compile(r"^from:(0x[0-9a-f]+) kind:(\S+) to:(0x[0-9a-f]+)(?: add:(0x[0-9a-f]+))? module:(\S+)")


def headers():
    return list((ROOT / "include").rglob("*.h")) + list((ROOT / "libs").glob("*/include/**/*.h")) + \
        list((ROOT / "libs").glob("*/*/include/**/*.h"))


class Types:
    def __init__(self):
        self.structs = {}  # name -> [(offset, type text, member name, dims)]
        self.alias = {}  # typedef name -> type text
        self.sizes = {}
        for h in headers():
            lines = h.read_text().splitlines()
            i = 0
            while i < len(lines):
                line = lines[i]
                if m := re.match(r"^\s*typedef\s+(struct|union)\s+(\w+)?\s*\{", line):
                    kind, body, i = m.group(1), [], i + 1
                    depth = 1
                    while i < len(lines) and depth:
                        depth += lines[i].count("{") - lines[i].count("}")
                        if depth:
                            body.append(lines[i])
                        else:
                            end = re.match(r"^\s*\}\s*(\w+)\s*;", lines[i])
                        i += 1
                    if end:
                        self.structs.setdefault(end.group(1), (kind, body))
                    continue
                if m := re.match(r"^\s*typedef\s+([\w\s\*]+?)\s+(\w+)\s*;", line):
                    self.alias.setdefault(m.group(2), m.group(1).strip())
                i += 1

    def members(self, name):
        kind, body = self.structs[name]
        out = []
        for line in body:
            if m := MEMBER.match(line):
                off = int(m.group(1), 16)
                decl = re.sub(r"\s*:\s*\d+$", "", m.group(2))  # bitfields: not handled (stop below)
                if ":" in m.group(2):
                    raise SystemExit(f"{name}: bitfield member `{m.group(2)}` not handled")
                dm = re.match(r"^(.*?)(\**)\s*(\w+)((?:\[[^\]]*\])*)$", decl)
                if not dm:
                    raise SystemExit(f"{name}: cannot read member `{decl}`")
                base, stars, mname, dims = dm.groups()
                dims = [int(d, 0) for d in re.findall(r"\[([^\]]*)\]", dims)]
                out.append((off, base.strip() + stars, mname, dims))
        return kind, out

    def resolve(self, t):
        t = t.replace("const ", "").replace("volatile ", "").strip()
        t = re.sub(r"^struct\s+", "", t)
        seen = 0
        while t in self.alias and t not in PRIM and seen < 10:
            t = self.alias[t].replace("const ", "").strip()
            t = re.sub(r"^struct\s+", "", t)
            seen += 1
        return t

    def size(self, t):
        t = self.resolve(t)
        if t.endswith("*") or "(" in t:
            return 4
        if t in PRIM:
            return PRIM[t][0]
        if t in self.structs:
            kind, ms = self.members(t)
            if not ms:
                raise SystemExit(f"{t}: no members with offsets")
            if kind == "union":
                return max(self.size(mt) * prod(d) for _, mt, _, d in ms)
            off, mt, _, d = ms[-1]
            end = off + self.size(mt) * prod(d)
            return (end + self.align(t) - 1) // self.align(t) * self.align(t)
        if t.startswith("enum") or t in ("UnkFunc", "UnkWordFunc"):
            return 4
        raise SystemExit(f"unknown type `{t}`")

    def align(self, t):
        t = self.resolve(t)
        if t.endswith("*") or "(" in t:
            return 4
        if t in PRIM:
            return min(4, PRIM[t][0]) if PRIM[t][0] != 8 else 4
        if t in self.structs:
            return max(self.align(mt) for _, mt, _, _ in self.members(t)[1])
        return 4


def prod(dims):
    n = 1
    for d in dims:
        n *= d
    return n


class Writer:
    def __init__(self, module, types):
        self.module, self.types = module, types
        self.base, self.blob = module_bytes(module)
        self.relocs = {}
        for path in CFG.rglob("relocs.txt"):
            mod = "main" if path.parent == CFG else path.parent.name
            if mod != module:
                continue
            for line in path.read_text().splitlines():
                if m := RELOC.match(line):
                    self.relocs[int(m.group(1), 16)] = (int(m.group(3), 16), int(m.group(4) or "0", 16), m.group(5))
        self.names = {}  # (module, address) -> (name, kind)
        mods = {"main": CFG / "symbols.txt", "itcm": CFG / "itcm/symbols.txt", "dtcm": CFG / "dtcm/symbols.txt"}
        for d in (CFG / "overlays").iterdir():
            mods[d.name] = d / "symbols.txt"
        for mod, p in mods.items():
            for line in p.read_text().splitlines():
                if (m := SYM.match(line)) and not m.group(1).startswith((".L", "@")):
                    self.names.setdefault((mod, int(m.group(4), 16)), (m.group(1), m.group(2)))
        self.used = set()

    def spacing(self, addr):
        """Bytes from addr to the next symbol of the module."""
        later = [ad for (mod, ad) in self.names if mod == self.module and ad > addr]
        return min(later) - addr if later else 4

    def word_ref(self, addr):
        """The C expression for a relocated word at addr, or None."""
        if addr not in self.relocs:
            return None
        to, add, field = self.relocs[addr]
        mod = field if field in ("main", "itcm", "dtcm") else (
            "ov%03d" % int(re.search(r"\d+", field).group()) if field.startswith("overlay") else self.module)
        for cand in (mod, "main", self.module):
            if (cand, to) in self.names:
                name, kind = self.names[(cand, to)]
                break
            if (cand, to & ~1) in self.names:
                name, kind = self.names[(cand, to & ~1)]
                to &= ~1
                break
        else:
            raise SystemExit(f"word at {addr:#010x}: no symbol at {to:#010x}")
        self.used.add(name)
        expr = name if kind == "function" else f"&{name}"
        if add:
            expr = f"(u8 *) &{name} + {add:#x}" if kind != "function" else f"(u8 *) {name} + {add:#x}"
        return expr

    def value(self, t, addr, indent):
        types = self.types
        rt = types.resolve(t)
        if rt.endswith("*") or "(" in rt or rt in ("UnkFunc", "UnkWordFunc"):
            ref = self.word_ref(addr)
            w = struct.unpack_from("<I", self.blob, addr - self.base)[0]
            if ref:
                return ref if rt.startswith("void") or "(" in rt else f"({t}) {ref}" if ref.startswith("(") else ref
            return "NULL" if w == 0 else f"({t}) {w:#010x}"
        if rt in PRIM:
            hit = [a for a in range(addr - 3, addr + PRIM[rt][0]) if a in self.relocs and a + 4 > addr]
            if hit and (PRIM[rt][0] != 4 or hit[0] != addr):
                raise SystemExit(f"{t} at {addr:#010x} holds part of a relocated word: give the object a type with a "
                                 f"pointer there")
            if addr in self.relocs:
                return f"({t}) {self.word_ref(addr)}"
            size, fmt = PRIM[rt]
            v = struct.unpack_from(fmt, self.blob, addr - self.base)[0]
            if fmt == "<f":
                return repr(v) + "f"
            if fmt[1].isupper() and v > 9:
                return f"{v:#x}"
            return str(v)
        if rt in types.structs:
            kind, ms = types.members(rt)
            if kind == "union":
                off, mt, mn, d = ms[0]
                return "{" + self.member(mt, d, addr + off, indent + 1) + "}"
            parts, covered = [], set()
            for off, mt, mn, d in ms:
                parts.append(self.member(mt, d, addr + off, indent + 1))
                covered |= set(range(off, off + types.size(mt) * prod(d)))
            size = types.size(rt)
            for i in range(size):
                if i not in covered and self.blob[addr - self.base + i]:
                    raise SystemExit(f"{rt} at {addr:#010x}: byte {i:#x} is not zero but no member covers it")
            return "{" + ", ".join(parts) + "}"
        if rt.startswith("enum"):
            return str(struct.unpack_from("<i", self.blob, addr - self.base)[0])
        raise SystemExit(f"unknown type `{t}`")

    def member(self, t, dims, addr, indent):
        if not dims:
            return self.value(t, addr, indent)
        size = self.types.size(t) * prod(dims[1:])
        rt = self.types.resolve(t)
        if len(dims) == 1 and rt in ("char", "u8", "s8") and self.is_text(addr, dims[0]):
            raw = bytes(self.blob[addr - self.base:addr - self.base + dims[0]])
            return c_string(raw.rstrip(b"\0")) if raw.rstrip(b"\0") else "{0}"
        items = [self.member(t, dims[1:], addr + i * size, indent) for i in range(dims[0])]
        while len(items) > 1 and items[-1] in ("0", "NULL", "{0}"):
            items.pop()
        return "{" + ", ".join(items) + "}"

    def is_text(self, addr, n):
        raw = bytes(self.blob[addr - self.base:addr - self.base + n])
        s = raw.split(b"\0")[0]
        return len(s) >= 2 and all(32 <= c < 127 for c in s) and not raw[len(s):].strip(b"\0")


def c_string(raw: bytes) -> str:
    return '"' + "".join(chr(c) if 32 <= c < 127 and chr(c) not in '"\\' else ("\\" + chr(c) if chr(c) in '"\\' else f"\\x{c:02x}")
                         for c in raw) + '"'


def find_decl(symbol):
    pat = re.compile(r"^\s*extern\s+(.+?)\b" + re.escape(symbol) + r"\s*((?:\[[^\]]*\])*)\s*;")
    for h in headers():
        for line in h.read_text().splitlines():
            if m := pat.match(line):
                return m.group(1).strip(), m.group(2), h
    raise SystemExit(f"no extern declaration of {symbol}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("symbol")
    ap.add_argument("ctype", nargs="?")
    ap.add_argument("--static", action="store_true")
    ap.add_argument("--const", action="store_true", help="define it const (an object of .rodata)")
    ap.add_argument("--bss", action="store_true", help="an object of .bss: the definition without initializer")
    ap.add_argument("--size", type=lambda s: int(s, 0), help="the object's size, for an array declared with []")
    a = ap.parse_args()
    types = Types()
    w = Writer(a.module, types)
    addr = next((ad for (mod, ad), (n, k) in w.names.items() if n == a.symbol and mod == a.module), None)
    if addr is None:
        raise SystemExit(f"{a.symbol} not in {a.module}")
    if a.ctype:
        base, dims_text = a.ctype, ""
    else:
        base, dims_text, _ = find_decl(a.symbol)
    stars = re.match(r"^(.*?)(\**)$", base)
    btype = (stars.group(1).strip() + stars.group(2)).strip()
    dims = [d for d in re.findall(r"\[([^\]]*)\]", dims_text)]
    if dims and dims[0] == "":
        esize = types.size(btype) * prod([int(d, 0) for d in dims[1:]])
        if a.size:
            n = a.size // esize
        elif not a.bss and types.resolve(btype) in ("char", "u8", "s8") and w.is_text(addr, w.spacing(addr)):
            n = w.blob.index(b"\0", addr - w.base) - (addr - w.base) + 1
        elif w.spacing(addr) % esize == 0:
            n = w.spacing(addr) // esize  # up to the next symbol: check that no padding is counted
        else:
            raise SystemExit("an array declared with []: give its size with --size")
        dims[0] = str(n)
    dims = [int(d, 0) for d in dims]
    init = None if a.bss else w.member(btype, dims, addr, 0)
    star = btype.endswith("*")
    decl = f"{btype}{a.symbol}" if star else f"{btype} {a.symbol}"
    decl = re.sub(r"\s*(\*+)$", r" \1", btype) + a.symbol if star else decl
    decl += "".join(f"[{d}]" for d in dims)
    if a.const and not decl.startswith("const "):
        decl = "const " + decl
    print(("static " if a.static else "") + (f"{decl};" if init is None else f"{decl} = {init};"))


if __name__ == "__main__":
    main()
