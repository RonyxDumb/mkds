# Copertura misurata — checkpoint 6

**0,4561% dei byte attribuiti alle funzioni identificate è verificato localmente byte per byte.**

8.728 / 1.913.676 byte. Denominatore: somma delle dimensioni dei corpi funzione nell’inventario Ghidra, incluse ARM9, overlay e ARM7. Non è la dimensione della ROM: risorse e dati non sono codice. L’inventario può avere funzioni mancanti, falsi positivi, dati nei corpi e byte condivisi fra funzioni; non è una certificazione del codice intero del gioco.

| Modulo | Byte funzioni | Byte locali identici | Copertura |
|---|---:|---:|---:|
| arm9 | 1397108 | 8296 | 0.5938% |
| arm9_ov000 | 174497 | 116 | 0.0665% |
| arm9_ov001 | 100010 | 280 | 0.2800% |
| arm9_ov003 | 94969 | 36 | 0.0379% |
| arm7 | 147092 | 0 | 0.0000% |

613 / 12.038 funzioni: 5,0922% per numero di funzioni. Non usare questa misura come percentuale per dimensione: le funzioni verificate sono prevalentemente piccole.

7.598 / 12.038 file compilabili: 63,1168%. Compilabilità e matching sono misure distinte.

Ricontrollati tutti i 613 hash dei sorgenti attuali, i byte originali nelle sezioni e la sezione testo completa degli oggetti MW salvati, con assenza di relocazioni. ROM completa, ABI globale e comportamento in gioco non verificati. Non si può ancora assegnare una percentuale esatta alla decompilazione funzionalmente corretta nonmatching.
