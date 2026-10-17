# Reference checkpoints

Counts are historical local byte-exact results. Bytes use the identified function
inventory (1,913,676 bytes), not the whole ROM. Checkpoint 22 is excluded because
its source corpus is unavailable. Detailed proof records remain in `verification/`.

| Checkpoint | Exact functions | Inventory bytes |
|---|---:|---:|
| 3 | 613 | 8,728 |
| 4 | 613 | 8,728 |
| 5 | 613 | 8,728 |
| 6 | 613 | 8,728 |
| 7 | 776 | 13,142 |
| 8 | 1,024 | 21,978 |
| 9 | 1,143 | 27,044 |
| 10 | 1,160 | 27,568 |
| 11 | 1,174 | 28,104 |
| 12 | 1,222 | 29,070 |
| 13 | 1,663 | 62,902 |
| 14 | 2,288 | 109,144 |
| 15 | 2,289 | 109,220 |
| 16 | 2,379 | 126,160 |
| 17 | 2,454 | 135,620 |
| 18 | 2,706 | 171,580 |
| 19 | 3,111 | 216,832 |
| 20 | 3,113 | 216,924 |
| 21 | 3,115 | 216,982 |
| 23 | 3,117 | 217,166 |
| 24 | 3,768 | 286,846 |
| 25 | 3,772 | 287,242 |
| 26 | 3,777 | 287,494 |
| 27 | 3,789 | 288,062 |
| 28 | 3,811 | 289,370 |
| 29 | 3,819 | 291,822 |
| 30 | 3,820 | 291,874 |
| 31 | 3,837 | 292,526 |
| 32 | 3,848 | 293,278 |
| 33 | 3,871 | 295,894 |
| 34 | 3,881 | 296,578 |
| 35 | 3,890 | 298,964 |
| 36 | 3,894 | 299,326 |
| 37 | 3,896 | 299,502 |
| 38 | 3,901 | 301,880 |
| 39 | 3,911 | 302,550 |
| 40 | 3,917 | 303,032 |
| 41 | 3,942 | 305,160 |
| 42 | 3,944 | 305,316 |
| 43 | 3,947 | 306,500 |

## Current work

Checkpoint 43: 3,947 functions, 306,500 / 1,913,676 inventory bytes
(16.016295%). Three fuzzy drafts promoted after unsigned load corrections:
`02118b48` (508 bytes), `0211efec` (596 bytes), `02181124` in overlay 1
(80 bytes). Fresh compilation and independent complete relocation checks passed;
82 relocations resolved. Proof: `verification/checkpoint43-unsigned-loads-audit.json`.
All checkpoint 42 exact proofs remain; 17 fuzzy candidates remain separate and
the original candidate sources are retained. The 16% inventory threshold is met;
whole-ROM matching is still unverified. The separate 17% target remains open.

### Checkpoint 42


Checkpoint 42: 3,944 functions, 305,316 / 1,913,676 inventory bytes
(15.954425%). `LoopFn_Some3D` at `02037a40`: recovered the unsigned
16-bit field at offset 10. Original uses `ldrh`; the fuzzy draft used
`ldrsh`. Fresh compilation and independent relocation audit verify all 84 bytes.
Proof: `verification/continuity-20261017-short-audit.json`.
ARM7 `FUN_037f8c74`: recovered typed call arguments, verified all 72 bytes
with MWCC 1.2/base at `-O2`, including both relocations. Proof:
`verification/continuity-20261017-arm7-audit.json`.
20 fuzzy drafts remain separate. The previous fuzzy source stays in Git.
Continuity checks compare against immutable commit `82499354a8c5b790a3d43c15c5540ffb0ea335bf`.
The earlier chat claim of 16.418035% has no recoverable source/proof checkpoint
in this checkout and is not included in measured progress.

### Previous checkpoint details


Checkpoint 41: 3,942 functions, 305,160 / 1,913,676 inventory bytes (15.946273%).
25 new exact functions, 2,128 bytes: corrected inferred local-array extents,
reused verified C for same-shaped sibling functions, and refined comparison types.
The 17% exact target remains unmet: 20,165 inventory bytes remain.
Fresh proof audits: `verification/checkpoint41-local-arrays-audit.json`,
`verification/checkpoint41-siblings-audit.json`,
`verification/checkpoint41-refined-siblings-audit.json`.

At checkpoint 41, 21 unaccepted fuzzy drafts were parked in `verification/fuzzy-candidates.json`.
They match at least 95% of their complete resolved bytes, but byte similarity is
not semantic correctness; they do not increase the exact count. Drafts explicitly
using Ghidra's `unaff_*` or `extraout_*` values were excluded from this bank.
Reproduce their comparisons with `python scripts/check_fuzzy_candidates.py`.
REA keyboard evidence: `verification/checkpoint41-rea-keyboard.json`.
Search results, including unsuccessful broad searches, are summarized in
`reports/checkpoint41-searches.json`.

Character-selection controller: 22/23 functions, 5,382/7,084 inventory bytes.
The remaining initializer at `02026910` has 19 differing bytes and is excluded.

Candidate: `scripts/inputs/character-select/initializer-candidate.c`.

```sh
python scripts/check_character_initializer_candidate.py
python scripts/report_character_select_family.py
```

Reference records:

- `reports/checkpoint38-initializer-residual.json`
- `verification/character-select-family.json`
- `verification/checkpoint38-character-controller-audit.json`
- `verification/checkpoint38-character-helpers-audit.json`
- `verification/checkpoint35-navigation-semantics.json` (2,240 cases)
