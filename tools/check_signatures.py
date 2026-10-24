#!/usr/bin/env python3
"""Lists functions whose declarations and definition disagree across src/, include/ and libs/.

Each function should have one declaration, in the header of the module that defines it, with the definition's
types. Types are compared after resolving the basic typedefs (u32 = unsigned int, s32 = int = BOOL, ...);
parameter names are ignored. Exit status 1 when anything disagrees.

  check_signatures.py
"""
import collections
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
KW = {"if", "while", "for", "switch", "return", "sizeof", "else", "do", "case", "goto", "new", "delete",
      "throw"}
TYPE_WORDS = {"long", "int", "char", "short", "double", "float", "unsigned", "signed", "void", "u8", "u16", "u32",
              "u64", "s8", "s16", "s32", "s64", "BOOL", "size_t", "wchar_t"}
ALIAS = [(r"\bunsigned int\b", "u32"), (r"\bunsigned short\b", "u16"), (r"\bunsigned char\b", "u8"),
         (r"\bsigned char\b", "s8"), (r"\bBOOL\b", "s32"), (r"\bint\b", "s32"), (r"\bshort\b", "s16")]
DECL = re.compile(r"^(?:extern\s+|static\s+|inline\s+|asm\s+)*((?:const\s+|unsigned\s+|signed\s+|volatile\s+|struct\s+)*"
                  r"\w+[\s\*]+)(\w+)\s*\(([^;{)(]*(?:\([^)]*\)[^;{)(]*)*)\)\s*(;|\{)", re.M)


def canon(x):
    for a, b in ALIAS:
        x = re.sub(a, b, x)
    return x


def split_params(p):
    """Splits a parameter list at top-level commas (a function-pointer parameter has its own list)."""
    out, depth, cur = [], 0, ""
    for ch in p:
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
            continue
        depth += (ch == "(") - (ch == ")")
        cur += ch
    return out + [cur]


def norm_params(p):
    p = p.strip()
    if p in ("", "void"):
        return "void"
    out = []
    for a in split_params(p):
        a = re.sub(r"\s+", " ", a.strip())
        if a == "...":
            out.append(a)
            continue
        a = re.sub(r"\[[^\]]*\]", "*", a)
        if fp := re.match(r"(.*?)\(\s*\*\s*\w*\s*\)\s*\((.*)\)\s*$", a):
            # function pointer: drop its own name and its parameters' names
            a = f"{fp.group(1).strip()} (*)({norm_params(fp.group(2))})"
        elif "(*" in a:
            a = re.sub(r"\(\s*\*\s*\w*\s*\)", "(*)", a)
        else:
            m = re.match(r"(.*?[\s\*])(\w+)\s*$", a)  # drop a trailing parameter name
            if m and m.group(2) not in TYPE_WORDS:
                a = m.group(1)
        out.append(re.sub(r"\s*\*\s*", "*", a).strip())
    return ",".join(out)


def main():
    sigs = collections.defaultdict(set)
    where = collections.defaultdict(set)
    for d in ("src", "include", "libs"):
        for f in (ROOT / d).rglob("*"):
            if f.suffix not in (".c", ".h", ".cpp", ".hpp"):
                continue
            text = re.sub(r"//[^\n]*|/\*.*?\*/", "", f.read_text(errors="replace"), flags=re.S)
            text = re.sub(r";[ \t]+(?=\S)", ";\n", text)  # one declaration per line (several prototypes on one line)
            for m in DECL.finditer(text):
                ret, name, params = m.group(1), m.group(2), m.group(3)
                if name in KW or ret.strip() in KW:
                    continue
                if not params.strip() and m.group(4) != "{" and f.suffix in (".c", ".h"):
                    continue  # a C declaration without a prototype says nothing about the parameters
                ret = re.sub(r"\b(extern|static|inline|asm)\b", "", ret)
                ret = re.sub(r"\s*\*\s*", "*", re.sub(r"\s+", " ", ret)).strip()
                sig = canon(f"{ret} ({norm_params(params)})")
                sigs[name].add(sig)
                where[(name, sig)].add(str(f.relative_to(ROOT)) + (" (definition)" if m.group(4) == "{" else ""))
    bad = sorted(n for n in sigs if len(sigs[n]) > 1)
    for name in bad:
        print(name)
        for sig in sorted(sigs[name]):
            print(f"    {sig:60} {', '.join(sorted(where[(name, sig)]))}")
    print(f"{len(bad)} function(s) with disagreeing declarations", file=sys.stderr)
    sys.exit(1 if bad else 0)


if __name__ == "__main__":
    main()
