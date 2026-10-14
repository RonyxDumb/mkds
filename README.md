# Mario Kart DS (EUR)

Work-in-progress C decompilation of **Mario Kart DS (Europe)** for Nintendo DS.

**ROM INFO**: game code `AMCP`, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

## Progress
![Function inventory treemap](docs/progress-treemap.svg)
Checkpoint 23: **3,117 locally verified functions, 217,166 inventory bytes (11.348107%)**. This includes 1,400 unrelocated matches and 1,717 matches after resolving all ARM/Thumb relocations. Full-ROM matching remains unverified.

The treemap is weighted by **identified function bytes**, with verified local matches highlighted. Compilation success is **not** evidence of correct behavior or matching assembly. These are local checkpoint measurements, not whole-game completion percentages. See [detailed measurements](reports/MISURA-DECOMP.md) and [GitHub Actions reports](https://github.com/RonyxDumb/mkds/actions/workflows/decomp-report.yml).

For runtime investigation, see [melonDS/GDB preparation and verified REA limitations](docs/DYNAMIC-ANALYSIS.md). Runtime observations do not count as matching proofs. Original-ROM gameplay has reached Figure-8 Circuit with scripted acceleration.

[Whole-ROM integration comparison](reports/FULL-ROM-COMPARISON.md): all decompressed modules match in a reference-derived hybrid; the complete physical `.nds` differs. Original and hybrid reached the title screen in a headless melonDS test.

You can check it online on [Decomp.dev](https://decomp.dev/RonyxDumb/mkds).

## AI disclosure

**AI-assisted project.** Artificial intelligence has been used to help analyze disassembly, reconstruct C code, resolve compilation issues, and automate verification. AI-generated changes require independent validation; unverified code must not be treated as matching or accurate by default.

## Legal

This repository does not distribute Nintendo ROMs or proprietary game assets. A legally obtained **Mario Kart DS (EUR)** copy is required for reference and verification.

Checkpoint 22 reported additional local results but its source corpus is unavailable here; those results are excluded from the published metrics.
