# Copertura misurata — checkpoint 7

**0.460684% dei byte dei corpi funzione identificati è verificato localmente.**

8,816 / 1,913,676 byte; 617 / 12038 funzioni. È una misura sull'inventario Ghidra, non un matching della ROM intera. I corpi possono includere dati, falsi positivi e byte sovrapposti.

| Modulo | Byte funzioni | Byte locali identici | Copertura |
|---|---:|---:|---:|
| arm9 | 1397108 | 8384 | 0.600097% |
| arm9_ov000 | 174497 | 116 | 0.066477% |
| arm9_ov001 | 100010 | 280 | 0.279972% |
| arm9_ov003 | 94969 | 36 | 0.037907% |
| arm7 | 147092 | 0 | 0.000000% |

File compilabili: 7598 / 12038 (63.1168%). Compilabilità e matching sono misure distinte.

Hash dei sorgenti e prove hex ricontrollati contro i binari estratti. Le prove MW precedenti restano storiche se il compilatore non è disponibile. Le nuove prove Clang hanno oggetti e opzioni conservati in verification/clang-leafs/. Linking completo e comportamento del gioco non verificati.
