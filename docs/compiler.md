# Compiler identification

How the toolchain settings in `tools/project.py` are established. Record each claim here with its evidence and how
to reproduce it; a setting with no exact match that breaks when it changes is unverified and says so.

## Result

| Code | Compiler | Flags | Evidence |
|---|---|---|---|
| Game code (main + overlays) | 1.2 base (ARM: base, sp2, sp2p3 not separated) | `-O4,p -inline on,noauto -char unsigned -str noreuse -proc arm946e -interworking` | exact matches below |
| NitroSDK | 1.2 base (assumed) | `-O4,p`, default inlining, `-char signed`, `-proc arm946e`, `-interworking` (assumed) | none yet: see Open |
| NitroSystem | 1.2 base (assumed) | as NitroSDK (assumed) | none yet: see Open |
| C runtime (MSL), C files | 1.2 base (assumed) | as NitroSDK (assumed) | none yet: see Open |

### Game code

The game code is C: no mangled names, an empty `.ctor` table in every module, and function-pointer tables that
aren't vtables. The deciding probes, written for this ROM, are in [probes/](probes/); each file's first lines say
what it shows and the command that reruns it on every installed build
(`python3 tools/probe_compilers.py docs/probes/<file> --flags="-O4,p -inline on,noauto"`):

- Thumb switch dispatch: four switch functions (main 0x02025e60 and 0x0204e3b4, ov003 0x021cca5c and 0x021c88c4)
  and one in ov001 (0x02194c7c) match on 1.2 b56 and base only: their tables are read with a sign-extended halfword
  load and `add r0, pc; bx r0`. sp2 drops the sign extension; sp2p3, sp3, sp4 and every 2.0 build end in
  `add pc, r0` (`thumb_switch_main.c`, `thumb_switch_ov003.c`, `thumb_switch_ov001.c`).
- b56 reaches a field it reads and writes back through an address computed once (`add rX, rY, #imm`, then
  `ldr`/`str` through rX), a shape base never emits; in the disassembly of main's game code that shape appears only
  once (0x0206ff50) in about 5,500 functions (read with a scanner that isn't in the repository).
- ARM: a multiply-heavy function (main 0x020dac00, 0x58 bytes, `arm_long_multiply.c`) matches on 1.2 b56 to sp2p3
  and on no 2.0 build at any `-proc`; in the disassembly, every ARM game function returns through
  `ldm {.., lr}; bx lr`, never `ldm {.., pc}`, which 1.2 sp3/sp4 emit under `-proc arm946e`. DSP multiplies (`smulbb`,
  `smlabb`) in game code need `-proc arm946e`.
- `-char unsigned`: a function walking a `char` path (main 0x02047780, `thumb_char_strings.c`) is 0x13c bytes with
  `ldrb`; with `-char signed` it is 0x144 bytes.
- `-str noreuse`: the same function references eight literals for four copies each of two format strings; with
  `-str reuse` the copies merge (0x124 bytes).
- `-O4,p`: `-O4,s`, `-O3` and `-O2` break main 0x0204e3b4 and ov001 0x02194c7c; `-O3`, `-O2` and `-O3,p` break
  ov003 0x021c88c4.
- Some game files are compiled for size and carry `#pragma optimize_for_size on`: `src/01/code_0218550c.c`,
  `code_021804e0.c`, `code_02180610.c`, `code_021857a4.c` and `code_02185438.c`. In `code_0218550c.c` (ov001, USA
  0x021854ec-0x02185784) five two-case switch functions share one exit block; at `-O4,p` the return sequence is
  repeated in each case (0x32 bytes instead of 0x2a). All 14 functions of that file match at `-O4,s`, at `-O3`, and at
  the build's `-O4,p` with the pragma. The others show the same two signs: switch cases that share an epilogue, and
  aggregate copies kept as loops instead of unrolled (`code_021804e0.c`, `code_02180610.c`).
- Inlining: `-inline auto` inlines a same-file call (ov001 0x02194ce4 into 0x02194c7c, `thumb_switch_ov001.c`)
  that the game keeps out of line.

### Libraries

Not probed from this ROM yet. `tools/project.py` builds NitroSDK, NitroSystem and the C runtime with the game code's
build (1.2 base) at `-O4,p`, with the default inlining and `-char signed`, as a starting point. Each setting needs
probes written from this ROM's library code before it counts as verified.

## Tools

- `tools/probe_compilers.py <probe>`: compiles a decompiled function with every installed compiler build and
  compares it byte for byte with the ROM, masking only each function's own relocation sites. Mark each function in
  the probe with `// PROBE: <mangled symbol> <module> <address>`; `--only`, `--flags` and `--show` narrow a run and
  print a side-by-side diff, and `--unit <source path>` probes with exactly the build's compiler and flags for that
  path. Each `--flags` set must spell out `-O` and `-inline` (and `-ipa` on 2.0 builds; 1.2 rejects it).
- `tools/flag_effect.py "<flag>" "<other>" [paths]`: compiles every file with its build settings and with one flag
  replaced or removed, and lists the files whose objects change. A flag no file depends on is "not separated"; files
  that change while the build's setting links and matches are evidence for it.

## Method

1. Decompile about 20 real functions spread across modules and constructs (constructors, destructors, virtual
   calls, singletons, soft float, 64-bit fixed point, switch tables, register-heavy loops, SDK struct access, string
   tables) as stand-alone probe files.
2. Compile each with every installed build and the candidate flag sets, and count exact matches. A miss that fails
   the same way on every build is a source detail, not a compiler signal.
3. If adjacent service packs can't be told apart on probes, write probes around the constructs listed under "What
   separates builds and flags" below.
4. Find a codegen idiom that separates the remaining groups and scan the ROM's disassembly for it, after checking the
   scanner on code whose build is known.
5. For each flag, record an exact match that breaks when the flag changes.
6. Identify each library separately: the SDK, NitroSystem, the C runtime and middleware are usually prebuilt with
   another build and other flags (often the default inlining instead of the game's `-inline on,noauto`). Count only
   functions with game idioms (singleton guards, the game's classes) as game evidence. One library can need different
   builds for different parts. Set `PATH_COMPILERS` and `PATH_DROP_FLAGS` from the result.
7. Commit the deciding probes in `docs/probes/` (one file per construct, with what it shows and how to rerun it) and
   document the evidence here; the other probes stay out of the repository.

## What separates builds and flags

- Idioms: a 64x32 multiply with a known-zero high word gives `umull` + `mla` against a zeroed register up to 2.0 sp2
  and only `umull` from sp2p2 on; whole-function size differences of a few words between service packs.
- `-O` level: `-O3,p` allocates registers differently; `-O4,s` and `-O2` keep small accessors out of line.
- `-ipa file`: statics of inline functions are shared standalone sections referenced from every module; without it
  they land in each file's `.bss`. In C under `-ipa file`, a function can load a global defined in its own file from
  two literal-pool words (one through the section, one through the symbol); with the global `extern`, or without
  `-ipa file`, it uses one. So a duplicate pool word in the original shows the global is defined in that file.
- 2.0 sp2p2 vs sp2p3 (under `-ipa file`): sp2p3 and sp2p4 give every object of 64 bytes or more defined in the
  file its own section; sp2p2 and earlier keep the file's objects in one section. Accesses at constant offsets go
  through the section, so an object under 64 bytes used by member and by address in one function takes two pool
  words on every build (which shows it is defined in that file), a bigger one takes two up to sp2p2 and one from
  sp2p3 (the same code as an `extern` object). Without `-ipa file`, C uses the symbol and C++ the section.
  sp2p3 and sp2p4 gave the same code on every comparison so far. Duplicate pool words found from relocations are
  mostly Thumb literal-pool islands: check that both words sit in one pool.
- `-str reuse` vs `noreuse`: identical literals in one file share one copy with `reuse`. One copy referenced by
  several functions shows `reuse` (literals are file-local).
- `-inline on,noauto` vs `auto`: calls within one file kept as `bl`.
- `-enum int` vs `min`: struct field offsets after enum-typed members.
- `-char signed`: `ldrsb` when walking a plain `char` table.
- `-Cpp_exceptions off`: new-expression codegen with a constructor.
- `-RTTI off`: no typeinfo slot before vtables.
- `-interworking`: leaf returns are `bx lr`, never `mov pc, lr`.
- `-proc arm946e`: DSP instructions (`smulbb`) present; `arm9tdmi` lacks them.
- Host: switch-table density exactly at the 0.4 threshold needs Windows' 53-bit x87 precision (the pinned wibo).

Probing tips: `tools/probe_compilers.py` strips `-O`, `-inline` and `-ipa` from the base flags because it varies
them, so spell them out (`--flags="-O4,p -inline on,noauto"`, plus `-ipa file` on 2.0 builds); it adds `-thumb`
when every probed function is Thumb and masks relocations per byte (a Thumb `bl` pair can straddle a word). Check it
first on one known match and one deliberate compile error.

## What 1.2 base never emits

Hand-written routines are kept as asm only where a rule of the compiler rules their code out. These were read from
the 1.2 base `mwccarm.exe` and checked under gdb and on compiled code:

- ldm/stm: the ARM backend builds them only when lowering the IR's block-move operations and in
  prologues/epilogues (`stmdb sp!`, `ldmia sp!`). The IR block moves come only from struct copies (lists upward from
  r0, the base moved to another register first, a lone word as ldr/str), struct zero fills, 8-byte copies
  (`{r2, r3}`, no writeback) and by-value struct arguments. Unrolled loads and stores are never merged. A hook on
  the instruction builders saw no other source.
- Thumb constants: 0-255 is `movs`, a complement or negation under 256 adds `mvns`/`negs`, anything else is a
  literal-pool load (gdb shows 0x1000 taking the pool path). `movs; lsls` is never built.
- Registers: after r0-r3 and ip the colourer opens the callee-saved registers in order; in a leaf ARM function lr
  comes before r4, in other functions lr is already a scratch register. Either way a function that saves r4 also
  saves lr.
- `tst`: built only by one peephole on `and`/`eor` that needs a flag set only on flag-setting forms, which that
  peephole isn't registered for; no compiled file checked built a `tst`, and C bit tests give `ands`.
- Tail calls: a call in tail position to a named function becomes `ldr ip, =callee; bx ip` (ARM, interworking;
  the register is fixed in the tail-call builder; r3 in Thumb); no other register is used.
- ARM constants: an immediate is `mov`, a complement immediate `mvn`, a negated one `mov` + `rsb`; only other values
  come from the literal pool, so -3 is never a pool load. No IR operation counts leading zeros and no
  code builds `clz`.
- Conditions: compiled comparisons use eq/ne/lt/lo/gt/hi/le/ls/ge/hs; mi/pl come only from the compare-with-0 fold,
  which deletes the `cmp`, so a `cmp` feeding mi/pl is not compiled code.
- `subs` with a carry test: the compare fold maps conditions to eq/ne/mi/pl only; `subs` otherwise appears only in
  64-bit arithmetic, so `subs; bcc/bcs` is not compiled code.

## Open

Settings not yet backed by an exact match.

- Game code: `-inline on` vs `off` vs the default. Thumb files in main call per-file out-of-line ARM copies of small
  register-writing helpers (placed after the file's functions, in reverse order of first use), while ARM game
  functions and some ov000 Thumb code have the same bodies inlined. No single setting with one form of the helpers
  explains both yet.
- Game ARM code: 1.2 base, sp2 and sp2p3 not separated (assumed to share the Thumb code's build).
- `-enum int` vs `min`: no probe separates them.
- Libraries (NitroSDK, NitroSystem, C runtime): the compiler build and every flag; no probe written from this ROM
  yet.
