# Toolchain and license review

Reviewed on 2026-10-25 against `82cdb9c`. This records the build's direct dependencies and the matching workflow;
it does not establish the provenance of every historical contribution or a license for the whole repository.

## External tools

| Tool | Project setting | Declared upstream license | Role |
| --- | --- | --- | --- |
| [ds-decomp](https://github.com/AetiasHax/ds-decomp/blob/v0.12.1/LICENSE) | `dsd v0.12.1` | MIT | Extract the user's ROM, split objects, generate linker inputs, rebuild and check symbols |
| [wibo](https://github.com/decompals/wibo/blob/420a75b7f80435824c3a633571277f90ae056119/LICENSE) | `420a75b7f80435824c3a633571277f90ae056119` | MIT for wibo itself | Run the Windows compiler with the required floating-point state |
| [objdiff](https://github.com/encounter/objdiff/tree/v3.8.2) | `v3.8.2` | MIT OR Apache-2.0 (`LICENSE-MIT`, `LICENSE-APACHE`) | Compare compiled and extracted objects; generate progress reports |
| GNU ARM binutils | Installed separately | GPL-3.0-or-later for the installed binutils package; individual components have their own notices | Read instructions, symbols and ELF sections |
| Ninja | Installed separately | Apache-2.0 | Execute the generated build graph |
| Python / pyelftools | Python 3.10+ / installed separately | Python's PSF terms / pyelftools declares public domain | Run the scripts and inspect ELF objects |
| Clang, lld, libclang / CMake | Installed separately | LLVM's Apache-2.0 WITH LLVM-exception / CMake's BSD-3-Clause, with separately licensed bundled components | Build the pinned wibo |
| Metrowerks CodeWarrior for DS | Game compiler/linker `1.2/base`; assembler `2.0/sp2p3` | Proprietary; applicable rights not established by this review | Reproduce the original machine code |

Keep each external tool's notices with any redistributed copy and check its bundled dependencies' terms. Running a
tool locally is separate from incorporating its implementation into the game's source.

wibo also builds MIT-licensed mimalloc and includes an MD5 implementation with a public-domain declaration and
fallback permissive terms in its source header. Its default configuration fetches Wine CRT DLLs (LGPL-2.1-or-later), and
the repository's preset enables liburing. Inspect those components before redistributing a wibo build. The local
validation build disabled both optional components; it retained the pinned wibo commit and its x87 initialization.

## Limits of the license findings

The compiler archive inspected for this build contains no license, EULA or notice file. Its download location,
successful execution and matching SHA-256 hashes do not prove permission to use or redistribute it. Consult the
terms of an appropriately licensed installation; [NXP's licensing page](https://www.nxp.com/design/design-center/software/development-software/codewarrior-development-tools/licensing-and-registration:CW_LICENSE)
describes CodeWarrior licensing generally, not an authorization for this archive. A local installation can be
selected with `python3 tools/configure.py eur --compiler /path/to/compiler/root`.

`tools/` and `.githooks/` contain the project's own scripts, without separate license notices. No repository-wide
license file is present at the reviewed commit, so no MIT or other open-source license is inferred for them.
`libs/` currently tracks only `.gitkeep`; its SDK/library paths in `tools/project.py` describe future layout and
compiler settings, not permission to import another project's sources or headers.

`tools/download_tool.py` checks pinned SHA-256 hashes for dsd and the three build executables. objdiff is selected by
release tag without a SHA-256 check. The compiler archive URL uses HTTP; its pinned executable hashes check identity,
not licensing or all other archive entries. Downloaded tools and all game-derived build output remain ignored by git.

## Matching tools in this repository

- Probe code generation with `probe_compilers.py --unit`; search declaration and expression changes with
  `permute.py`, `auto_permute.py`, `mutate.py` and `permuter.py`. Scratch probes stay in `build/`.
- Follow `CONTRIBUTING.md` for source, header and `delinks.txt` placement. Recover functions and types from the
  supplied ROM. Do not import code or headers from other decompilations, even when they have a permissive license.
- Generate `ninja report`, compare every function against the previous report, and run `check_calls.py`,
  `check_callees.py`, `check_strings.py`, `check_signatures.py` and `check_units.py`. Relocation-masked equality alone
  does not prove the callees or referenced objects are correct.
- Use `try_link.py` for complete units. Keep a unit linked only when the rebuilt ROM's SHA-1 and `ninja check` pass.
- Run `python3 tools/progress.py update` for the configured version before pushing; `.githooks/pre-push` checks it.

See [decompiling.md](decompiling.md) for the full workflow and [compiler.md](compiler.md) for the compiler evidence.
