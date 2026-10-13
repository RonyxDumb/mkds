# Checkpoint 7 — 13 ottobre 2026

## Risultato verificato

617 funzioni locali byte-exact; 8.816 / 1.913.676 byte (0,460684%). Quattro funzioni nuove, 88 byte aggiunti.

- `arm9:0x020c0b84` `func_020c0b84`: 36 byte, Zig 0.14.1 bundled Clang.
- `arm9:0x01ff9c9c` `func_01ff9c9c`: 20 byte, Zig 0.14.1 bundled Clang.
- `arm9:0x02010998` `Tex0Block_SetTexturesVramKeys`: 20 byte, Zig 0.14.1 bundled Clang.
- `arm9:0x020204b4` `func_020204b4`: 12 byte, Zig 0.14.1 bundled Clang.

Tutti i nuovi oggetti sono stati ricompilati e confrontati integralmente con i byte originali, senza relocazioni del testo. Le relocazioni della metadata unwind non rientrano nella prova locale. Le 613 prove MW preesistenti conservano lo stato storico: hash e binari verificati, MW non disponibile per una nuova compilazione.

## Ricostruzioni funzionali

`GetDriverPlace` e `GetCurrentLapCount`: 197.888 confronti di risultato e sequenza delle letture RAM contro ARM originale, superati. Casi dettagliati in `scripts/test_race_semantics.py`. Non verificano tutte le possibili condizioni di memoria, l’ABI globale o il gioco intero.

## Compilazione e limiti

12.038 file controllati: 7.598 compilabili, 4.440 falliti. Le sei funzioni modificate sono state ricompilate dopo l’ultima modifica. Tutte le 617 funzioni delle prove locali superano il controllo di compilazione ARM con Clang. Nessun linking completo o test in emulatore DS. Il 100% non è raggiunto.

Sorgenti precedenti conservati in `verification/semantic-race/previous/` e `verification/clang-leafs/previous/`. Il salvataggio intermedio precede le ultime tre nuove prove; questo archivio finale le include.
