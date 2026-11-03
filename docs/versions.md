# Shared-source validation on Europe

Checked on 2026-10-29, starting at `9cc5b2a7` and the European ROM with SHA-1
`ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

## Results

The USA configuration registers 2,713 C translation units, representing 7,549 functions. Building those same
sources for Europe gives **7,254 fully matching functions, covering 958,670 bytes**. These totals equal the latest
committed USA progress point. The 295 remaining functions in these units are not 100% matches; this check does
not establish that they are regional differences. A fresh USA ROM build was not run.

The European configuration was missing 725 of the main module's source units and one ITCM unit. Registering
these 726 units adds 3,488 verified matching functions. Another 168 matching functions are in source units
registered only for Europe.

| European measurement | Before | After |
| --- | ---: | ---: |
| Matching functions | 3,934 | 7,422 |
| Matching code | 278,314 bytes (14.76%) | 964,162 bytes (51.12%) |
| Linked source code | 59,640 bytes (3.16%) | 59,640 bytes (3.16%) |

No previously reported function's matching score decreased. Of the newly registered units, 567 have every
function matching. New units remain unlinked: an object-level match and a successful ROM rebuild with the
existing linked units do not prove that a pending unit's data layout is ready for linking.

## Regional addresses

After the secure area, all 7,676 main-module functions have the same addresses, instruction modes, sizes and
order in the two symbol configurations. This provided candidate ranges; actual compiled code was compared
with the European original through objdiff. Matching also checks the referenced addresses and strings with the
repository tools, since relocated branch and pointer bytes are masked during instruction comparison.

Data addresses cannot be copied with one regional offset. Corresponding relocation sites in the original
European code establish the data addresses, including:

- The data range for `src/Main/Unknown/code_020bb5ec.c` is `0x0216910c–0x02169134` in Europe, versus
  `0x02169104–0x0216912c` in USA.
- The shared pointer named `data_0217ae80` lives at `0x0217ae80` in Europe and `0x0217ae60` in USA. Its old
  source name selected the unrelated European symbol at `0x0217ae60`.
- Seventeen shared data names now use the European reference addresses. The USA symbol addresses, kinds,
  sizes and attributes are unchanged.
- Eight additional European data symbols identify referenced tables in the main module and overlays 0 and 1.

The nonmatching draft `func_020e0764` also shares its two result paths, bringing its four helper-call sites down
to the original's two. Its code is now `0x43c` bytes against the original's `0x448`, and its similarity improves
from 36.27% to 63.80%. It remains excluded from the fully matching count.

## Reproduce

Use the pinned tools described in `INSTALL.md`, including wibo `1.2.0-8-g420a75b` and CodeWarrior `1.2/base`.

```sh
python3 tools/configure.py eur
ninja report check
python3 tools/check_calls.py
python3 tools/check_callees.py
python3 tools/check_strings.py
python3 tools/check_signatures.py
python3 tools/check_protos.py
python3 tools/check_units.py
python3 tools/progress.py check
```

The European ROM rebuild and symbol check pass. Calls/pointers, callee sets, strings, signatures and missing
prototypes each report zero differences or problems; every source unit passes the range check. All previously
matching functions remain matching, and no reported function's score decreases.

## Shared-source update, 2026-11-02

Checked against `6a7fd8a8` and the same European ROM and pinned tools. The USA progress recorded on 2026-10-31
is 10,801 matching functions out of 11,498, or 1,571,102 matching bytes (83.30%). This update does not include
a fresh USA ROM build.

The October 31 source changes already improve Europe when rebuilt. Registering another **915 source units**
adds **3,250 matching functions and 550,824 matching bytes** beyond that fresh starting build. No previously
reported function's matching score decreases. Of the added units, 643 have every function matching.

| European measurement | Published 2026-10-29 | Fresh starting build | After registration |
| --- | ---: | ---: | ---: |
| Matching functions | 7,422 | 7,533 | 10,783 |
| Matching code | 964,162 bytes (51.12%) | 1,018,204 bytes (53.98%) | 1,569,028 bytes (83.19%) |
| Linked source code | 59,640 bytes (3.16%) | 59,640 bytes (3.16%) | 59,640 bytes (3.16%) |

| Module | Added units | Added matching functions | Added matching bytes |
| --- | ---: | ---: | ---: |
| Main | 452 | 1,951 | 341,228 |
| ITCM | 11 | 73 | 16,836 |
| Overlay 0 | 282 | 849 | 133,554 |
| Overlay 3 | 170 | 377 | 59,206 |
| Total | 915 | 3,250 | 550,824 |

The European inventory now contains 11,499 functions. The main-module software floating-point routine at
`0x02131694` previously included two following entry points; their boundaries now agree with the corresponding
source definitions. The European overlay 0 also contains a function absent from the USA inventory.

### Reference and layout validation

Original European relocation sites identify the data addresses for 539 shared USA source names.
Each name has one consistent European target across all matching functions that reference it. These names
are linker aliases of the original European symbols, leaving the original data symbols and their boundaries
intact. The empty constructor list uses its linker boundary, `ARM9_CTOR_START`. All 539 aliases also resolve
to the expected addresses in the linked ELF.

Floating-point comparison and integer multiplication entry aliases are recorded in the European symbols.
The instruction-level audit covers 13,658 referenced names without unresolved or inconsistent targets, and
59 references to local initialized data were checked byte for byte. The normal matching-function call/pointer
and string checks report zero differences. Function declarations and definitions agree, and every registered
source unit passes the range check.

The same source and header tree also passed all 3,778 native prototype-check compile commands, without compilation
failures or calls lacking a declaration in scope.

The all-function callee check still reports 12 differences in nonmatching drafts. None of those functions is
included in the matching totals; the instruction-level checks of fully matching functions report no differences.

Splitting formerly combined original objects exposed unreferenced code, `BuildInfo`, and zero padding to the
linker's dead stripping. The European `keep .text` edit retains those sections. The resulting ROM still passes
the original SHA-1 and symbol checks; retaining them does not mark additional source units complete.

New units remain unlinked. Matching their code and references does not establish that their own data layout
is ready to replace the original objects in the ROM. Nonmatching drafts remain outside the matching totals.

## European matching sweep, 2026-11-03

Checked against a fresh build of `40d305c5`, using the same European ROM and CodeWarrior `1.2/base`.
Near-matching functions were examined across the main game code, libraries, ITCM and overlays. This sweep
adds **21 fully matching functions and 5,568 matching bytes**, with no decrease in any function's score.

| European measurement | Fresh starting build | After this sweep |
| --- | ---: | ---: |
| Matching functions | 10,801 / 11,499 | 10,822 / 11,499 |
| Matching code | 1,571,196 bytes (83.30%) | 1,576,764 bytes (83.60%) |
| Linked source code | 61,698 bytes (3.27%) | 74,048 bytes (3.93%) |

Percentages use the fixed 1,886,120-byte image code size. The remaining 677 functions are outside the fully
matching count; overall fuzzy similarity does not establish a byte match.

| Area | New matching functions | New matching bytes | Newly linked units |
| --- | ---: | ---: | ---: |
| Main game code | 13 | 3,988 | 5 |
| Libraries | 1 | 56 | 1 |
| ITCM | 1 | 96 | 1 |
| Overlay 0 | 3 | 508 | 2 |
| Overlay 3 | 3 | 920 | 3 |
| Total | 21 | 5,568 | 12 |

Twenty function bodies were corrected. Restoring the original function placement in `code_020681f0.c` also
made `func_02068640` exact. The twelve newly linked units passed `tools/try_link.py`, including their data
layout; the complete rebuilt ROM was compared byte for byte with the original and retains SHA-1
`ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

The encoder `func_ov000_021882f8` now uses the original unsigned division helpers for its block count and
signed helpers for its remaining bits. This removes one pre-existing all-function callee difference, leaving
11 differences in nonmatching drafts. Matching-function call/pointer and string checks report zero
differences; signatures and all source-unit ranges pass. Prototype-check compiles for all 17 changed source
units report no missing declarations. Headers and public signatures were not changed.

Fifteen newly matching functions use explicitly marked enum temporaries or volatile pointer views whose
original source forms remain unknown; their compiled code and references are verified. The EUR call argument
in `func_0205dee0_inline` is verified as zero. The existing non-EUR value `0x20` is preserved, but its value
in the USA original has not been verified here, and no fresh USA build was run.
