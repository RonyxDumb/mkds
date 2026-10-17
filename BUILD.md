# Setup and verification

Run commands from the repository root. Requires Linux, Python 3 and an AMCP ROM
with SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.
There is no complete ROM build target yet.

```sh
python -m venv .venv
. .venv/bin/activate
pip install -r requirements.txt
python scripts/setup_matching_toolchain.py
python scripts/prepare_rom.py /path/to/AMCP.nds
export MKDS_BASELINE="$PWD/baseline"
export WIBO="$PWD/tools/wibo"
export MWCCARM="$PWD/tools/mwccarm/1.2/sp2p3/mwccarm.exe"
```

## Matching

```sh
python scripts/batch_matching.py --workers 4 --limit 2000 --summary build/search.json
python scripts/accept_batch_matches.py build/search.json --audit-name batch-session-audit.json
python scripts/audit_current_unrelocated.py
python scripts/audit_resolved_calls.py
python scripts/measure_progress.py
python scripts/generate_treemap.py
```

The batch search caches attempts under `build/`. Acceptance recompiles candidates
and checks every byte, including resolved relocations. Audits use recorded compiler
variants; compilation alone does not count as matching.

## Progress report

```sh
python scripts/test_compare_rom.py
python scripts/export_objdiff_report.py --output build/decomp-report/report.json
```

GitHub Actions publishes this objdiff report as `eur_report` on pushes to `main`.
Its input is `reports/progress-measured.json`; verification records are under
`verification/`. Historical reference checkpoints are in [CHECKPOINTS.md](CHECKPOINTS.md).

## REA / Ghidra (optional)

Requires Node compatible with REA, Ghidra 12.1.4, JDK 21 and Linux with `pidfd_open`.

```sh
git clone https://github.com/morluto/rea.git tools/rea-source
git -C tools/rea-source checkout --detach fffb0741936067530d1ce9777461cd53e87398c2
python scripts/rea/apply_fix.py
(cd tools/rea-source && npm ci && npm run build:cached)
python scripts/rea/decompile_mkds.py arm9 0x0200104c
```

Set `GHIDRA_INSTALL_DIR` and `JAVA_HOME` to your installations. The launcher defaults
to `tools/ghidra_12.1.4_PUBLIC` and `tools/jdk21/jdk-21.0.12.1+1`.
REA uses a locally patched, pinned revision; output goes to `build/rea-mkds`.

## Runtime analysis (optional)

Requires Git, CMake and a C++17 compiler.

```sh
sh scripts/build_headless_emulator.sh
tools/melonds-headless /path/to/AMCP.nds 900 build/reference
python scripts/prepare_dynamic_analysis.py /path/to/AMCP.nds
```

Add `--gdb` to the emulator command to enable the debugger. ARM9 and ARM7 use
ports 3333 and 3334. Runtime observations do not establish byte matching.
The melonDS license is in [docs/MELONDS-LICENSE.txt](docs/MELONDS-LICENSE.txt).
