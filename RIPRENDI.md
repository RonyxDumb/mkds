# Riprendere dal checkpoint 9

1.143 funzioni; 27.044 byte verificati localmente. 984 senza relocazioni e 159 dopo linking locale completo delle relocazioni ARM. Nessuna ROM completa verificata.

Impostare MKDS_BASELINE alla cartella MarioKartDS-EUR-analysis del primo archivio, MWCCARM a mwccarm 1.2/sp2p3 e WIBO al runner. Installare capstone, pyelftools, ziglang==0.14.1.

Verifiche:
- python scripts/audit_local_matching.py
- python scripts/audit_resolved_calls.py
- python scripts/recheck_verified.py
- python scripts/measure_progress.py

Registri autorevoli: verification/local-byte-exact.tsv e verification/local-linked-byte-exact.tsv. Non sovrascriverli con gli script storici. I file compilati MW e le prove sono inclusi; il compilatore non è incluso.

Ricerca: verify_multiple_transfers.py per foglie e trasferimenti multipli; verify_draft_control_flow.py per bozze con condizioni/cicli; verify_resolved_calls.py per oggetti candidati con chiamate ARM. Conservare entrambi i registri quando si estendono gli script: non ricontare o modificare funzioni già verificate. Alcuni script storici conoscono solo il primo registro e richiedono adattamento prima di riutilizzarli.

Prossimi obiettivi: prologhi/stack e salti delle foglie; varianti di compilazione per funzioni più grandi; relocazioni Thumb/interworking mediante un linker verificato. Non usare stub, rimuovere argomenti o mascherare byte. La verifica locale non certifica firme, linking globale o comportamento in gioco.

Ricerca del checkpoint 9: verify_arm_flow_all.py, verify_large_drafts.py e verify_linked_variants.py. Il resolver supporta Thumb BL con controllo indipendente Capstone. Conservare entrambi i registri; non ricontare funzioni già verificate.

## Checkpoint 10 — Clang ARM flow

1.160 funzioni; 27.568 byte (1,440578%). Nuove prove: `verification/clang-arm-flow-recheck.json`. Ricompilare con `python scripts/recheck_clang_arm_flow.py` e misurare con `python scripts/measure_progress.py`. La ricerca `verify_clang_arm_flow.py` salva il registro dopo ogni match; non eseguirla insieme ad altri script che scrivono i registri. I nuovi record `clang_arm_control_flow` usano Clang, non MW. Le quattro prove in `clang-leafs/results.json` sono state ricompilate sul sorgente corrente e riconfermate: gli hash precedenti sono conservati nel campo `historical_source_sha256`. `python scripts/recheck_clang_matching.py` passa su tutte e quattro.

Ricerca aggiuntiva: 604 candidati ARM flow estesi e 275 candidati con trasferimenti multipli, nessun ulteriore match. Il tool `verify_clang_multiple_transfers.py` conserva i registri e salva dopo ogni match. Il recheck ARM flow riconosce anche questi eventuali futuri record e la modalita Thumb.
