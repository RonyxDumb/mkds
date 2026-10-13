# Stato attuale — checkpoint 6

**7,598 file C compilabili su 12.038: 63.12%.**

| Modulo | File C | Compilabili ARM | Da correggere |
|---|---:|---:|---:|
| arm9 | 7807 | 5056 | 2751 |
| arm9_ov000 | 1381 | 690 | 691 |
| arm9_ov001 | 844 | 645 | 199 |
| arm9_ov002 | 0 | 0 | 0 |
| arm9_ov003 | 1024 | 662 | 362 |
| arm7 | 982 | 545 | 437 |

Checkpoint 5: 4.957 dichiarazioni di chiamate tramite indirizzo collegate alle definizioni indicizzate, senza cambiare gli argomenti: +461 file compilabili.

Checkpoint 6: 8.280 conversioni esplicite tra valori e puntatori in 2.581 file. Si tratta di rappresentazioni ARM a 32 bit, usando uintptr_t per conservare il valore dell'indirizzo. Le espressioni originali restano interamente presenti e sono valutate lo stesso numero di volte; nessun argomento è stato aggiunto o rimosso. Rimuovendo soltanto le conversioni registrate si ricostruiscono esattamente tutti i sorgenti precedenti. +1.234 file compilabili rispetto al checkpoint 5; nessuna regressione di compilabilità.

Queste conversioni risolvono la forma C del passaggio di parole e indirizzi. **Non dimostrano che i tipi puntati o le firme inferite siano corretti**, né verificano l'allineamento o il comportamento durante il gioco. I controlli del compilatore non sono stati disabilitati. Nessuno stub o ritorno inventato è stato aggiunto in questo intervento.

Tutti i 12.038 file sono stati ricompilati con Clang/Zig 0.14.1 per ARM946E-S/ARM7TDMI. Gli oggetti riusciti sono ELF32 little-endian ARM. Restano bloccanti dichiarazioni implicite, tipi di ritorno e conversioni non rappresentabili nel gruppo ammesso.

Le 613 funzioni già verificate localmente, per 8.728 byte identici all'originale, sono rimaste inalterate: controllati i 613 hash sorgente e ricompilati i 613 file, senza errori. Non si aggiungono nuove funzioni byte-exact in questo checkpoint.

La rigenerazione sperimentale dopo aver bloccato le firme inferite in Ghidra non è stata integrata. Il controllo ha rilevato 1.476 sorgenti con chiamate eliminate o meno argomenti e casi con registri d'ingresso non modellati. L'esperimento e il motivo del rigetto sono documentati in verification/signature_reconciliation/; i risultati sperimentali non entrano nella percentuale.

**La percentuale misura solo la compilabilità dei singoli file.** Decompilazione funzionalmente completa, ABI globale, linking di una ROM e avvio nell'emulatore non sono verificati.
