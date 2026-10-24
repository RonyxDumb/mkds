#!/usr/bin/env python3
"""Random source-transformation search (simulated annealing) for one near-matching function.

Stronger than mutate.py: it works on the whole function body, uses many more transformations (enum-typed copies,
reassigned locals, temporaries through an inline identity, block vs function scope, operand order, casts, compound
assignments, statement order),
scores with a graded distance (a register-only difference costs less than a different instruction) and accepts worse
variants with a temperature, restarting from the best one now and then.

To keep compiles fast, every other function body in the file is replaced by its declaration; the tool first checks
that this leaves the target's bytes unchanged (with `-ipa file` other bodies can matter: then use --full).

  permuter.py <unit.cpp|.c> <function identifier> [--jobs 2] [--minutes 30] [--seed N] [--full]
              [--unit PATH] [--compiler 1.2/base] [--flags '-O4,p -inline on,noauto'] [--out DIR]

Compiler and flags default to the build's settings for --unit (default: the source's own path); -thumb is added
when the target function is Thumb.

The source needs a `// PROBE: <symbol> <module> 0x<address>` line for the target. The best variant is written to
<out>/best.<ext> whenever it improves (score 0 = byte-identical apart from relocated words). Review every result:
statement swaps and type changes are only accepted when the output is identical, but they can still change meaning
if the original compiled to the same code.
"""
import argparse
import math
import os
import random
import re
import shlex
import shutil
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import probe_compilers as pc  # noqa: E402

TYPES = ["int", "s32", "u32", "u16", "s16", "u8", "s8"]
IDENT = r"[A-Za-z_]\w*"
DECL = re.compile(r"^(\s*)((?:const\s+)?(?:unsigned\s+|signed\s+)?(?:int|s32|u32|u16|s16|u8|s8|BOOL|long|short|char"
                  r"|fx32|fx16|PermE\d+))\s+(" + IDENT + r")\s*(=\s*(.+?))?;\s*(//.*)?$")
PTRDECL = re.compile(r"^(\s*)((?:const\s+)?" + IDENT + r"(?:\s*\*)+)\s*(" + IDENT + r")\s*=\s*(.+?);\s*(//.*)?$")
ASSIGN = re.compile(r"^(\s*)(" + IDENT + r")\s*=\s*(.+?);\s*(//.*)?$")
SIMPLE = re.compile(r"^\s*[^{}#/][^{}]*;\s*(//.*)?$")
COMM = re.compile(r"(\b[\w.\[\]>-]+\b|\))\s*([+*&|^]|==|!=)\s*(\b[\w.\[\]>-]+\b)")
MEMBER = re.compile(r"\b(?:" + IDENT + r")(?:(?:->|\.)" + IDENT + r"|\[[^\[\]]+\])+")
COMPOUND = re.compile(r"^(\s*)(" + IDENT + r"(?:(?:->|\.)" + IDENT + r"|\[[^\[\]]+\])*)\s*([+\-*|&^]|<<|>>)=\s*(.+?);\s*$")
EXPANDED = re.compile(r"^(\s*)(" + IDENT + r"(?:(?:->|\.)" + IDENT + r"|\[[^\[\]]+\])*)\s*=\s*\2\s*([+\-*|&^]|<<|>>)\s*(.+?);\s*$")

HELPERS = ("template <class PermT> static inline PermT PermId(PermT x) { return x; }\n")


# ---------------------------------------------------------------------------------------------------------- source
def split_top(text):
    """Top-level chunks: (kind, text). kind is 'func' for a function definition body we may strip."""
    out, i, n, start, depth = [], 0, len(text), 0, 0
    in_s = in_c = in_lc = in_bc = False
    while i < n:
        c = text[i]
        if in_lc:
            if c == "\n":
                in_lc = False
        elif in_bc:
            if text.startswith("*/", i):
                in_bc = False
                i += 1
        elif in_s:
            if c == "\\":
                i += 1
            elif c == '"':
                in_s = False
        elif in_c:
            if c == "\\":
                i += 1
            elif c == "'":
                in_c = False
        elif c == "#" and (i == 0 or text[text.rfind("\n", 0, i) + 1:i].strip() == ""):
            # preprocessor line: skip it with its backslash continuations (macro bodies may contain braces)
            while i < n:
                j = text.find("\n", i)
                if j < 0:
                    i = n
                    break
                if text[j - 1] != "\\":
                    i = j
                    break
                i = j + 1
            continue
        elif text.startswith("//", i):
            in_lc = True
        elif text.startswith("/*", i):
            in_bc = True
        elif c == '"':
            in_s = True
        elif c == "'":
            in_c = True
        elif c == "{":
            if depth == 0:
                head_start = start
                brace = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                head = text[head_start:brace]
                tail_end = i + 1
                is_type = re.search(r"\b(class|struct|union|enum|namespace)\b[^;()]*$", head.split(";")[-1]) or \
                    "=" in head.split(";")[-1].split(")")[-1]
                last = head.rfind(";")
                last = max(last, head.rfind("}"))
                for pm in re.finditer(r"(?m)^[ \t]*#.*$", head):  # preprocessor lines end a header too
                    if pm.end() > last:
                        last = pm.end()
                if not is_type and "(" in head[last + 1:] and not head[last + 1:].strip().startswith("#"):
                    out.append(("pre", text[start:head_start + last + 1]))
                    out.append(("func", text[head_start + last + 1:tail_end]))
                    start = tail_end
        i += 1
    out.append(("pre", text[start:]))
    return out


def find_function(chunks, ident):
    hits = [k for k, (kind, t) in enumerate(chunks) if kind == "func" and re.search(r"\b" + re.escape(ident) +
                                                                                      r"\s*\(", t.split("{")[0])]
    if len(hits) != 1:
        raise SystemExit(f"{len(hits)} definitions match {ident!r}")
    return hits[0]


def stub(func_text):
    head = func_text[:func_text.index("{")]
    head = re.sub(r"\)\s*:\s*[^{]*$", ")", head.rstrip())  # constructor initialiser lists
    if re.search(r"\binline\b", head) or "template" in head:
        return func_text
    return head.rstrip() + ";\n"


# ---------------------------------------------------------------------------------------------------------- scoring
class Scorer:
    def __init__(self, a, probe):
        self.a = a
        self.sym, self.mod, self.addr = probe
        base, blob = pc.module_bytes(self.mod)
        if getattr(a, "goal", None):
            # lab mode: compare the lab function against an excerpt of the original (module:addr:len)
            gm, ga, gl = a.goal.split(":")
            gbase, gblob = pc.module_bytes(gm)
            ga, gl = int(ga, 16), int(gl, 16)
            self.orig = gblob[ga - gbase: ga - gbase + gl]
        else:
            self.orig = blob[self.addr - base: self.addr - base + pc.orig_size(self.mod, self.addr)]
        self.lang = pc.lang_flag(a.unit or a.src)  # the unit's flags already say whether exceptions are on
        thumb_target = not getattr(a, "goal", None) and pc.orig_function(self.mod, self.addr)[1]
        self.mode = "-thumb" if thumb_target and "-thumb" not in a.cc_flags.split() else ""
        self.thumb = "-thumb" in (a.cc_flags + " " + self.mode).split()
        self.tmp = a.run_dir / f"w{os.getpid()}"  # removed with the run directory when main() ends
        self.tmp.mkdir(parents=True, exist_ok=True)

    def compile(self, text):
        src = self.tmp / f"v{os.getpid()}{self.a.src.suffix}"
        obj = self.tmp / f"v{os.getpid()}.o"
        src.write_text(text)
        obj.unlink(missing_ok=True)
        q = shlex.quote
        cmd = (f"{q(str(pc.WIBO))} {q(f'{pc.MWCC_ROOT}/{self.a.compiler}/mwccarm.exe')} {self.a.cc_flags} "
               f"{pc.COMMON_FLAGS} -i {q(str(self.a.src.parent))} {self.lang} {self.mode} -c {q(str(src))} -o {q(str(obj))}")
        r = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=ROOT)
        if r.returncode or not obj.exists():
            return None
        funcs = pc.elf_functions(obj)
        sym = self.sym
        if sym not in funcs:
            ident = re.sub(r"^_Z\d+|^_ZN\d+", "", sym).split("E")[0]
            cands = [f for f in funcs if ident and ident in f]
            if len(cands) != 1:
                return None
            sym = cands[0]
        return funcs[sym]

    def score(self, text):
        got = self.compile(text)
        if got is None:
            return 10 ** 9
        code, mask, _ = got
        if getattr(self.a, "goal", None):
            return self.aligned(code, mask) + 2 * abs(len(code) - len(self.orig)) // self.step
        if len(code) == len(self.orig):
            return self.words(code, mask)
        return self.aligned(code, mask) + 6 * abs(len(code) - len(self.orig)) // self.step

    @property
    def step(self):
        """Instruction unit: 2 bytes in Thumb code, 4 in ARM."""
        return 2 if self.thumb else 4

    def pair_cost(self, a, b):
        if a == b:
            return 0
        # same opcode class, registers differ: cheap; a different instruction: expensive
        cls = 0xF800 if self.thumb else 0xFFF00000
        return 3 if (a & cls) == (b & cls) else 12

    def units(self, data, mask=None):
        """Instruction units as integers; with a mask, units holding a relocated byte become "M"."""
        n = self.step
        return [("M" if mask is not None and any(o in mask for o in range(i, i + n)) else
                 int.from_bytes(data[i:i + n], "little")) for i in range(0, len(data) - n + 1, n)]

    def words(self, code, mask):
        return sum(0 if x == "M" else self.pair_cost(x, y)
                   for x, y in zip(self.units(code, mask), self.units(self.orig)))

    def aligned(self, code, mask):
        """Distance after aligning the two instruction streams (a missing instruction costs one, not a shift)."""
        import difflib
        ours, orig = self.units(code, mask), self.units(self.orig)
        cls = 0xF800 if self.thumb else 0xFFF00000
        key_o = [x if x == "M" else x & cls for x in ours]
        key_g = [x & cls for x in orig]
        s = 0
        for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, key_o, key_g, autojunk=False).get_opcodes():
            if op == "equal":
                s += sum(0 if ours[i] == "M" else self.pair_cost(ours[i], orig[j]) for i, j in
                         zip(range(i1, i2), range(j1, j2)))
            else:
                s += 12 * max(i2 - i1, j2 - j1)
        return s


# ---------------------------------------------------------------------------------------------------------- mutation
class Mutator:
    def __init__(self, rng, cpp):
        self.rng = rng
        self.cpp = cpp  # C++-only transformations are skipped in C
        self.enum_n = 0

    def statements(self, lines):
        return [i for i, l in enumerate(lines) if SIMPLE.match(l) and not l.strip().startswith(("return", "case",
                                                                                               "break", "default"))]

    def mutate(self, body_lines, extra):
        """Mutates body lines in place (one random transformation). `extra` collects file-scope additions."""
        r = self.rng
        ops = [self.swap, self.swap, self.swap_far, self.move_decl, self.split_merge, self.retype, self.retype,
               self.enum_copy, self.temp, self.permid, self.commute, self.cast, self.compound, self.incdec,
               self.inline_ptr, self.reuse, self.hoist_decl, self.sink_decl, self.inplace_add]
        for _ in range(8):
            if r.choice(ops)(body_lines, extra):
                return True
        return False

    def indent(self, l):
        return len(l) - len(l.lstrip())

    def swap(self, L, extra):
        st = self.statements(L)
        pairs = [(i, j) for i, j in zip(st, st[1:]) if j == i + 1 and self.indent(L[i]) == self.indent(L[j])]
        if not pairs:
            return False
        i, j = self.rng.choice(pairs)
        L[i], L[j] = L[j], L[i]
        return True

    def swap_far(self, L, extra):
        st = self.statements(L)
        if len(st) < 3:
            return False
        i = self.rng.choice(st)
        same = [j for j in st if j != i and self.indent(L[j]) == self.indent(L[i]) and abs(j - i) <= 6 and
                not any(("{" in L[k] or "}" in L[k]) for k in range(min(i, j), max(i, j) + 1))]
        if not same:
            return False
        j = self.rng.choice(same)
        line = L.pop(i)
        L.insert(j, line)
        return True

    def move_decl(self, L, extra):
        decls = [i for i, l in enumerate(L) if DECL.match(l) and not DECL.match(l).group(4)]
        if not decls:
            return False
        i = self.rng.choice(decls)
        line = L.pop(i)
        tgt = self.rng.randrange(0, min(len(L), 12) + 1)
        L.insert(tgt, line if self.indent(L[min(tgt, len(L) - 1)]) <= self.indent(line) else line)
        return True

    def split_merge(self, L, extra):
        cand = [i for i, l in enumerate(L) if (m := DECL.match(l)) and m.group(4)]
        if cand and self.rng.random() < 0.6:
            i = self.rng.choice(cand)
            m = DECL.match(L[i])
            L[i] = f"{m.group(1)}{m.group(2)} {m.group(3)};"
            L.insert(i + 1, f"{m.group(1)}{m.group(3)} = {m.group(5)};")
            return True
        for i, l in enumerate(L):
            m = DECL.match(l)
            if m and not m.group(4) and i + 1 < len(L):
                a = ASSIGN.match(L[i + 1])
                if a and a.group(2) == m.group(3) and m.group(3) not in a.group(3):
                    L[i] = f"{m.group(1)}{m.group(2)} {m.group(3)} = {a.group(3)};"
                    del L[i + 1]
                    return True
        return False

    def retype(self, L, extra):
        cand = [i for i, l in enumerate(L) if DECL.match(l) and "const" not in DECL.match(l).group(2)]
        if not cand:
            return False
        i = self.rng.choice(cand)
        m = DECL.match(L[i])
        new = self.rng.choice([t for t in TYPES if t != m.group(2)])
        L[i] = L[i].replace(m.group(2), new, 1)
        return True

    def new_enum(self, extra):
        self.enum_n += 1
        name = f"PermE{self.enum_n}"
        extra.append(f"enum {name} {{ PERM_E{self.enum_n}_0 }};\n")
        return name

    def enum_copy(self, L, extra):
        """Read a field/element into an enum-typed local before its statement (a real load, never substituted)."""
        st = self.statements(L)
        self.rng.shuffle(st)
        for i in st:
            ms = [m for m in MEMBER.finditer(L[i]) if not L[i][m.end():].lstrip().startswith(("(", "="))]
            if not ms:
                continue
            m = self.rng.choice(ms)
            name = self.new_enum(extra)
            var = f"perm_e{self.enum_n}"
            ind = " " * self.indent(L[i])
            L[i] = L[i][:m.start()] + var + L[i][m.end():]
            L.insert(i, f"{ind}{name} {var} = ({name}) {m.group(0)};")
            return True
        return False

    def temp(self, L, extra):
        """Hoist a subexpression into a typed temporary declared just before the statement."""
        st = self.statements(L)
        self.rng.shuffle(st)
        for i in st:
            ms = [m for m in MEMBER.finditer(L[i]) if not L[i][m.end():].lstrip().startswith(("(", "=", "++", "--"))]
            if not ms:
                continue
            m = self.rng.choice(ms)
            self.enum_n += 1
            var = f"perm_t{self.enum_n}"
            ind = " " * self.indent(L[i])
            typ = self.rng.choice(["__typeof__(" + m.group(0) + ")"] * 3 + TYPES)
            L[i] = L[i][:m.start()] + var + L[i][m.end():]
            L.insert(i, f"{ind}{typ} {var} = {m.group(0)};")
            return True
        return False

    def permid(self, L, extra):
        """Route a subexpression through an inline identity (its result becomes a compiler temporary). C++ only: the
        helper is a template."""
        if not self.cpp:
            return False
        st = self.statements(L)
        self.rng.shuffle(st)
        for i in st:
            ms = [m for m in MEMBER.finditer(L[i]) if not L[i][m.end():].lstrip().startswith(("(", "=", "++", "--"))]
            if not ms:
                continue
            m = self.rng.choice(ms)
            if HELPERS not in extra:
                extra.append(HELPERS)
            L[i] = L[i][:m.start()] + f"PermId({m.group(0)})" + L[i][m.end():]
            return True
        return False

    def commute(self, L, extra):
        st = [i for i in self.statements(L) if COMM.search(L[i])]
        if not st:
            return False
        i = self.rng.choice(st)
        ms = list(COMM.finditer(L[i]))
        m = self.rng.choice(ms)
        L[i] = L[i][:m.start()] + f"{m.group(3)} {m.group(2)} {m.group(1)}" + L[i][m.end():]
        return True

    def cast(self, L, extra):
        st = self.statements(L)
        if not st:
            return False
        i = self.rng.choice(st)
        casts = list(re.finditer(r"\((?:u8|s8|u16|s16|u32|s32|int)\)\s*", L[i]))
        if casts and self.rng.random() < 0.5:
            m = self.rng.choice(casts)
            L[i] = L[i][:m.start()] + L[i][m.end():]
            return True
        ids = [m for m in re.finditer(r"(?<![\w.>])(" + IDENT + r")(?![\w(])", L[i]) if m.group(1) not in
               ("return", "if", "else", "for", "while", "do", "const") and not m.group(1)[0].isupper()]
        if not ids:
            return False
        m = self.rng.choice(ids)
        L[i] = L[i][:m.start()] + f"({self.rng.choice(TYPES)}) " + L[i][m.start():]
        return True

    def compound(self, L, extra):
        for i in self.rng.sample(range(len(L)), len(L)):
            m = COMPOUND.match(L[i])
            if m:
                L[i] = f"{m.group(1)}{m.group(2)} = {m.group(2)} {m.group(3)} {m.group(4)};"
                return True
            m = EXPANDED.match(L[i])
            if m:
                L[i] = f"{m.group(1)}{m.group(2)} {m.group(3)}= {m.group(4)};"
                return True
        return False

    def incdec(self, L, extra):
        for i in self.rng.sample(range(len(L)), len(L)):
            m = re.match(r"^(\s*)(" + IDENT + r")(\+\+|--);\s*$", L[i])
            if m:
                op = "+" if m.group(3) == "++" else "-"
                L[i] = self.rng.choice([f"{m.group(1)}{m.group(2)} {op}= 1;", f"{m.group(1)}{m.group(3)}{m.group(2)};",
                                        f"{m.group(1)}{m.group(2)} = {m.group(2)} {op} 1;"])
                return True
        return False

    def inline_ptr(self, L, extra):
        cand = [i for i, l in enumerate(L) if PTRDECL.match(l)]
        if not cand:
            return False
        i = self.rng.choice(cand)
        m = PTRDECL.match(L[i])
        name, init = m.group(3), m.group(4)
        rest = L[i + 1:]
        if any(re.search(r"\b" + name + r"\s*=[^=]", l) for l in rest):
            return False
        L[i + 1:] = [re.sub(r"\b" + name + r"\b", f"({init})", l) for l in rest]
        del L[i]
        return True

    def reuse(self, L, extra):
        """Turn `T b = e;` into a reassignment of an earlier same-type local `a` that is dead afterwards (rarely valid;
        the score decides)."""
        decls = [(i, DECL.match(l)) for i, l in enumerate(L) if DECL.match(l)]
        if len(decls) < 2:
            return False
        (i, a), (j, b) = sorted(self.rng.sample(decls, 2))
        if a.group(2) != b.group(2) or not b.group(4):
            return False
        bname, aname = b.group(3), a.group(3)
        L[j] = f"{b.group(1)}{aname} = {b.group(5)};"
        L[j + 1:] = [re.sub(r"\b" + bname + r"\b", aname, l) for l in L[j + 1:]]
        return True

    def sink_decl(self, L, extra):
        """Move a declaration without initialiser down to the line before its first use (into an inner block)."""
        cand = [i for i, l in enumerate(L) if (m := DECL.match(l)) and not m.group(4)]
        if not cand:
            return False
        i = self.rng.choice(cand)
        m = DECL.match(L[i])
        name = m.group(3)
        use = next((j for j in range(i + 1, len(L)) if re.search(r"\b" + name + r"\b", L[j])), None)
        if use is None or use == i + 1:
            return False
        del L[i]
        use -= 1
        ind = " " * self.indent(L[use])
        a = ASSIGN.match(L[use])
        if a and a.group(2) == name and name not in a.group(3):
            L[use] = f"{ind}{m.group(2)} {name} = {a.group(3)};"
        else:
            L.insert(use, f"{ind}{m.group(2)} {name};")
        return True

    def inplace_add(self, L, extra):
        """Turn `... f(x + k) ...` (x a local) into `x += k;` before the statement and `x` in it."""
        locals_ = {DECL.match(l).group(3) for l in L if DECL.match(l)}
        st = self.statements(L)
        self.rng.shuffle(st)
        for i in st:
            for m in re.finditer(r"\b(" + IDENT + r")\s*([+-])\s*(" + IDENT + r"|0x[0-9a-fA-F]+|\d+)\b(?=\s*[,)])", L[i]):
                if m.group(1) in locals_:
                    ind = " " * self.indent(L[i])
                    L[i] = L[i][:m.start()] + m.group(1) + L[i][m.end():]
                    L.insert(i, f"{ind}{m.group(1)} {m.group(2)}= {m.group(3)};")
                    return True
        return False

    def hoist_decl(self, L, extra):
        """Move a block-scope declaration (with its initialiser split off) to the top of the function."""
        cand = [i for i, l in enumerate(L) if DECL.match(l) and self.indent(l) > self.indent(L[0])]
        if not cand:
            return False
        i = self.rng.choice(cand)
        m = DECL.match(L[i])
        top_ind = " " * self.indent(L[0])
        if m.group(4):
            L[i] = f"{m.group(1)}{m.group(3)} = {m.group(5)};"
        else:
            del L[i]
        L.insert(0, f"{top_ind}{m.group(2).replace('const ', '')} {m.group(3)};")
        return True


# ---------------------------------------------------------------------------------------------------------- search
G = {}


def worker_init(a, probe, pre, post, head, extra0):
    G.update(a=a, scorer=Scorer(a, probe), pre=pre, post=post, head=head, extra0=extra0)


def assemble(body, extra):
    return G["pre"] + "".join(extra) + G["head"] + "{\n" + "\n".join(body) + "\n}\n" + G["post"]


def run_chain(args):
    body, extra, seed, steps, temp0 = args
    rng = random.Random(seed)
    mut = Mutator(rng, G["a"].src.suffix == ".cpp")
    mut.enum_n = 1000 + seed % 100000 * 10
    sc = G["scorer"]
    cur_b, cur_e = list(body), list(extra)
    cur_s = sc.score(assemble(cur_b, cur_e))
    best = (cur_s, list(cur_b), list(cur_e))
    for k in range(steps):
        b, e = list(cur_b), list(cur_e)
        n = 1 + (rng.random() < 0.3) + (rng.random() < 0.1)
        if not all(mut.mutate(b, e) for _ in range(n)):
            continue
        s = sc.score(assemble(b, e))
        if s >= 10 ** 9:
            continue
        t = temp0 * (1 - k / steps) + 0.5
        if s <= cur_s or rng.random() < math.exp(-(s - cur_s) / t):
            cur_b, cur_e, cur_s = b, e, s
            if s < best[0]:
                best = (s, list(b), list(e))
                if s == 0:
                    break
    return best


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("src", type=Path)
    ap.add_argument("ident")
    ap.add_argument("--jobs", type=int, default=2)
    ap.add_argument("--minutes", type=float, default=30)
    ap.add_argument("--seed", type=int, default=None)
    ap.add_argument("--full", action="store_true", help="keep other function bodies")
    ap.add_argument("--unit", help="source path whose build settings to use (default: the source itself)")
    ap.add_argument("--compiler", help="default: the build's compiler for --unit")
    ap.add_argument("--flags", help="replace the build's -O/-inline/-ipa flags for --unit")
    ap.add_argument("--steps", type=int, default=60, help="steps per chain")
    ap.add_argument("--temp", type=float, default=8.0)
    ap.add_argument("--out", type=Path, default=None)
    ap.add_argument("--goal", default=None, help="lab mode: score against original bytes MODULE:0xADDR:0xLEN "
                    "(the lab file needs a // PROBE: line naming its own function; implies --full)")
    a = ap.parse_args()
    a.src = a.src.resolve()
    compiler, flags = pc.unit_flags(a.unit or (a.src.relative_to(ROOT) if a.src.is_relative_to(ROOT) else a.src))
    a.compiler = a.compiler or compiler
    if a.flags:  # replace the build's -O / -inline / -ipa with the given ones
        flags = [f for f in flags if not f.startswith(("-O", "-inline", "-ipa"))] + [a.flags]
    a.cc_flags = " ".join(flags)
    a.run_dir = Path(tempfile.mkdtemp(prefix="perm", dir="/dev/shm"))
    try:
        return search(a)
    finally:
        shutil.rmtree(a.run_dir, ignore_errors=True)


def search(a):
    text = a.src.read_text()
    probes = [(s, m, int(x, 16)) for s, m, x in pc.PROBE.findall(text)]
    if not probes:
        raise SystemExit("need a // PROBE: line")
    probe = next((p for p in probes if a.ident in p[0]), probes[0])
    if a.goal:
        a.full = True
    chunks = split_top(text)
    k = find_function(chunks, a.ident)
    func = chunks[k][1]
    if not a.full:
        chunks = [(kind, stub(t) if kind == "func" and i != k else t) for i, (kind, t) in enumerate(chunks)]
    pre = "".join(t for _, t in chunks[:k])
    post = "".join(t for _, t in chunks[k + 1:])
    head = func[:func.index("{")]
    body = func[func.index("{") + 1: func.rindex("}")].strip("\n").split("\n")
    out = a.out or a.src.parent / f"perm_{a.ident}"
    out.mkdir(parents=True, exist_ok=True)

    sc = Scorer(a, probe)
    full_s = sc.score(text)
    G.update(pre=pre, post=post, head=head)
    red_s = sc.score(assemble(body, []))
    print(f"baseline: full file {full_s}, reduced {red_s}", flush=True)
    if not a.full and red_s != full_s:
        print("reduced file scores differently: rerun with --full", flush=True)
        return 1
    best = (red_s, body, [])
    seed = a.seed if a.seed is not None else random.randrange(1 << 30)
    end = time.time() + a.minutes * 60
    rnd = 0
    with ProcessPoolExecutor(a.jobs, initializer=worker_init, initargs=(a, probe, pre, post, head, [])) as ex:
        while time.time() < end and best[0] > 0:
            rnd += 1
            starts = [best] * a.jobs
            jobs = [(b, e, seed + rnd * 997 + j, a.steps, a.temp) for j, (s, b, e) in enumerate(starts)]
            for res in ex.map(run_chain, jobs):
                if res[0] < best[0]:
                    best = res
                    (out / f"best{a.src.suffix}").write_text(
                        text.replace(func, head + "{\n" + "\n".join(res[1]) + "\n}\n") if not res[2] else
                        "".join(res[2]).join([text[:text.index(func)], ""]) + text[text.index(func):].replace(
                            func, head + "{\n" + "\n".join(res[1]) + "\n}\n", 1))
                    print(f"{time.strftime('%H:%M:%S')} round {rnd}: best {best[0]}", flush=True)
    print(f"done: best {best[0]} -> {out}/best{a.src.suffix}", flush=True)
    return 0 if best[0] == 0 else 2


if __name__ == "__main__":
    sys.exit(main())
