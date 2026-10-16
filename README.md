# Mario Kart DS (EUR)

Work-in-progress C decompilation of **Mario Kart DS (Europe)** for Nintendo DS.

**ROM INFO**: game code `AMCP`, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

## Progress
![Function inventory treemap](docs/progress-treemap.svg)
Checkpoint 33: **3,871 locally verified functions, 295,894 inventory bytes (15.462074%)**. This includes 1,462 unrelocated matches and 2,409 matches after resolving all ARM/Thumb relocations. Full-ROM matching remains unverified.

The treemap is weighted by **identified function bytes**, with verified local matches highlighted. Compilation success is **not** evidence of correct behavior or matching assembly. These are local checkpoint measurements, not whole-game completion percentages. See [detailed measurements](reports/MISURA-DECOMP.md) and [GitHub Actions reports](https://github.com/RonyxDumb/mkds/actions/workflows/decomp-report.yml).

You can check it online on [Decomp.dev](https://decomp.dev/RonyxDumb/mkds).

## AI disclosure

**AI-assisted project.** Artificial intelligence has been used to help analyze disassembly, reconstruct C code, resolve compilation issues, and automate verification. AI-generated changes require independent validation; unverified code must not be treated as matching or accurate by default.

## Legal

This repository does not distribute Nintendo ROMs or proprietary game assets. A legally obtained **Mario Kart DS (EUR)** copy is required for reference and verification.

Checkpoint 22 reported additional local results but its source corpus is unavailable here; those results are excluded from the published metrics.

[Checkpoint 24 recovery](reports/CHECKPOINT-24.md): +651 freshly audited C matches, +3.641160 percentage points of the unchanged function inventory.

[Checkpoint 25](reports/CHECKPOINT-25.md): four pending C matches freshly audited; bounded mission, time-trial and battle observations; reproducible local GDB launch. REA/Ghidra remains blocked.

[Checkpoint 26](reports/CHECKPOINT-26.md): +5 verified C functions / +252 bytes. [Menu exploration with screenshots](reports/MENU-EXPLORATION-2026-10-15.md): Options, Records, WFC Setup, multiplayer, race modes and ghosts; original reference ROM, bounded coverage.

[Checkpoint 27](reports/CHECKPOINT-27.md): +12 verified C functions / +568 bytes; mission queries, boss checks and save dialog; 20,792 original ARM/Thumb versus host C cases passed.

[Checkpoint 28](reports/CHECKPOINT-28.md): +22 verified C functions / +1,308 bytes; 3D resource accessors and menu/emblem helpers; 42,235 additional semantic cases passed.

[Checkpoint 29](reports/CHECKPOINT-29.md): +8 verified C functions / +2,452 bytes; dictionary searches, material/texture animation, time-trial codes and audio loading; 9,792 dictionary semantic cases passed. The 18% inventory target remains open.

Batch analysis and resumable matching: [workflow and measured timings](docs/BATCH-MATCHING.md).

[Checkpoint 32](reports/CHECKPOINT-32.md): +11 typed Thumb command/list helpers, +752 freshly compiled and independently audited bytes.

[Checkpoint 33](reports/CHECKPOINT-33.md): +23 verified functions, +2,616 inventory bytes; caller-signature recovery fixed and historical library variants checked. **18% remains unreached.**
