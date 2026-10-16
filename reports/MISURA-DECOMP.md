# Copertura misurata — checkpoint 36

**15.641415% dei byte dei corpi funzione identificati è verificato localmente.**

299,326 / 1,913,676 byte; 3894 / 12038 funzioni. È una misura sull'inventario Ghidra, non un matching della ROM intera. I corpi possono includere dati, falsi positivi e byte sovrapposti.

| Modulo | Byte funzioni | Byte locali identici | Copertura |
|---|---:|---:|---:|
| arm9 | 1397108 | 251476 | 17.999754% |
| arm9_ov000 | 174497 | 204 | 0.116907% |
| arm9_ov001 | 100010 | 700 | 0.699930% |
| arm9_ov003 | 94969 | 194 | 0.204277% |
| arm7 | 147092 | 46752 | 31.784189% |

File compilabili: 8613 / 12038 (71.5484%). Compilabilità e matching sono misure distinte.

Hash dei sorgenti e prove hex ricontrollati contro i binari estratti. Le prove MW precedenti restano storiche se il compilatore non è disponibile. Le nuove prove Clang hanno oggetti e opzioni conservati in verification/clang-leafs/. Linking completo e comportamento del gioco non verificati.
