# Toolchain

| Tool | Version | License | Used for |
| --- | --- | --- | --- |
| [ds-decomp](https://github.com/AetiasHax/ds-decomp) (dsd) | v0.12.1 | MIT | Extracting the ROM, delinking, linker inputs, rebuilding and checking |
| [wibo](https://github.com/decompals/wibo) | `420a75b` | MIT | Running the Windows compiler |
| [objdiff](https://github.com/encounter/objdiff) | v3.8.2 | MIT or Apache-2.0 | Comparing objects, progress reports |
| Metrowerks CodeWarrior for DS | compiler and linker 1.2 base, assembler 2.0 sp2p3 | Proprietary | Building the code |
| GNU ARM binutils | system | GPL-3.0-or-later | Reading instructions, symbols and sections |
| Ninja | system | Apache-2.0 | Running the build |
| Python 3.10+ with pyelftools | system | PSF / public domain | Scripts |
| Clang, lld, CMake | system | Apache-2.0 with LLVM exception / BSD-3-Clause | Building wibo |

- `tools/download_tool.py` fetches dsd, wibo, objdiff and the compiler, and checks their SHA-256 hashes (objdiff by
  release tag only). A local compiler installation can be used instead:
  `python3 tools/configure.py <ver> --compiler <path>`.
- The compiler is proprietary and is not part of the repository.
- wibo bundles mimalloc (MIT) and a public-domain MD5. Its optional Wine CRT DLLs and liburing support are left out
  of the build here.
- The repository has no license file yet.


## License review (2026-10-27)

The license files at the versions used by this build were checked directly:

- dsd v0.12.1: [MIT](https://github.com/AetiasHax/ds-decomp/blob/v0.12.1/LICENSE).
- wibo `420a75b7f80435824c3a633571277f90ae056119`:
  [MIT](https://github.com/decompals/wibo/blob/420a75b7f80435824c3a633571277f90ae056119/LICENSE).
- objdiff v3.8.2: [MIT](https://github.com/encounter/objdiff/blob/v3.8.2/LICENSE-MIT) or
  [Apache-2.0](https://github.com/encounter/objdiff/blob/v3.8.2/LICENSE-APACHE).

These tools are used as separate programs; their source and downloaded executables are not committed. Keep their
copyright and license notices when distributing copies of the tools. Their licenses do not license the game or
this repository's source.

CodeWarrior is proprietary. Its executable hashes identify the build; they do not establish permission to use or
redistribute it. Its license terms have not been verified here. The absence of a root license also means this
repository cannot be described as generally licensed under MIT, Apache-2.0 or another open-source license.

The overlay 0 and 3 additions in this change were reconstructed from the European ROM, without importing source
or headers from other decompilations. This review does not certify the provenance of every pre-existing source
file or the legal status of the project as a whole.

How to decompile and match: [decompiling.md](decompiling.md). Compiler evidence: [compiler.md](compiler.md).
