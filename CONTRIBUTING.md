# Contributing

## Layout
| Path | Contents |
| --- | --- |
| `config/<ver>/` | `dsd` configuration: symbols, relocations and translation-unit boundaries (`delinks.txt`) |
| `src/Main/` | Game code from the main ARM9 binary, grouped by subsystem; `Unknown/` for units whose role isn't settled |
| `src/ITCM/` | Game code that runs from ITCM |
| `src/NN_Name/` | Game code from overlay `NN`, named once its purpose is known; unnamed overlays use just the number |
| `include/` | Game headers, grouped by subsystem |
| `libs/<name>/` | Library code the game links (NitroSDK in `libs/nds/`, NitroSystem in `libs/nns/`, the C runtime in `libs/msl/`, middleware in a folder of its own), each with `src/` and `include/`; libraries usually need their own compiler (`PATH_COMPILERS`) |
| `tools/` | Build scripts and analysis tools; `tools/project.py` holds the game's settings |
| `docs/` | Notes on the compiler, decompiling and the game |
| `extract/`, `build/` | Your ROM, its extraction and build output (never committed) |

## Naming
Settle these on day one, before names accumulate: renaming thousands of placeholders later is far more work than
naming them right once.
- Source files are named after the module they define, with the header (`.h`) under `include/` in the same
  subsystem folder.
- Structs, enum types and functions use `PascalCase`; members use an `m` prefix (`mState`).
- File-scope statics use an `s` prefix (`sFrameCount`), globals shared between units a `g` prefix (`gGameData`).
- Locals and parameters use `camelCase`; `i`/`j`/`k` are fine for loop counters.
- Library functions keep their library's own naming (`OS_GetLockID`, `NNS_G3dDraw`). Decide per library, once, how
  unnamed library functions are named (for example type first: `FileOpen`, `HeapAlloc`).
- Constants are `#define`s in `UPPER_SNAKE`; a `#define` keeps the literal's value and type exactly (suffix included,
  `0x8000u`). Naming never changes a variable's or member's type to an enum type: the compiler treats enum-typed
  values differently and the output would move (where the original needs an enum-typed local, the matching source
  already has one).
- A constant names a value of a set: the values one member, parameter or return value takes. All the set's names
  share a prefix (`SCENE_`, `UPLOAD_KIND_`) and go in the header that declares the API carrying the value, or at the
  top of the one `.c` file that uses them. Every site of the set uses the names; a value the code gives no meaning (a
  sentinel, a count, a value doing another job) stays a literal with a comment. Coordinates, sizes and one-off waits
  stay literals.
- Recurring words keep one meaning everywhere. Write the list down as it grows; a starting set: `m...Timer` counts
  down, `m...Frames` counts up, `m...FrameCount` is a fixed length, `m...Handle` holds index + 1 (0 = none),
  `m...Visible` / `m...Enabled` are 1 when drawn / active, `Update<X>` runs every frame, `Load<X>` reads a file,
  `Init<X>` runs once, `Setup<X>` can run again.
- A name has to be supported by what this repository shows: what the code does, the game's own strings and file
  paths, and names already given. New names carry no address (symbols.txt keeps it).
- While lifting, no abstractions: no function-like or expression macros (`MIN`, `CLAMP`, `ASSERT`, register-cast
  wrappers) or new helpers. Each function is written out plainly as it was matched, so its source reads as obtained
  from the code alone. Hardware registers use the SDK headers' names (`reg_G3X_*`), or the address cast in place
  where there is none. Macros and helpers may come in the polish pass, once the whole codebase matches.
- Never take a name, a macro or a code shape from memory of other code: every name must be traceable to this
  repository (the code's behaviour, the game's strings, the SDK headers it already has).
- Library functions keep their library's own API names (NitroSDK `OS_*`, `MI_*`, ...); those names come from
  the SDK interface, not from this ROM, so they are only given where the function's identity is certain.
- Anything not yet understood keeps an address-based name: functions `func_<addr>` / `func_ovNNN_<addr>`, data
  `data_<addr>`, members `mUnk_<offset>`, virtual slots `vfunc_<offset>`.
- Placeholder addresses are the reference version's (`REFERENCE_VERSION` in `tools/project.py`: the European
  version). Every other version's own placeholders carry its name (`func_usa_<addr>`), added when its config is
  generated, so a name from the source never lands on a different object in another version. Source uses the
  reference names; `tools/sync_symbols.py` carries them into each version's config.
- Annotate struct members and vtables with their offsets: `/* 2c */ u8 mState;`.
- Format C/C++ with `clang-format` (the repository's `.clang-format`). It reflows `asm` function bodies into one
  line, so fence each `asm` function with `// clang-format off` and `// clang-format on`.
- Headers live in `include/` and `libs/<name>/include/`, never next to a source file, and are included by their path
  there (`#include "Scene/Title.h"`); there is one copy of every header.

## Adding a translation unit
The full steps and tools are in [docs/decompiling.md](docs/decompiling.md), "Workflow". In short:
1. Add the file and its section ranges to the right `delinks.txt` (`dsd` splits the original object at those
   boundaries). A `.text` range starts at the unit's first function and ends on a 4-byte boundary after its padding.
   Boundaries that are guesses carry a `// provisional` comment above the entry. The entry's format is in
   [docs/decompiling.md](docs/decompiling.md), "Workflow" step 4.
2. Write the functions in address order until each matches; one that doesn't yet keeps a `// non-matching:` comment
   saying exactly what differs. Files can land like that, unlinked.
3. When every function matches, link the unit (`tools/try_link.py <unit>`): the ROM must still match.

## Commits
- One area per commit (a unit, a library family, a tool), never one huge commit. Messages are short (about 50
  characters) and say what the change does and nothing else: no "fix" framing for wording, no admitting earlier
  mistakes.
- No assistant or service attributions anywhere: no co-author trailers, session links or model names in files, file
  names or commit messages.
- Commit what the project is made of: source, headers, config, docs, the build and its tools. Scratch files, probes
  (except the compiler evidence in `docs/probes/`), search output and one-off scripts for a pass stay out of the
  repository, and nothing loose goes in the root.

## Before committing
- `ninja` ends with `mkds_usa.nds: OK` and `ninja check` passes.
- `tools/check_calls.py`, `tools/check_callees.py` and `tools/check_strings.py` end with a count of 0.
- `tools/check_signatures.py` lists no function and `tools/check_units.py` prints OK for every unit (both after
  `ninja report`; each exits non-zero otherwise).
- No function's score in `build/<ver>/report.json` got worse; `tools/progress.py update` before pushing.
- Docs say only what has been checked; anything unverified says so.

## Rules
- Never commit anything taken from the game: ROMs, assets, extracted files or disassembly. Text the game code
  itself uses (string literals, file paths) belongs in source like any other constant.
- Every function is decompiled from this ROM. Code, headers and prose from other decompilations (including other
  versions or related games) are not accepted. Write SDK headers yourself from the API names and observed codegen.
- The repository stands on its own, never as a fork of another decomp: no "same as project X", "sister project" or
  names "taken from" another repository in sources, docs, config or commit messages. State evidence from this ROM
  ("matches at 1.2 base with `-O4,s`, not at `-O4,p`").
- Data the code uses is written as typed source (structs and arrays with their values), not as raw byte dumps.
  Bytes with no meaning as data are read from your ROM at build time (`.incbin`, expanded by `tools/expand_incbin.py`).
- Comments say what the code or the compiler does. They never say where code came from ("original source",
  "copied", "transcribed", "as the SDK does"). Hand-written routines written as `asm` bodies are commented.
- Format C/C++ with the repository's `.clang-format`.
