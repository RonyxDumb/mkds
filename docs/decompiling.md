# Decompiling notes

Lessons for getting functions to match exactly. Compiler and flags: see `compiler.md`. Paths use the default version
`usa`; substitute yours.

## Workflow

1. Pick a function or file. `ninja dis` writes disassembly to read from into `build/usa/asm/`.
2. Write the function in a scratch file with a `// PROBE: <symbol> <module> <address>` line and compare it:
   `python3 tools/probe_compilers.py <file> --unit <the source path it will live at> --show` compiles it with exactly
   the compiler and flags the build uses for that path and prints a side-by-side diff (`*` = differs, relocated bytes
   masked). Without `--unit`, give `--only` and `--flags` yourself and spell out `-O` and `-inline` (and `-ipa` on 2.0
   builds; 1.2 rejects it), which the tool leaves to `--flags`. Probes mask call targets and literal addresses:
   check them against the original.
3. When only registers or stack slots differ, mark movable declarations with a trailing `//PERM` and run
   `python3 tools/permute.py <file> <function>`: declaration order sets the locals' numbering and so their colouring
   order (1.1); the tool tries the orders.
   `tools/auto_permute.py`, `tools/mutate.py` and `tools/permuter.py` search wider. Long searches run in the background.
4. Put the code in its translation unit under `src/` (or `libs/<name>/src/`), functions in address order, with an
   entry in `config/usa/arm9/delinks.txt` (see `CONTRIBUTING.md`): the source path, then one line per section it
   owns, and `complete` once it links from source:

       src/Main/Title.c:
           complete
           .text       start:0x02004a20 end:0x02004c48
           .rodata     start:0x0205f010 end:0x0205f0a4

   A unit's `.text` range starts at its first function and ends on a 4-byte boundary after the padding
   (`tools/check_units.py` checks both). Shared types go in `include/`, library declarations in
   `libs/<name>/include/`; each function has one declaration, with the definition's types
   (`tools/check_signatures.py`), and every call has a declaration in scope: the build's `-w off` hides an undeclared
   call, `tools/check_protos.py` lists them.
5. `ninja report`, then rename the original symbols to the names your code uses:
   `python3 tools/sync_symbols.py build/usa/<path>.o main --write`. It finds each matching function by its bytes and
   reads every referenced address from the original code (ARM and Thumb calls); identical candidates are settled with
   `--assume NAME=ADDR`. With several versions, run it for each (`DECOMP_VERSION=<ver>`): it refuses a name that
   already belongs to another symbol, so a name from the source can't land on a different object. Symbols your code
   references at a point inside a bigger original object are placed by
   `python3 tools/resolve_undefined.py <unit> --write`.
6. Statics of inline functions (`_ZGVZ...`, `_ZZ...`, e.g. singleton instances and guards) are defined by every file
   that uses them. Mark them `weak` in `symbols.txt`. Compiled objects get their copies demoted to weak
   (`tools/demote_multidef.py`, run by the build), so the original's copy wins when a file is linked.
7. Run `python3 tools/check_calls.py`, `tools/check_callees.py` and `tools/check_strings.py`: matching masks relocated
   words, so a function can match while calling the wrong function or loading the wrong string.
8. A function that doesn't match yet stays in its file with a `// non-matching:` comment saying exactly what differs
   (`tools/unmatched.py` lists every function below 100% in the report; `tools/clean_notes.py` removes the notes
   once they match). Files land like that, unlinked; linking can wait until a file's code is done.
9. Linking a unit whose functions all match: `python3 tools/try_link.py <unit>` (or `--libs`) runs the steps below and
   restores the config if anything fails.
   - `tools/link_check.py <unit>` checks the function order (mwcc 2.0 emits functions in source order, 1.2 in
     reverse, so under 1.2 a file defines its functions in descending address order: `emits_reversed` in
     tools/project.py; fix it with `tools/reorder_functions.py <unit> --write`) and that every compiled data section
     has a range in the entry.
   - `tools/data_ranges.py <unit> --write` finds those ranges from the relocations of matching functions. It refuses
     when sections disagree, land in the wrong kind of section (`.data` in the original's `.rodata`: the source has
     the const-ness wrong), come in a different order, or hold different bytes.
   - `tools/mark_complete.py <unit>`, `ninja`: the ROM must still match.
   - `tools/sync_linked_symbols.py --write`, then `ninja` and `ninja check`: inside complete units, `symbols.txt`
     takes the linked binary's names and bindings. Never run it after a failed build: it rewrites the config from a
     stale link.

When a unit breaks the ROM on linking, `python3 tools/diff_rom.py` shows where the rebuilt module first differs and
which pointers moved; read the differing pool words (a wrong table or field behind a masked relocation).

## Setting up a new game

- `dsd init` stops with "Local function call from X to Y leads to no function" when its analysis misses a target
  (a one-instruction `bx lr` function, code reached only through a table): set
  `DSD_INIT_FLAGS = ["--allow-unknown-function-calls"]` in `tools/project.py` and run `configure.py` again. The
  generated `func_<addr>_unk` symbols have size 0, and dsd then maps everything up to the next known function as
  ARM code: pointer words to Thumb functions in that stretch become ARM-to-Thumb references, the linker adds veneers
  (`ldr ip, [pc]; bx ip; .word`) at the end of `.text`, the module grows by 12 bytes per veneer and the ROM doesn't
  match. Read the disassembly at each `_unk` (`arm-none-eabi-objdump -D -b binary -marm --adjust-vma=0x02000000
  --start-address=<addr> extract/usa/arm9/arm9.bin`), give it its real size, up to and including its literal pool,
  and rename it to `func_<addr>` (`func_<ver>_<addr>` in a version other than the reference); dsd then maps
  what follows as data.
- If the build ends with a SHA-1 mismatch, `python3 tools/diff_rom.py` shows the size change, which pointers shifted
  and the first other difference. Thumb function pointers that now point at veneers mean a stretch mapped as code
  that isn't: look for a function before it with a wrong or zero size.
- Hand-written routines inside `.rodata` (a codec's code mixed with its tables) can keep function symbols, but dsd
  emits no `$d` mapping symbol for data symbols there: after a function, the linker reads everything up to the next
  mapping symbol as ARM code. Thumb code in the same delinked object that takes the address of data in that stretch
  then gets a Thumb-to-ARM veneer (12 bytes, `bx pc; nop; ldr pc, [pc, #-4]`) and the ROM grows. Code in another
  object is not affected, so the problem goes away once units split the gap. Until then, keep such a routine at the
  end of `.text` rather than at the start of `.rodata`.
- `dsd init` can end a hand-written routine at its first return and leave the code its branches reach outside every
  function (in this game, parts of the soft-float runtime at 0x02130380-0x02133670). Code outside a function can't
  be matched or scored: extend the function over the code only it branches into, include a literal pool its loads
  read, and give an entry stub that falls through into the next function a symbol of its own. Every non-zero byte
  of `.text` outside a function should then be data (tables, pools, the build info, the secure area's filler).
- "Call goes to middle of function" warnings from `dsd init` usually mean merged functions; some are real second
  entries (division routines' fast paths, long-branch `bl` inside large Thumb functions) and stay labels.
- `ninja dis` stops with "Inline tables must have a known size" when a data symbol of unknown size sits inside a
  function (dsd folds a literal pool placed before a function into it): give it a size, e.g. `kind:data(word[4])`.
- A game without overlays works as is: the tools fall back to the end of the main module's `.bss`.
- An overlay without code (only `.bss`, no `.text` in its delinks.txt) has no entry function to keep active;
  `tools/lcf_force_active.py` skips it and the link keeps it as is.
- Thumb game code: give `src/` (or the Thumb folders) `-thumb` through `PATH_ADD_FLAGS`; an ARM function in a Thumb
  file sits between `#pragma thumb off` and `#pragma thumb on`. `ninja objdiff` gives each unit its own compiler and
  flags.

## Source patterns that matter

Each rule reads "the binary shows X -> write Y, because Z". Tags say where a rule was observed: [sp2p2] on
CodeWarrior for DS 2.0 sp2p2 game code (`-O4,p -ipa file -inline on,noauto`); [2.0-all] also on 2.0 sp1p5 library
code; [SP-diff] differs between 2.0 service packs; [host] depends on the host running the compiler; [mwld] [dsd]
[objdiff] [mwasm] are tool behaviour. Untagged rules were seen on 2.0 builds and are probably general. This game is
built with 1.2 base (`compiler.md`), so check a rule against this game's code before relying on it.

### 1.0 Meta-rules (read these first)

- Which variables exist, where they are defined and what type they have moves registers and scheduling far more
  often than how an expression is spelled. Macro vs inline, ternary vs if/else, index spellings usually compile the
  same. Try variable structure first.
- Matching masks relocated words, so a 100% function can call the wrong function, load the wrong string, or point
  at the wrong field (`&banks[9]` vs `&banks[6]`). Run call/callee/string checkers; linking catches the rest.
- A one-word literal-pool difference is often a wrong constant (wrong divisor: `/ 24`, 182 vs 240), not a layout
  problem. A wrong constant can also masquerade as a scheduling difference when the original builds a value from a
  neighbouring constant (`mov r7,#34; sub r7,r7,#47` reveals -13 where the source said 3).
- Before fighting a caller's registers, check the callee's real signature: parameter widths, return type (void vs
  value), ignored parameters. Wrong callee prototypes were the single cause of several "unfixable" caller misses.
- Source that is dead only by the program's logic still reaches the backend and can move the scheduler or the
  colourer though it leaves no instructions: a store every reachable case overwrites, an unread zero initialiser of a
  variable that is read later, a product whose result is overwritten, an extra live value. What the front end removes
  outright never matters, so don't try it: locals that are never read, discarded expressions, empty inlines,
  self-assignments, `if (0)`, `do {} while (0)`, empty `asm` blocks. [sp2p2, traced]
- To see whether a register difference comes from scheduling or from allocation: compile with `-proc generic`
  instead of `-proc arm946e` (other flags unchanged); it skips the ARM9 instruction scheduler that runs before
  register allocation. Also shows stack-parameter copy order at entry.
- Don't change a shared helper (bit-test/set helpers, flag setters) to fix one caller: existing matches depend on it.
  Fix the caller's form instead.
- `#pragma scheduling` does not exist in this compiler; setting it changes nothing. [sp2p2]
- A function that really uses an object declared `__attribute__((aligned(N)))` skips the whole IR optimiser (one
  pass instead of ~100): no loop rotation, no strength reduction, globals reloaded from the pool. A dead reference
  does not trigger it. Useful diagnostic, and a hint if the original looks unoptimised.

### 1.1 Register allocation and colouring (mechanism, stated once)

Virtual-register numbering:
- Parameters first, then IR objects (named function-scope locals in REVERSE declaration order, so the first
  declared gets the highest number of them; IR @temps below them; nested-scope locals lowest), then expression
  temporaries in creation order. Named locals are numbered below every temporary (traced with gdb on the stock
  compiler).
Simplify/select (graph colouring, traced):
- Scans run over vregs in increasing number; each node with fewer conflicts than K is removed and pushed; scans
  repeat until empty (a stuck graph removes by lowest spill-cost/conflict ratio). Colours are handed out popping
  the stack: the LAST pushed picks first and takes the lowest free register.
- Consequence: between two nodes pushed in the same scan, the lower-numbered is coloured LATER. A rotation of
  callee-saved registers among a few values means they left the graph in different scans: count their conflicts at
  the scan where each is visited.
- Register choice for a popped node: lowest free of r0-r3; else a callee-saved register already handed out; else
  r12, then r14; else a new callee-saved register.
Practical consequences (lab rules on int-sized values living across calls):
- Named locals loaded from memory (or assigned later) are coloured in declaration order: first declared gets the
  lowest free register. Parameters go the other way round and after all locals.
- Values from calls (`int a = g();`) and loop invariants hoisted by the backend are coloured as temporaries, BEFORE
  named locals, in reverse creation order (first hoisted invariant / first call result gets the highest of them).
- Use counts make no difference; the shape of the live ranges (where the last use is) does.
- Under register pressure the value interfering with more others gets the lower register regardless of
  declaration order, which is why permuting declarations often does nothing.
- Declaration order sets registers; assignment order sets load order. Declare `a,b,c,d`, assign `b,a,d,c` if that is
  what the binary shows.
- Under pressure, initialisation order can swap a pair where declaration order can't.
- Types and order interact: search them together (one large update function matched only with `u32 id = (u8) x`
  AND a particular declaration order). permute.py supports `//PERM T=u8|u32|int`.
- `s16` locals colour differently from `s32` in otherwise identical code. Declaration order does not
  affect `double` locals.

Rules for "short-lived temp must share a callee-saved register with a long-lived value":
- When the original reuses a long-lived value's callee-saved register for a short-lived value once the long one is
  dead -> the long-lived value must be coloured first = higher vreg number = must NOT be a named local. Write it as
  an expression temporary whose arithmetic folds into its later use (`Entry *entries = mData->mEntries;` with the
  `+12` folding into the use, instead of `Data *d = mData; ... d->mEntries`). Routes that make the
  short-lived value a named local fail because the backend's copy propagation removes a local in a straight-line
  block.
- Declaring extra locals at function scope ahead of a call-surviving local can give the "original registers renamed"
  state (r4/r5 swapped with `this`): only two allocation states existed in ~6,000 variants; the fix was structural
  (previous rule), not ordering.

Colouring order by variable shape:
- A variable assigned in both arms of an if/else is coloured late (after `this`); a short-lived value per arm early.
- The same if/else inside an inline member that RETURNS the value gets the lowest register (`u32 v = Entry(i);`
  with the helper keeping `u32 v; if (...) {...} else {...} return v;`; an early return changes it).
- A value returned from an inline helper (or a block-local assigned to the variable) colours differently from
  assigning the variable directly. A variable left unset on some path is live from entry and gets low registers.
- Locals shared by two blocks colour as named locals: declaring `x, y, step` once at function scope and assigning in
  both blocks matched, where per-block locals were call-result temporaries.
- A block-local pointer gets a different register from a function-scope one.
- A local reused for an earlier, separate value: its later live range is coloured after the loop counter.
- Reused function-scope locals: later live ranges are coloured in the order variables first APPEAR in the function,
  not declaration order; a dead `j = 0;` near the top (or moving `g = 0;` up) reorders them. Separate variables still
  go by declaration order ahead of those ranges.
- A local reassigned to an unrelated value that lands in another register was two variables in the source.
- A global read repeated inside a loop is hoisted and coloured after named locals and loop temps (higher
  registers); a named local copy is coloured early.
- Through an inline accessor a field read becomes a temporary: `o->Entries()` vs `o->mEntries` moved a pointer
  r5->r6; `Item(n)` (inline, compiler temporary, coloured before named locals) vs `mItems[n]` (coloured like a named
  local).
- A load folded into an address is a temporary: `e = &o->mItems[o->mIndex]` colours the index before `o`; as its own
  statement (enum-typed copy) it is coloured after `o`.
- `*q++ = x` vs `*q = x; q++;` moves `q` to the end of the order. Write post-increments as separate statements on
  the pointer they move (`*base = *r; base++; r++;`). Counter-example: `a[n++] = 0;` computes n+1 before the store
  and needed the folded form; `x[n] = v; n++;` vs `x[n++] = v;` schedule differently. Try both.
- A value that is also returned is forced into r0: `return g = &x;` gives a different order from a plain store.
- `T *p = tbl; ... e[id]; e += id;` (pointer created before the index load) colours differently from `e = &tbl[id]`.
- Reading components into named locals in the original's order (`z = p->z; y = p->y; x = p->x;`) fixes load order
  before a call.

More operand/pointer-shape rules (game code):
- `p[c]` vs `p += c; *p`: indexing in place loads the other operand first.
- Advance the pointer, then read past it: `p += idx * 2; y = *(s16 *)(p + 2);` gives a different register pair than a
  second `p + idx*2 + 2` expression.
- Store, then scale in place: `d->x = FX_Mul(s->x, len); d->x = FX_Mul(d->x, k);` colours differently from one
  expression through a temporary.
- Indexing in place vs a pointer local: `owner->mSlots[i].x` written inline instead of through a `slot` local fixed a
  register difference. Index a table with the global field in place (`&tbl[g.a]`) rather than through a named
  copy of the index (seen in C runtime code).
- Named pointer locals change what survives calls: `T *p = (T *) &g;` (initialised WITH a cast) addresses `g` through
  its own symbol and keeps the base (or a shared base like `this + 0x6000`) in a callee-saved register across calls.
  `T *p = &g;`, `g.f` and a cast written at each use all address an in-file `g` from its section base and reload it
  after each call [sp2p2/sp2p3, ARM and Thumb, tested]. A struct-typed table indexed directly and a field read
  through `Get().mField` are temporaries where a named local is not.

Coalescing [sp2p2, traced]:
- Greedy: blocks and instructions in order; each copy whose two sides don't interfere is folded into the
  LOWER-numbered register and deleted ("keep vA drop vB").
- A conversion temporary (narrow value passed to a wider parameter) can coalesce with the local, which then takes
  the temporaries' register whatever its declaration order. Fix the callee's parameter type: u16 parameters made a
  `u16` local a named local again; an `s16` third parameter let two callers match by declaration order alone.
- A `u8` passed to an inline with a 64-bit temporary (`MATH_Rand32`) merges into it, so its declaration position
  doesn't matter.

### 1.2 Local CSE, copy propagation, constant handling (backend)

- The backend's first local CSE forwards a local's copy into every use in the same extended basic block (its block
  and the following single-predecessor blocks); DCE then drops the copy and the local has no register of its own. It
  survives only when a use lies in a block with two predecessors, a call between kills the value (memory-dependent
  values only), or the copy's source is a physical register (parameter copies). Several definitions alone don't keep
  it. [sp2p2, traced]
- A call result kept in a local loses its name: inside the call's extended basic block (the call's block plus
  following single-predecessor blocks) every use is replaced by the call's result temporary (numbered after all
  locals, coloured on its own). The local keeps the value only if one use sits in a block with two predecessors.
  A repeated identical test `a || a` creates such a block for free; after colouring, head/tail merge and the
  conditional optimisation drop the repeated compare. A different-looking second test (`n >= 1` after `n > 0`)
  keeps its compare. Such a repeated test is a placeholder: mark it as one.
- Expression propagation (IR) substitutes a single-definition local into its uses: always when its right side is a
  plain operand or a direct object read, otherwise only when the local is used in one statement. It looks at one
  block only, so a value used in another block keeps its statement (the backend may still forward it, rule above).
  [sp2p2, traced] Substituted values are hoisted out of loops where invariant; passed straight as a call argument
  they are recomputed instead. A local assigned twice (`s32 left = c; left += b;`) is not substituted and is computed
  where written (e.g. an inner loop preheader).
- Reusing one variable for two arguments pins the first one's evaluation point (a game function matched only with a
  local reused for its third and fourth arguments).
- A value whose only consumer is one later call is substituted into that call; a compound assignment or a later read
  keeps it in place.
- `T *p = o->a; p += o->b;` pins the computation where written (not substituted into a call argument). A pointer
  built by `p = base; p += idx;` is not substituted, so identical `base[idx]` accesses elsewhere don't share its
  address; only `idx*size` is shared and the base re-added at each use (`ldrh r0,[r6,r7]`). `&e[idx]` / `e + idx`
  shares the whole address.
- A pointer local can hoist shared index arithmetic over a branch: `T *e = list->mItems[p];` makes `p*4` a CSE with
  a later `p*4 + 0x28` and it is hoisted above the `if`. Index the container inside each arm to stop it.
- Repeated identical reads: the compiler shares a repeated field read (only when no real call sits between the
  uses); a named local copy vs repeating the access moves register pairs. Reading a const table at each use (reads
  are merged even across calls) can give the original order where a named local takes a register too early.
- Re-read instead of caching where the original reloads a table element or global chain in a loop. Re-reading a
  global chain (`g.list->mItems[k]->a + g.list->mItems[k]->b`) forces fresh loads; a named pointer lets the compiler
  reuse earlier ones.
- Where a shift sits matters: `fx32 d = f(...) << 12;` then `FX_Mul(d, k)` matched; shifting inside the `FX_Mul`
  argument did not.
- Recompute differences instead of naming them: `x0 - x1` written out at each use matched where
  `dx/dy` locals did not.
- Reading a member directly (`mData->x`) rather than through `T *data = mData;` makes the pointer a temporary; it is
  still loaded once when no store or call intervenes.
- A pointer saved in a local before a store fixes pool-load order; fields loaded into named locals
  before arithmetic fix field-load order, then try both operand orders.
- Store forwarding: through a singleton reference a stored member is NOT forwarded to a later load, but a store
  immediately followed by a reload of the same member through `this` is (`mData = data; data = mData;` emits no
  load). A pointer taken from a member just after storing it (`mUnk_40 = data; entries = mUnk_40->mEntries;`)
  schedules where `data->mEntries` does not.
- A leftover `mov rX, rX` means a store followed by a read-back of the same field (`g.mode = m; ...; if (g.mode<=1)`).
- `if (field)` right after `field = var;` compiles to `tst #255`. Store first and test the field (`f = g; if (f)`)
  rather than `if (g & 0xff)`.
- `u8 now = ++field;` gave `add; and; strb` with no reload where `field++; now = field;` reloaded (one function:
  the value is tested, then passed to an inline that writes hardware registers). In a small test without that
  context both forms compiled the same, so try both.
- A constant stored to a member and read back stays a run-time computation (`mUnk_38 = 0x20; mUnk_38 = (0x6c -
  mUnk_38)/2 + 0x1e;`); from a local it folds. Likewise `n = 8; f(n*12);` via memory keeps
  `mov #8; mov #12; smulbb`.
Constants held in registers:
- The backend reuses a register already holding a needed constant within an extended basic block (`mov rd, rs`, or
  `add rd, rs, #(K-C)` from a nearby constant). Knowledge passes only into single-predecessor blocks (a join, even an
  if-converted one, clears it; a call does not clear callee-saved registers) and only if the constant's definition
  comes first. So `i = 0;` after an `if (n > lim) n = lim;` clamp gives `mov r5, r6`; before it gives `mov r5,#0`.
- A variable updated by compound assignment keeps its constant start value in a register (`int r = 0; r += 0xe0;`
  -> `mov r2,#0; add r3,r2,#0xe0`); other uses still fold.
- Enum-typed locals are NOT constant-propagated. When the original keeps a known constant in a register and
  computes with it (`mov r2,#0; mov r1,#52; smulbb r4,r2,r1` for `array[0]`), use an enum-typed local. An enum-typed
  zero stays in its register through a loop of byte stores (`enum {ZERO} z = ZERO; p[k] = (unsigned char) z;`, the
  cast avoids sign extension); plain int zeros fold back.
- Several zero-initialised locals share one `mov rN,#0`, put in whichever is ASSIGNED first; later ones become
  `mov rM, rN`. Use declare-then-assign to choose. `s32 a = 0, b = 0, c = 0;` as ONE declaration lets the zeros
  share one register where separate declarations (or `= a`) don't.
- Two u8 zeros sharing a register can steer the scheduler; a `u32` counter with a `(u8)` wrap stops the sharing.
- A dead store can be load-bearing: `n = 30;` before a switch whose reachable cases all overwrite it (the compiler
  can't know which are reachable) keeps 30 in n's register for later calls with 30.
- Mixing signed and unsigned stops constants combining: `t + 0x24 + 0x28c0u` keeps two adds.
- Compound assignment keeps constants out of folding: `angle += 90;` / `fx *= 2.0f;` differ from `angle = angle + 90`
  (constant not folded, variable stays first operand of the float multiply).

### 1.3 Scheduling (pre-colouring and post-colouring schedulers)

- Two list schedulers (one before colouring, one after). Pick order: instruction whose latest start time has
  arrived; then the one making the most successors ready; then the taller; then list (source) order. Ties = source
  order, so statement placement decides ties.
- Pre-colouring scheduler under register pressure: once live values reach the limit it picks by a pressure score
  (start 16; each last use subtracts 1 + max(1, live - limit); each new value adds max(1, live - limit)), keeping
  source order on ties. [sp2p2, traced]
- Memory-dependence edges come from alias classes set by what defines the base register: an integer-constant base
  (hardware register `*(vu16*)0x04000300`) gets the worst-case class and is ordered after every earlier global store,
  whatever volatility/casts; a base from a symbol (`lda &sym`) gets that symbol's class and can pass stores to other
  objects. When the original reads a hardware register ahead of an earlier store -> declare the register as an extern
  object and pin its address in the linker script (alias line).
- Out-of-bounds rule (2.0, read from the compiler): a direct access to a global gets the worst-case alias set when
  offset + size runs past the declared type's size (incomplete arrays `T x[]` excepted); a worst-case store is
  ordered against every later load and store. Within bounds, all members of one object alias each other and
  different objects never do. So when a store seems to pin a later load, check the declared size: an object
  declared too small pins its stores past the end, and its real size frees them. The pool-word anchor can't tell
  a member of a big object from a store past a smaller object's end; this scheduling difference can.
  Exact form (from the compiler): a Thumb access re-anchored to obj+A (A = offset & ~imm range) is checked as
  A + offset + 1 > declared size, so in a big object every access far enough in is already worst-case and the
  declared size only decides accesses below about half of it. Of the out-of-bounds spellings only `obj.arr[k]` /
  `&obj.arr[k]` with k past the end folds into the pool word and anchors like a member; casts compute the address
  at run time.
- Globals: a store through any pointer makes the compiler re-read a global declared with a complete type
  (`extern T g;`, `extern T g[1];`) but not one declared `extern T g[];` (kept in a register / hoisted). Give globals
  their real size (pad a struct to the size its block has in the binary). Loads through a pointer local die at any
  global store; loads written as `g[i].f` don't.
- const-ness: loads from `const` data may move above stores (and stack-argument stores), non-const may not. Declare
  read-only externs const (pointer tables `const char *const`). [2.0-all]
- A function-local static table schedules like const data (no store can reach it, loads move above stores) while
  staying in `.data` (file-scope const would move it to `.rodata`). Symbols are `name$N`.
- `abs` (and other functions) declared in a header named stdlib.h are treated as pure: calls with the same argument
  merge, even across stores. Declare it in a project header when the original calls it repeatedly. In ARM code an
  `add sp` was seen scheduled before global stores at a return (the Thumb epilogue rule above is Thumb-only).
- Epilogue order: a store just before a return is scheduled after `add sp, #N` only when it targets a function-local
  static whose address is never taken. The pop's memory alias is every non-const global the function touches,
  file-scope statics included; a local static is left out, so its store loses the memory edge to the pop. A store
  through a register the pop restores gets the same order another way. [2.0 sp2p3 Thumb, tested]
- Volatile: a field/param re-loaded where the compiler would reuse or hoist it is volatile in the original (tick
  counter, file flags). A store followed by a reload of the same field is not by itself a sign. In small C and C++
  tests with nothing between the store and the load (2.0 sp1p5, sp2p2, sp2p3): Thumb code reloaded every byte
  (`strb; ldrb`) and halfword and reused words; ARM code reused bytes (`strb` then `and #0xff`) whether the value
  was a parameter, a computed value or a call result, reused words, and reloaded a halfword parameter. In Thumb code
  `strb; ldrb` is normal; in ARM code look for what sits between (a call, an aliasing store) before calling the
  field volatile. A volatile field can pin a load where it is formed (a text offset field made volatile pinned its
  load right after the file pointer and fixed the register allocation of a whole argument setup).
- Arguments with side effects (volatile read, `x++`) are evaluated before the stack-argument stores and other
  arguments; side-effect-free arguments are folded into the call and loaded after the stores, because the scheduler
  never lifts a `[this]` load above a `[sp]` store. An enum-typed copy plus a named reference can give the same
  effect.
- A u16/s16 local or stack parameter is spilled to a full 32-bit slot; its spill stores/reloads use the worst-case
  alias set, so they are ordered against each other and the post-allocation clean-up won't reuse a register value
  across them. A parameter's/local's width moves both scheduling and copies (u16 and s16 parameters of a text
  printing API; a u16 value and u8 flag that also needed the callee's parameters to be u8).
- One more live value across a loop changes the loop body's schedule even if it leaves no code (`const u8 *mode =
  &g;` reloaded from the pool).
- Ties between equally ready instructions go to source order, so moving a statement within its block (or adding a
  call before it) can flip them.
- Narrowing changes scheduling, not just instructions: `-(u8)(m/4)` vs `-((u32)m >> 2)` emit the same ops,
  but the u8 form schedules `rsb` before the next pool load.
- Equivalent arithmetic inside a long sum (`y%8 << 3` vs `y%8 * 8`, `(y/64)*8*512` vs `(y/64)*4096`) schedules
  differently; term order doesn't matter (sum is re-sorted).
- Repeated calls with constant arguments schedule in a cycle (20 identical calls: pattern repeats every 7; period
  10/8/7/6/6 for 1-5 stack args). Code before the run shifts the phase: a global store, or a call that returns a
  value (void shifts less). Several "open" cases were one cause: a BOOL-returning callee declared void.
- Spill reload vs mov: when a spilled value's register is still intact at its next use in the same block, the reload
  becomes a `mov` (or is dropped). A use directly after the definition reuses the defining register (`mov r5,#0;
  str r5,[sp,#n]`); with an instruction in between it reloads and the clean-up turns store-then-load into a copy
  (`mov r0,#0; str r0,[sp]; mov r5,r0`). How the variable is built (`s16 x = base; x += off;` vs `x = off + base;`)
  and statement order move this.
- A zero shared by two spilled stores keeps its own register (`mov r0,#0; str; str; mov r5,r0`); one spilled zero
  before a loop lets the counter take it over (`mov r5,#0; str r5,[sp]`).
- A spilled `s32` whose register still holds the value at a predicated early return has its reload dropped; as `s16`
  (still word-stored) it keeps `ldrcs r0,[sp]`.
- A spilled u8 local holding a call result is reloaded before each compare of a switch chain; an int isn't. A spilled
  u16 local is reloaded before each store of a shared zero; s32/u32/int share one register for all the stores.
- Store order: `Set(mUnk = value)` (chained assignment as argument) schedules the store differently from two
  statements. Compute all sums before storing (`u16 y = o->mRotY + r[1]; ...; o->mRotX = x;`); `o->mRotY += r[1]`
  interleaves loads and stores.
- Create the first operand early and add the second late (`u16 rx = p->mRotX; ...; rx += r[0];`) to get reverse-
  creation register order.
- `x*3+y` vs `x + x + x + y`: only the spelled-out sum matched a set of animation blends (`(s64) x + x + x + y` for
  32-bit).
- Product order: `a*b + c*d` evaluates the right-hand product first; reverse the terms to swap. [2.0-all]
- Chained assignments `a = b = c = k` store right to left and change which register holds the constant; in
  constructors `a = b = 0;` reproduces reload-and-truncate (`ldrb`/`and #0xff`) sequences.
- Post-increment reads: `s += *w++ * p[x];` keeps each address add next to its load; `w[2*k]` with `w += 16` after
  groups the adds.
- Identical first instruction in both arms of an if/else (same registers) is hoisted above the branch AFTER register
  allocation: not source-level CSE, so source forms can't stop it; the original avoids it only by different
  registers per arm.
- `mov rX, rY` just before a load through rX with rY live can be a second identical load turned into a copy by
  post-allocation clean-up; reading through a `const T *` (const-param inline helper) keeps that second load apart.

### 1.4 IR optimiser behaviour

- Loop-invariant hoisting: the IR hoists invariants out of loops into the preheader; the backend has its own
  invariant pass that puts hoisted values in a block of their own just before the loop (after the preceding block's
  code). A value assigned inside a loop is loop-variant to the IR, so `d2 = delta; shift = d2*d2/8;`
  inside the loop leaves it for the backend's pass; a pre-loop form is hoisted by the IR and scheduled differently.
- Loop-invariant expressions are hoisted out of an OUTER loop only when bound to a local; write them inline in the
  inner loop condition to keep them in the loop.
- Pointer local placement: `T *xb;` declared with other locals and assigned just before a loop puts the address
  computation before the loop guard; `((T*)&x)[k]` at each use puts it after; initialising at declaration recolours
  the whole function. A named `char *q = (char*)&x` gives indexed `q[i]` loads; the cast expression form is strength-
  reduced to a running pointer. [2.0-all]
- Through a pointer local a flag array's address is hoisted (pooled, coloured) before a table read only in the loop
  condition; used directly it's hoisted after.
- `(u8 *) g[0].member` keeps aliasing with `g` (and the direct hoist order) where an extern alias for the same bytes
  doesn't.
- A table offset as its own variable before the bounds check (`u32 pos = id * 0x20; if (pos >= size) ...`) gives the
  separate shift the original has. [2.0-all]
- Indexing through a pointer-to-array type (`int (*t)[3][32]`) recomputes `t + k*4` each iteration where a
  running pointer is strength-reduced.
- Reassociation: `tbl[k*3 + byte]` is reassociated into a hoisted `tbl + byte`; `const u8 *p = tbl; p += k*3;
  p[byte]` stops it.
- A dead product still shapes code: scaling all three components before overwriting one matters.
- `x % 300` and `x - x/300*300` compile differently (different smull use).
- A declared 2-D member builds `j + row`; a cast to 2-D (`((u8(*)[2]) flat)[i][j]`) builds `row + j`. Use a union view
  with a real 2-D member.
- `u16 *` indexing keeps an index update in place where byte-pointer arithmetic lets it sink past calls; a local
  reassigned in place (`cx += width;`) keeps its register.

### 1.5 Loops

- No pre-test (`cmp; bls`) before the body -> `do { } while (k < count);`, not `for`.
- Entry test inside the body (back edge jumps to a `count != 0` guard) -> do-while with the guard as an `if` inside.
- `if (n) { i = 0; do ... while (++i < n); }` has one guard; a `for` keeps a second `cmp/bls`.
- One function-scope loop counter (`u8 i`, maybe `j`) reused by every loop is the common original form, even where a
  loop counts down; per-loop counters colour differently and no declaration order fixes it. A shared counter is
  coloured above a hoisted singleton address, per-loop counters below. When two counters step together the order of
  `j++; i++;` matters.
- `u32 k = 0; ... k = (u8)(k + 1);` fixes counter/coordinate swaps where `u8 k` fails in every order; also a counter
  passed to a 64-bit-temp inline matched as `u32 n` with `n = (u8)(n + 1)`.
- `unsigned long` loop counter vs `unsigned int` (different types to the compiler): matched once in game code; it
  depends on the variable's own type, casts change nothing. A sweep over 39 near-misses helped none, so it's rare in
  game code. In C middleware `long` locals and parameters matter much more (`long i` turned `mul` into `smulbb` and
  fixed a stack frame and temporaries): try `long` early in such libraries. It only matters where it creates a
  mixed-type expression. [2.0-all]
- `(n + 1) * x; ...; n++;` keeps the unmasked `n + 1` in the multiply.
- A pointer declared before a loop and assigned inside it (`e = &list->Items()[i];`) fixed a base/element swap.
- A struct copy declared inside a loop block stays an `ldm/stm` copy re-read from the stack; at function scope it's
  decomposed into registers.

### 1.6 Switches, branches, predication, selects

- Switch layout: cases sorted, merged left to right into jump-table clusters while count/range >= 0.4 (computed in
  x87 floating point); the tree root is item (lo+hi)/2. A density of exactly 0.4 (12/30, 2/5) is decided by host x87
  precision: run the compiler with Windows' 53-bit precision (wibo from commit e8f4795+, not 1.2.0). [host]
- Gaps in a jump table that lead to a label inside the switch are case labels the source is missing, not default.
- `x == 0 || x == 2 || x == 3` folds into a range check; `cmp #0; cmpne #2; cmpne #3` came from `switch (x) { case
  0: case 2: case 3: }`. Write `||` chains in the original's test order.
- `switch` instead of an if-chain stops predication of the arms. A two-case `switch` gives a beq chain with case-0
  block out of line where if/else-if predicates.
- Explicit nested ifs setting a BOOL keep a branch that a ternary or selected u8 would predicate.
- `else { return x; }` keeps a branch where `if (!c) return x;` predicates. Conditional early returns `bxeq/bxcs`:
  `if (x != 0) { x = 0; return TRUE; } return FALSE;`, `if (id < N) return table[id]; return 0;`; inverted forms
  predicate.
- Guards branching to one shared `mov r0,#0` exit are nested ifs with a single `return 0` at the end; early returns
  become predicated `movne/popne`. Two early `return i;` -> `goto found;` to one `found: return i;` after `return 0;`
  gave the original branch shape.
- The compiler predicates the ELSE arm: in an if/else whose predicated arm branches over the other, the predicated
  arm is the source's else.
- Identical trailing statements in both arms are merged into the join; identical setter calls in both arms are
  merged after the join; duplicated CALL tails are not merged. Write statements in both arms when the original keeps
  them there.
- A helper called with a different constant per arm is compiled per arm and merged into `moveq/movne` only after the
  first scheduling pass, so a later call's arg setup isn't moved up.
- 0/1 selects always put the 1 first: an int/bool select between exactly 0 and 1 (`x ? 1 : 0`, `x != 0`, `!!x`,
  if/else assigning 0/1 to a local, inline `return x != 0`) becomes `movCC #1; movNCC #0` regardless of source order.
  `#0`-first comes from: a select of two enum constants; if/else storing straight to memory in both arms; a variable
  with other definitions; or constants other than {0,1}. `b = 0; if (x) b = 1;` gives `mov #0; movne #1`.
- `if (c) { x = 0; } else { x = 1; }` as statements can give `moveq/movne` order that `x = c ? 0 : 1` reverses.
  `x == 0 ? 3 : 2` vs `x ? 2 : 3` swaps `moveq/movne`. `mode == 0 ? a : b` if-converts (predicated loads) where
  `mode != 0 ? b : a` branches.
- `f = c != 0 ? tbl[i] : g;` branches; `if (c == 0) f = g; else f = tbl[i];` predicates both arms.
- Bool stores: `if (x) { f = 1; } else { f = 0; }` computes into the result register and stores before the
  return-value move; `f = x != 0;`, `?:`, `!!` don't. Bool-returning inline getters: `bool r = false; if (cond) r =
  true; return r;` matches where `return cond;` doesn't.
- Repeated identical test `a || a` creates a join block that is later removed (see 1.2; placeholder).
- Predicated `movCC/strCC` right after a `bCC` on the same condition is a dead re-test inside the branch (`if (x <= K)
  { if (x > K) x = 0; }`): keep it.
- An `&` chain no single expression reproduces: `BOOL lo = (a >= 0) & (b >= 0); if (lo & (a < 0x100) & ...)`.
- Two loads before two compares: an enum-typed copy of a field read is a real load at its declaration and isn't
  substituted into the compare, so `Mode a = (Mode) x.mMode; Mode b = ...;` (`Mode` an enum type) keeps both loads
  ahead of the tests (~60 int-typed forms failed).
- An enum-typed result stops the return being folded (an enum-typed `result` kept `return result` that `u32` folded
  to `mov r0,#0`).

### 1.7 Constants and literal pools

- `mvn rX,#0` stored to a byte -> the field is signed (`s8` = -1).
- A negative constant stored with `strh` built as `mov r0,#0xe000; sub r1,r0,#0x12000` (0xffffc000) can't come from a
  u16 field (every form folds to 0xc000): the lvalue was signed 16-bit (written as a cast placeholder when the
  field's type can't change).
- A register-form `and` with a pool-loaded mask comes from division plus u16 truncation
  (`u16 v = (x & 0x1fff) / 0x200;`); a shift pair would fold.
- On u16 values `/ 32` emits `lsr`, `>> 5` emits `asr` (promotion to int); on a signed value `f / 8` gives `lsr`
  sequence vs `f >> 3` `asr`.
- Two literal-pool entries for one address: two relocations (different symbols or symbol+offset) resolve to the
  same address. Model it with a second extern name for the same address; really it means the statics' layout isn't
  understood yet.
- Constant offsets into an object in a file's shared data section are addressed from the SECTION BASE (re-anchored at
  `off & ~0xff` for strh, `& ~0xfff` for str), so two tables can share one pool word; taking the address as a value or
  variable indexing keeps the symbol. See 1.12 for which objects get their own symbol.
- A struct member at the head of an array element (`mItems[k].mHead = ...`) folds the element base into the
  offset; `*(T*)&mItems[k] = ...` hoists it.
- A cast on the address swapped address and value registers in a read-modify-write of a global in game code:
  direct access coloured the address first; the cast form gave the value the lower register and its own pool word.
  In a small test a cast written at each use compiled exactly like direct access; a pointer local initialised with
  a cast (`T *p = (T *) &g;`) did change the addressing (see 1.2, "Named pointer locals"). Try both.

### 1.8 Types, casts, narrowing, enums, volatile, const

- `-char signed`: `ldrsb` on a string walk means plain `char`.
- Return types show in callers: enum return gives `movlo #0; movhs #1` at the last compare where BOOL gives the
  reverse; a BOOL stored into a u8 field gives `ands rX, r0, #0xff` before the store; a u8 return removes the caller's
  `and #0xff`. In a function returning u8, `u8 r = c >= x; return r;` has no final `and`; a BOOL local does.
- Declare return values: a callee declared void that really returns a value changes callers' allocation AND
  scheduling (ties). Declaring the true type fixed runs of callers (a function returning offset + size, another
  returning BOOL). Conversely a tail-call function whose callers all ignore the result may need to be void to keep
  another caller matching (a judgement call: mark it as a placeholder).
- Arguments a callee ignores: if callers load a register (e.g. `this` into r0) that the callee never reads, the callee
  still takes that parameter; removing it makes callers 8 bytes short.
- Parameter width shows in the caller: passing u8 to u32 makes a conversion temporary that shifts registers.
  `lsl #16; asr #16` on an argument -> caller's variable was s16. A caller passing an `ldrsb` value with no `and` means
  the parameter is wider than u8. `(u8)` casts at call sites often stand in for the callee's real parameter types.
- Implicit narrowing at a short parameter is not shared between calls (original keeps `x + 4` as int and narrows at
  each call, hoisting narrowed stack args in source order); an explicit `(s16)` cast passed to s32 IS shared. Get the
  callee types right and drop the casts. `(s16)(int)(y - 8)` stops sharing (placeholder form).
- A u16/s16 stack parameter is loaded at the top of the entry block; a 32-bit one sinks to its first consumer. Helps
  only when every consumer has the same narrow type (mismatch adds a conversion temp and 8 bytes of frame). A u8
  stack param is loaded first in the prologue; BOOL puts it later.
- A stack parameter the callee reads as a narrow load while all callers store a full word: declaring it narrow breaks
  callers (they add an `and`). If the callee reads `*(s16*)&param` it really is s16 (declaring so made callers narrow
  late and matched). Otherwise `*(u8*)&param` is a placeholder.
- A signed compare (`bgt`) on an `ldrh` value means `int v = field; if (v > K)`; comparing the field gives `bhi`.
  Unsigned bitfield compares are unsigned (`bcc`); `(s32) bf >= 2` gives `blt`.
- An index the original masks with `and #0xff` at each use was not a u8 local: write the expression at each use.
- `x *= 10; x &= 0xffff;` keeps a call result and its narrowed product in one callee-saved register (`movs rN,r0`);
  `x = (u16)(x*10)` splits them. Narrow read-modify-write toggles: `f++; f &= 1;` on a u8 field as two statements.
- A `(u8*)` cast store recolours differently from a real u8 field store.
- Byte array really an array of small structs: struct indexing stops address sharing across a call. A two-byte `{x,y}`
  struct instead of `u8[2]` keeps a table out of its own section (see 1.12).
- Separate globals, not a struct: count/head/free/tail bytes matched only as five globals (struct accesses reorder
  across each other). Several file-level `static u8` are addressed from one .bss base like a struct but schedule
  differently; their offsets follow declaration order under `-ipa file`.
- `-enum int` vs `-enum min` shifts struct field offsets after enum members (evidence for the flag: docs/compiler.md).
- Enum-typed copies/locals are a general tool: not const-propagated, not substituted into compares, real loads at
  declaration, change colouring order of an index relative to its base (u8 index coloured after its base).
- `NitroSDK u32` is `unsigned long`; a project's own `u32` may be `unsigned int`; these differ to the compiler.

### 1.9 Calls, parameters, stack arguments, frames

- Spill slots: spilled parameters take the lowest stack slots in parameter order; spilled named locals go above them
  in reverse declaration order (first declared = highest slot); a spilled compiler temporary (e.g. a merged repeated
  global read) sits just above the parameters. Function-scope stack locals get slots in descending declaration
  order. In the functions matched so far the spilled locals were the ones declared first (observed, not traced). A
  local that won't take its slot may need to be a repeated expression.
- Declared before, computed after: declaring `b/bLevel` before `a/aLevel` but computing the `a` chain first changes
  which value is spilled, independently of either order alone.
- Stack-parameter copies: emitted at entry in parameter order (`-proc generic` shows it); the arm946e scheduler moves
  a copy early only when its loaded value has a consumer in the same region. A local with two definitions sharing the
  parameter's home slot pulls its copy early; narrow param widths put that copy at the top.
- `stm` where the original has two `str`s for stack args: declare the flag without an initialiser and assign only in
  the arm that needs it, passing literals in the other.
- A parameter moved into r1-r3 at entry and kept until a later call is usually that call's argument in that position
  (a missing `%d` argument looked like a register problem).
- By-value struct parameters: modify fields in place (`spec.prec -= 2`), don't copy to locals (changes spill slots). A
  `double` parameter saved in a local puts its argument loads at entry, above an early return.
- `T a[2] = {0,0};` / `VecFx32 v = {0,0,0};` store through an `add rN, sp, #off` base; separate element stores, field
  stores and setter calls use sp offsets.
- A local array filled from a one-use rodata table is an aggregate initializer (`u8 buf[3] = {0,1,4};`): it emits an
  anonymous rodata object (often first in the unit's .rodata) and changes temp creation order; element-wise copy
  doesn't match.
- Struct copies: where the original loads every component before storing (often `ldm/stm`), fill a local temp (z, y,
  x) and assign `*dst = t;`. Three u16s assigned as one object (`*(Vec3u16 *)dst = *(Vec3u16 *)p->mRot;`, a struct of
  three u16) load all three first.
  A struct copy initialised at its declaration stays ldm/stm; assigned later it is split into fields. Inline setters
  compute all values before storing; write-backs through them load the owner pointer once. A scalar argument of an
  inline setter is loaded before the struct copy in its body.
- Float compared with an int: keep the float expression in a helper returning float and cast at the compare (`(s32)
  ToFloat(n) < x`): evaluates float, then left side, then `_ffix`.

### 1.10 Inlines, macros, intrinsics

- A macro where an inline won't do: a bit-test macro lets the compiler reuse the loaded byte for a following set,
  which inline helpers don't.
- Write SDK inlines and macros as inline functions/macros under their API names (FX_Mul, FX_F32_TO_FX32, MATH_Rand32,
  FS_GetLength, OS_SetIrqCheckFlag, G2S_SetBG1Priority...): their multiple evaluation and casts show in codegen.
- Inlined SDK setters appear as a 36-byte copy followed by calls (NNS_G3dGlbSetBaseRot/Trans/Scale; MI_Copy36B).
- `__clear(ptr, size)` (aka `__builtin__clear`) is a CodeWarrior intrinsic: `mov r0,#0; mov r1,r0; mov r2,r0;
  mov r3,r0` and an `stm lr!,{r0-r3}` loop. `memset(p,0,n)` compiles to a call; a zero-initialised struct goes through
  the stack.
- `__memcpy(dst, src, n)` is an intrinsic too: inline `ldrb/strb` pairs (source in r3), unlike `memcpy` or struct
  copies.
- With `-inline on,noauto`, same-file calls stay `bl`; `auto` would inline them (identification evidence).
- Element access through accessor methods (`Elem(i)`) is common for arrays inside singletons.
- An inline's wider parameter can turn a local into a temporary (conversion temp coalesces with it; see 1.1).
- An inline identity (`template <class T> inline T Id(T x) { return x; }`) around an operand changes code: around a
  field read it moved the value to another register and split an `ldm`; around an argument it moved the argument's
  load ahead of an earlier call (2 of 5 test functions changed; sp2p2 and sp2p3, ARM and Thumb). permuter.py tries it
  in C++ files. A placeholder unless a real inline helper of the same shape exists.

### 1.11 C++: constructors, destructors, vtables, new/delete, singletons, static init

C++ only: this game's code is C (`compiler.md`).

- Singleton pattern in the binary: `if (!(guard & 1)) { ctor; guard |= 1; }` = a function-local static in an inline
  accessor (`static T &Get() { static T i; return i; }`). With `-ipa file` the guard and object are shared across
  modules (weak/multidef), so keep one definition. `__register_global_object` appears when T has a destructor; its
  12-byte chain node lives in the calling file's `.bss`.
- `T &a = T::Get(); T &b = T::Get();`: the address from the second guard block is kept in a callee-saved register and
  serves `a`; uses of `b` reload from the pool. A single reference reloads at every use.
- A pointer kept only part of the way and then reloaded from the pool = a second `Get()` (a fresh `T::Get()` at the
  reload point took one large function from over a thousand differing words to 0).
- `new T(args)` emits a null check around the constructor call; `-Cpp_exceptions off` matters (on changes it). A
  guarded allocation calling a constructor that returns `this` is `new T` (operator new/delete may be class
  members); the new-expression's result is a temporary.
- Virtual `delete p` calls vtable slot 1 (deleting destructor) with no explicit null check needed. Plain `delete p;`
  has its own emitted null check; an explicit `if (p) delete p;` changes block shape: try both.
- A function that is only `operator delete(p); return p;` is a deleting destructor and belongs to its class's file.
- The compiler emits separate C1/C2 constructors and D1/D2 destructors for some classes; the original link dropped
  the unused copy (and strings only it used). They show as "unknown symbols"; harmless.
- Vtables are emitted at the end of the file in REVERSE class order, only those the file emits (a key function
  defined mid-file still puts its vtable at the end). Inline virtual destructors are emitted with their vtables (D0
  then D1). Destructors defined out of line after the other functions emit D1, D0, D2 (linker drops D2): use that
  when vtable order and destructor order disagree.
- `-RTTI off`: vtables have a zero typeinfo slot.
- Inline destructors of singletons are emitted as weak copies in every file that uses `Get()`; the original link kept
  one. Making the singleton destructors `inline` in the owner file gave the original function order.
- One class compiled under two names in different files shows as an undefined vtable only once the other links.
- A class whose empty constructor was visible in one file but not others (guard-before-node order differs only in
  that file): declare the ctor under an #ifdef defined in that one file. Exhaustive search proved nothing else worked.

### 1.12 Data layout, sections, link order

- Thumb anchoring (2.0 sp2p3): a constant member offset becomes pool word = object + (offset & ~0x7f) for words,
  & ~0x3f for halfwords, & ~0x1f for bytes. For an object the file defines, constant offsets go through the
  `.bss` section base plus the anchor; taking the address or a variable index uses the object's own symbol. A
  pool word that names no object start is an anchor: find the object it belongs to before declaring it.
- ARM anchoring: word and byte members are reached as object + (offset & ~0xfff), halfwords as object +
  (offset & ~0xff); pointer locals fold the same way. Register-offset loads carry the full address.
- Shared `.bss` order (2.0 sp2p3): ascending size; on a tie, definition order except that the first-defined object
  goes last; objects of 64 bytes or more get own sections, also smallest first. A smaller object after a
  bigger one starts a new file.

The size-sort model (exact on synthetic files, needs calibration on real ones):
1. Objects join one list per file as declared, by PREPENDING (list ends reversed). One list for the whole file
   (.bss, .data, .rodata together); each shared section is emitted at the place of its first member.
2. A USED singleton accessor adds guard (4), destructor-chain node `@N` (12, only if T has a destructor) and instance
   where its header is first included. Order: guard, node, instance if T has a non-trivial constructor (user ctor,
   virtuals, base/member with one); node, guard, instance if trivial. An unused accessor adds nothing (does not
   count as a reference either).
3. File-level statics add themselves where defined, preceded by the string literals of their initializer. String
   literals used inside functions don't join (emitted afterwards in creation order). Function-local static tables
   join at their function's position; a local array initializer's `@N` in .rodata joins at its function's position.
4. Vtables join at the end, reverse class order.
5. The list is heapsorted by size (max-heap, strict compares): ascending sizes; equal sizes in an order depending on
   the whole list. So a smaller object can never follow a bigger one from the same list.
6. Weak objects (guards, instances) move to their own sections; what stays is the unit's layout.
Consequences:
- Header include order and static definition order (including statics placed BETWEEN includes) decide all three
  sections. `tools/layout_search.py <unit>` searches singleton order, static order and where statics
  sit among the headers (it refuses unless it reproduces the current compile first); `tools/fix_layout.py` tries
  header orders by compiling them; `tools/fix_static_order.py` applies a static order; `tools/data_order.py` works
  out a declaration order for one section. `.clang-format` must keep include order (`SortIncludes: Never`): it's
  load-bearing.
- Define every table in the range: `.rodata` tables take part in the same sort as `.data` ones.
- Merging tables into one struct changes what the sort can reach (a 60-byte struct of position+order tables; a
  struct of two tables to put a 10-byte table before an 8-byte one). Byte tables indexed by a variable stay separate
  (inside a struct the index becomes an immediate offset).
- Order of identical string literals in a table initializer follows from the whole list (`-str noreuse` keeps them as
  separate copies).
Which objects get their own section (and are addressed through their own symbol):
- Objects the file never references (inline accessors in included headers count as references); byte-aligned const
  tables whose size is a multiple of 4; function-local mutable statics (except under 2.0 sp2p3 with
  `-O4,p -ipa file -inline on,noauto`: there they join the shared `.bss` and are addressed through the section
  base); every string literal; arrays of char/u8/s8 (1-D char arrays always, even referenced; 2-D char arrays and
  same-size structs stay shared); `extern` objects; weak objects (inline-function statics, template statics);
  objects under `#pragma section npdata begin/end`.
  Under sp2p2 nothing else matters (size, alignment, order, static vs global, opt level); 2.0 sp2p3 and sp2p4 also
  give every object of 64 bytes or more its own section [SP-diff, tested; see compiler.md]. Own sections are emitted
  at their place in the size sort, after the shared one. mwld starts each section on 4 bytes.
- `const` always wins: a const object goes to `.rodata`. Wrong const-ness shows as a section landing in the other
  kind (`.data` in the original's `.rodata`).
- To give a table its own pool word / own section in `.data`, make it a function-local static of an inline accessor
  (`inline Rec *Items() { static Rec s[4] = {...}; return s; }`). Also used to place writable tables after a file's
  strings.
- Big globals that the code must address by their own symbol: `#pragma section npdata begin/end`; other units naming
  fields inside them by address get linker-script aliases (base + offset).
- A zero-initialised table the original has in `.data`: `#pragma explicit_zero_data on` around it (`= {0}` alone goes
  to `.bss`).
- A const table read only with constant indices is folded into immediates (no relocation reaches it) yet is still
  referenced and joins the shared section: look for a gap's values among a function's immediates before calling it
  dead data; read it in code to keep it referenced.
- A static's `.bss` place shows in relocations: byte-identical code addressing the wrong `.bss` offset = definition
  order.
Unit-boundary cues:
- The same singleton's node at two original addresses means two files. A smaller object between two larger ones means
  a boundary. Another unit's data on both sides means a shared file. Literals lying before a vtable mean an earlier
  file (function literals are emitted after a file's shared .data). An object in a neighbour's block means the code
  using it belongs to that file (two classes, one file). Deleting-destructor stubs sit at the start of their class's
  file range.
- When no include order works, look for a boundary problem first.
Link order and linking:
- Function order = definition order. A function defined before its caller (for the declaration) is emitted first:
  use a prototype and define after. `-inline deferred` would reverse function order (not used).
- [mwld] `-dead` strips unreferenced data once a unit links from source, though the original link kept it: list such
  objects in `config/<ver>/arm9/force_active.txt` (written into a FORCE_ACTIVE block; mwldarm's `-force_active` flag
  segfaults under wibo). Unreferenced statics are dropped by the compiler; unreferenced globals take part in the
  sort and get own sections.
- [mwld] Linker-script aliases (`alias` lines in `config/<ver>/arm9/lcf_edits.txt`, see `tools/lcf_force_active.py`)
  must go after the sections (before them they silently resolve to 0).
- [mwld] Weak vtable copies get stripped; write that unit's `.data` range by hand and mark the symbol weak.
- [mwld] mwcc emits inline-function statics with a processor-specific "multidef" binding (13) that mwld resolves to
  the first definition; mwld prefers multidef over weak. To make the original's (delinked) copy win: demote compiled
  multidef to weak (14), promote delinked weak to multidef, and put delinked objects first.
- A function placed apart from its unit (e.g. `main` right after start-up code): a stub unit holds its slot and a
  linker-script edit puts `OBJECT(main, Game.o)` there.
- [dsd] dsd reads any address-looking word as a pointer: a data blob (font bitmap) word recorded as a relocation into
  an overlay becomes 0 when the target is renamed away. Delete such lines from relocs; check relocations into a newly
  linked range when the ROM differs by one word.
- [dsd] The `.text/.rodata` boundary may be set too late (70 KB of tables counted as code); fixing it lets units own
  their tables and corrects progress numbers. Hand-written routines inside data then live in `.rodata`.
- [dsd] dsd delink refuses a relocation from one unit to a LOCAL symbol of another: never make a symbol local while an
  outside relocation targets it.
- When a fully matched unit breaks the ROM on linking, diff the linked binary against the extracted one and read the
  differing pool words.

### 1.13 Soft float and runtime helpers

- `float` arithmetic calls runtime helpers (`_fadd _fsub _fmul _fdiv _fflt _ffltu _ffix _ffixu`, compares `_fgeq
  _fgr _fleq _fls _feq _fneq`). A source compare must use the same operator as the original (`a < b` -> `_fls`;
  `!(a >= b)` -> `_fgeq`).
- `s->x = 8;` on a float folds to a constant; `u32 left = 8; s->x = left;` keeps `mov r0,#8; bl _ffltu`.
- `/` and `%` on ints call a combined division helper (`_s32_div_f`: quotient r0, remainder r1). Write the operator,
  never call the helper by name. The divisor in r1 often already holds a value used elsewhere (keep it in a local).
  Compound-assigned locals (`s32 q = a; q /= b;`) fix the order of division calls; one big expression lets them be
  reordered.
- 64-bit fixed point (NitroSDK-style matrix concat): a product of two locals gives umull+mla with sign words on the
  stack; a local times a fresh load gives smull/smlal; both in one function is the sign of the source shape.
  `(fx32)((e64 >> 12) + t)` gives `adds`. Matrix concat reuses the last column loaded in a row for the next row's
  first element (load columns into locals, alternate column order row by row).
- 64x32 multiply with known-zero high word: up to 2.0 sp2 emits umull + mla against a zeroed register; sp2p2+ drops
  it. [SP-diff]
- The soft-float/division runtime itself is hand-written assembly (written as asm bodies).

### 1.14 Asm bodies

- Hand-written routines (start-up, soft-float/division, SHA-1 block, cache/protection/irq/context, ITCM copy/fill
  routines, divider save/restore, an LZ streaming step, codec DSP kernels) are written as commented `asm` function
  bodies in C files, clean room.
- Each compiled function gets its own 4-byte-aligned section, so Thumb BIOS thunks at halfword addresses can't come
  from C: use an assembler file (mwasmarm), which can place global labels anywhere in one section.
- Labels inside one asm function aren't visible to another: a branch into the middle of a neighbouring routine is a
  raw instruction word (`dcd`) with a comment. objdiff then reads it as data and scores < 100% though bytes match.
- [mwasm] mwasmarm reads `.incbin` input as TEXT (lone 0x0a -> 0x0d): expand `.incbin` lines into `.byte` lines in a
  build-dir copy. The 2.0 sp2p2 package ships no assembler; use the next build's (sp2p3).
- Opaque filler bytes (secure area) are read from the user's ROM at build time, never committed.

### 1.15 objdiff / dsd / checker quirks (identical code, < 100%)

- A `bl` to the function starting right where the caller ends stays a mismatch (99.99%): symbol + -8 addend lands
  inside the caller. Linking is the proof.
- A `bl` to another function of the same unit counts as a mismatch while that callee doesn't match.
- Stripped weak copies (inline destructors) in our objects shift objdiff's view of later relocations (99.9x%).
- Data inside asm bodies (no `$d` mapping symbol) and a data block whose delinked target has no mapping symbol (scored
  as instructions: 40% for a parameter block) -> < 100% with identical bytes.
- Literal-pool relocation names in not-yet-linked units.
- objdiff scratches: `tools/objdiff_place.py` gives each unit its own decomp.me compiler and flags.
- `dsd check symbols` keeps a few unfixable mismatches (a local destructor node another unit references; labels
  inside asm bodies that emit no symbol). Document them.
- Probes mask call targets and string addresses: a wrong file name or wrong callee "matches".
- A Thumb `bl` from a function into its own body (a far branch to a shared exit block) gets a relocation from
  `dsd init`, but the compiler resolves it without one: the delinked original then has a relocation the compiled
  object never has (99.99%). Remove such relocations from relocs.txt (source and target inside one function).

### 1.16 Thumb code

- `#pragma thumb off` ... `#pragma thumb on` around a function in a file compiled with `-thumb` gives exactly the code
  of compiling it in an ARM file (checked on every 1.2, 2.0 and DSi build), so an ARM function can sit in a Thumb
  file; the binary can't show whether the original set the mode per file or per function.
- A Thumb `bl` is two halfwords (one 4-byte instruction) and can straddle a word boundary: mask relocations per byte.
  objdump prints it as one line.
- Thumb functions end on a halfword: a unit's range ends after the padding, on a 4-byte boundary (the linker places
  every section on 4 bytes, and a halfword end shifts everything after the unit).
- Thumb code has no `umull`/`smull` for 64-bit products; it calls a runtime helper, so the 2.0 sp2-vs-sp2p2 multiply
  idiom only exists in ARM code.
- Thumb has no conditional execution other than branches: where ARM code would predicate an arm, Thumb code branches.

## Placeholders

Forms that reproduce the original's bytes but are probably not its source. Use one only when the bytes match and the
code still behaves the same, mark it in place (`// placeholder: <what it stands in for>`), and replace it when a real
form matches. Kinds that have worked:
- Layout stand-ins: a dummy static of the right size taking part in the data size sort (a missing participant changes
  the order of equal-sized objects); named copies of identical initialisers to set their order; a 2-D shape that
  keeps a byte table in the shared `.rodata`; a stub unit that holds the slot of a function placed apart from its
  unit (moved with an `lcf_edits.txt` line); an empty constructor visible in only one file through an `#ifdef`.
- Index and register stand-ins: a pointer local for a hardware register read (keeps the address numbered among the
  variables); a second extern name for part of a table (keeps a loop base a hoisted temporary); unread zero
  initialisers (register and stack-slot order); volatile reads that keep two reloads apart; an enum-typed index; a
  narrow read of a stack parameter (`*(u8 *)&param`) when callers store a full word; a repeated test `a || a` (a join
  block that keeps a call result in its local); `(s16)(int)(y - 8)` (stops narrowing being shared between calls); a
  two-arm value whose arms read the same thing (`idx = c ? list->x : g.list->x;`), which keeps a value as its own
  statement past expression propagation and then merges to nothing.
- Expression stand-ins: `- -v`, a cast through a byte pointer, a zero base, a constant stored through
  `*(s16 *)&field`. They steer folding, sign or temporary creation; the type or variable structure that does the same
  is the real form.
- Judgement calls: a tail-call function declared `void` because every caller ignores the result and `void` keeps
  another caller matching.
Things that looked like they needed placeholders but were solved by rules: two loads before two compares (enum-typed
copies of the field reads); scheduling "cycles" and enum-zero workarounds (a BOOL-returning callee declared void);
literal-order problems (wrong strings behind masked addresses).

## objdiff below 100% with identical code

See 1.15 above for the known causes. The ROM check is the proof; record each such function and its cause here.
