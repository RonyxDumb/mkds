# Mario Kart DS decompilation

A matching decompilation of *Mario Kart DS* for the Nintendo DS. The C in this repository is written with AI
assistance so that, built with the original compiler, it reproduces the game's code byte for byte.

**No game content is included.** The repository holds no ROM, no assets and no disassembly. To build, you need your
own dump of the game; see [INSTALL.md](INSTALL.md).

| Version | Game code | SHA-1 |
| --- | --- | --- |
| USA | `AMCE` | `691e00d9a5dd80b04f80cc7559503e8b06848785` |

Every function is decompiled from the game's own code. Code from other decompilations is not accepted.

## Progress
<!-- progress:start -->
![Decompilation progress over time](progress/progress.svg)

![Function bytes by module](progress/treemap.svg)

| Measure | Progress |
|---|---|
| Matched code | 0.00% (0 / 1,886,100 bytes) |
| Linked code (complete units) | 0.00% (0 bytes) |
| Overall accuracy (fuzzy) | 0.00% |
| Matched functions | 0 / 11,501 |

_Last updated 2026-10-24. Full history: [`progress/history.csv`](progress/history.csv)._
<!-- progress:end -->

## Documentation
- [INSTALL.md](INSTALL.md): setting up and building
- [CONTRIBUTING.md](CONTRIBUTING.md): repository layout, naming and workflow
- [docs/compiler.md](docs/compiler.md): how the compiler and flags were identified
- [docs/decompiling.md](docs/decompiling.md): source patterns that matter for matching

Built with [ds-decomp](https://github.com/AetiasHax/ds-decomp), Metrowerks CodeWarrior for DS run through
[wibo](https://github.com/decompals/wibo), and [objdiff](https://github.com/encounter/objdiff).
