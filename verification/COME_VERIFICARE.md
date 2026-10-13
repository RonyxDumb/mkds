# Riprodurre la verifica locale

Servono Python, `capstone`, `pyelftools`, il compilatore mwccarm 1.2/sp2p3 e un runner compatibile (qui wibo 1.2.0 Linux x86_64). I binari del compilatore non sono inclusi.

Imposta `MKDS_BASELINE` alla cartella `MarioKartDS-EUR-analysis` del primo archivio, `MWCCARM` al compilatore e `WIBO` al runner. Esegui `python scripts/verify_leafs.py`.

Lo script analizza foglie lineari senza chiamate, traduce le operazioni supportate in C e accetta soltanto oggetti con uguale lunghezza, byte interamente identici e zero relocazioni. Non converte gli errori in stub e non usa assembly inline. Le 34 candidature che non coincidono non sostituiscono le bozze esistenti.

Il confronto è locale: il linking della ROM e il comportamento nel gioco non sono verificati. Le firme C e la loro compatibilità con tutti i chiamanti richiedono ancora controllo.
