# Mario Kart DS EUR: decomp.dev integration

The workflow `.github/workflows/decomp-report.yml` generates an objdiff v2
JSON artifact named `eur_report`, containing `report.json`, whenever `main`
is updated. It also supports manual runs.

## Verification scope

The report reads `reports/progress-measured.json` and
`verification/local-byte-exact.tsv`. Only the 613 local byte-exact proof entries
count as matching. The exporter checks each proof's source SHA-256, byte size,
relocation count and the inventory aggregate totals. Compilation success is
NOT counted as code matching. The code inventory currently identifies 1,913,676
function-body bytes, with 8,728 verified locally byte-exact (0.4561%).
This metric is *not* whole-game or whole-ROM matching; the original ROM and
compiler are not rerun in this ROM-free GitHub Actions workflow.

The report organizes functions into treemap units of up to 64 functions and
categories for ARM9, overlays and ARM7.

## Setup

1. Copy `.github/` and `scripts/export_objdiff_report.py` into the root of
   `RonyxDumb/mkds` (preserve folder hierarchy).
2. Commit and push to `main`.
3. Visit `https://github.com/RonyxDumb/mkds/actions` and confirm that the
   `decomp.dev progress report` run succeeds and publishes `eur_report`.
4. Log into `https://decomp.dev/manage/new`, select `RonyxDumb/mkds`,
   game name **Mario Kart DS**, platform **Nintendo DS**, and register.
5. Check project progress and treemap, then use Refresh if necessary.

The live decomp.dev registration and import cannot be verified until the
workflow actually executes and the project is registered.
