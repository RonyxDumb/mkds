# Copertura misurata — checkpoint 10

**1.440578% dei byte dei corpi funzione identificati è verificato localmente.**

27,568 / 1,913,676 byte; 1160 / 12038 funzioni. È una misura sull'inventario Ghidra, non un matching della ROM intera. I corpi possono includere dati, falsi positivi e byte sovrapposti.

| Modulo | Byte funzioni | Byte locali identici | Copertura |
|---|---:|---:|---:|
| arm9 | 1397108 | 26842 | 1.921254% |
| arm9_ov000 | 174497 | 132 | 0.075646% |
| arm9_ov001 | 100010 | 496 | 0.495950% |
| arm9_ov003 | 94969 | 98 | 0.103192% |
| arm7 | 147092 | 0 | 0.000000% |

File compilabili: 7616 / 12038 (63.2663%). Compilabilità e matching sono misure distinte.

Hash dei sorgenti e prove hex ricontrollati contro i binari estratti. Le prove MW precedenti restano storiche se il compilatore non è disponibile. Le nuove prove Clang hanno oggetti e opzioni conservati in verification/clang-leafs/. Linking completo e comportamento del gioco non verificati.
