# Mario Kart DS (EUR)

Work-in-progress C decompilation of **Mario Kart DS (Europe)** for Nintendo DS.

**ROM INFO**: game code `AMCP`, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

## Progress
![Function inventory treemap](docs/progress-treemap.svg)
Checkpoint 25: **3,772 locally verified functions, 287,242 inventory bytes (15.009960%)**. This includes 1,409 unrelocated matches and 2,363 matches after resolving all ARM/Thumb relocations. Full-ROM matching remains unverified.

The treemap is weighted by **identified function bytes**, with verified local matches highlighted. Compilation success is **not** evidence of correct behavior or matching assembly. These are local checkpoint measurements, not whole-game completion percentages. See [detailed measurements](reports/MISURA-DECOMP.md) and [GitHub Actions reports](https://github.com/RonyxDumb/mkds/actions/workflows/decomp-report.yml).

You can check it online on [Decomp.dev](https://decomp.dev/RonyxDumb/mkds).

## AI disclosure

**AI-assisted project.** Artificial intelligence has been used to help analyze disassembly, reconstruct C code, resolve compilation issues, and automate verification. AI-generated changes require independent validation; unverified code must not be treated as matching or accurate by default.

## Legal

This repository does not distribute Nintendo ROMs or proprietary game assets. A legally obtained **Mario Kart DS (EUR)** copy is required for reference and verification.

Checkpoint 22 reported additional local results but its source corpus is unavailable here; those results are excluded from the published metrics.

[Checkpoint 24 recovery](reports/CHECKPOINT-24.md): +651 freshly audited C matches, +3.641160 percentage points of the unchanged function inventory.

[Checkpoint 25](reports/CHECKPOINT-25.md): four pending C matches freshly audited; bounded mission, time-trial and battle observations; reproducible local GDB launch. REA/Ghidra remains blocked.
