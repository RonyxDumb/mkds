# Riprendere dal checkpoint 8

1.024 funzioni; 21.978 byte verificati localmente. 937 senza relocazioni e 87 dopo linking locale completo delle relocazioni ARM. Nessuna ROM completa verificata.

Impostare MKDS_BASELINE alla cartella MarioKartDS-EUR-analysis del primo archivio, MWCCARM a mwccarm 1.2/sp2p3 e WIBO al runner. Installare capstone, pyelftools, ziglang==0.14.1.

Verifiche:
- python scripts/audit_local_matching.py
- python scripts/audit_resolved_calls.py
- python scripts/recheck_verified.py
- python scripts/measure_progress.py

Registri autorevoli: verification/local-byte-exact.tsv e verification/local-linked-byte-exact.tsv. Non sovrascriverli con gli script storici. I file compilati MW e le prove sono inclusi; il compilatore non è incluso.

Ricerca: verify_multiple_transfers.py per foglie e trasferimenti multipli; verify_draft_control_flow.py per bozze con condizioni/cicli; verify_resolved_calls.py per oggetti candidati con chiamate ARM. Conservare entrambi i registri quando si estendono gli script: non ricontare o modificare funzioni già verificate. Alcuni script storici conoscono solo il primo registro e richiedono adattamento prima di riutilizzarli.

Prossimi obiettivi: prologhi/stack e salti delle foglie; varianti di compilazione per funzioni più grandi; relocazioni Thumb/interworking mediante un linker verificato. Non usare stub, rimuovere argomenti o mascherare byte. La verifica locale non certifica firme, linking globale o comportamento in gioco.
