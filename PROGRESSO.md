# Progressi salvati

| Checkpoint | Compilabili ARM | Percentuale | Funzioni con byte locali identici | Byte identici |
|---|---:|---:|---:|---:|
| 3 | 5.419 | 45,02% | 613 | 8.728 |
| 4 | 5.903 | 49,04% | 613 | 8.728 |
| 5 | 6.364 | 52,87% | 613 | 8.728 |
| 6 | 7.598 | 63,12% | 613 | 8.728 |
| 7 | 7.598 | 63,12% | 776 | 13.142 |
| 8 | 7.598 | 63,12% | 1.024 | 21.978 |
| 9 | 7.615 | 63,26% | 1.143 | 27.044 |
| 10 | 7.616 | 63,27% | 1.160 | 27.568 |
| 11 | 7.619 | 63,29% | 1.174 | 28.104 |
| 12 | 7.619 | 63,29% | 1.222 | 29.070 |
| 13 | 7.800 | 64,79% | 1.663 | 62.902 |
| 14 | 7.986 | 66,34% | 2.288 | 109.144 |
| 15 | 7.987 | 66,35% | 2.289 | 109.220 |
| 16 | 8,028 | 66.69% | 2,379 | 126,160 |
| 17 | 8,052 | 66.89% | 2,454 | 135,620 |
| 18 | 8,141 | 67.63% | 2,706 | 171,580 |
| 19 | 8,307 | 69.01% | 3,111 | 216,832 |
| 20 | 8,308 | 69.01% | 3,113 | 216,924 |
| 21 | 8,308 | 69.01% | 3,115 | 216,982 |
| 23 | 8,308 | 69.01% | 3,117 | 217,166 |
| 24 | non rimisurato | — | 3,768 | 286,846 |
| 25 | 8,589 | 71.35% | 3,772 | 287,242 |
| 26 | 8,590 | 71.36% | 3,777 | 287,494 |

Checkpoint 4: 846 puntatori tipizzati, 484 nuove compilazioni riuscite.

Checkpoint 5: 4.957 dichiarazioni di chiamate con indirizzo risolte verso definizioni indicizzate; +461 compilazioni.

Checkpoint 6: 8.280 reinterpretazioni esplicite di valori ARM32 e puntatori in 2.581 file; +1.234 compilazioni, nessuna regressione. Non cambia il numero di argomenti e non vengono rimossi errori disabilitando controlli. Le firme restano inferite e richiedono verifica.

L'intervento dal checkpoint 4 aggiunge 1.695 file compilabili. La verifica byte-exact resta a 613 funzioni. Non è stata verificata una ROM completa.


Checkpoint 7: +163 funzioni e +4.414 byte localmente identici. Ricompilazione MW e Clang di tutte le 776 riuscita.

Checkpoint 8: +248 funzioni; +8.836 byte. 937 senza relocazioni, 87 con tutte le relocazioni applicate. Copertura inventariata: 1,1485%.

Checkpoint 9: +119 funzioni, +5.066 byte. Relocazioni Thumb BL verificate e ricostruzione di flussi ARM con cicli.

Checkpoint 10: +17 funzioni ARM e +524 byte verificati con Clang (Zig 0.14.1). Ricompilazione indipendente: intera sezione di codice identica ai binari estratti, nessuna relocazione. Le prove MW precedenti restano storiche; il compilatore MW non era disponibile in questa sessione.

Checkpoint 11: +14 funzioni e +536 byte. Recuperato MW build 82. Ricompilazione completa: 1.012 prove senza relocazioni e 162 prove con tutte le relocazioni risolte passano. Il controllo `audit_current_unrelocated.py` seleziona il compilatore corretto per le prove Clang e non riscrive i registri.

Checkpoint 12: +48 funzioni Thumb, +966 byte, tutte riconfermate con ricompilazione. Ricerca sulle 6.802 bozze C con sei ottimizzazioni: zero nuovi match. Totale della sessione: +62 funzioni e +1.502 byte rispetto al checkpoint 10. Il 10% dei byte non e stato raggiunto; servono altri 162.298 byte.

Checkpoint 13: +441 funzioni e +33.832 byte. Folding dei soli literal pool referenziati da LDR PC, resolver ARM BLX con controllo Capstone indipendente, CFG con tutti i ritorni e chiamate con arita inferita dai sorgenti. Ricerca literal: 6.754 candidati / 123 match. CFG: 1.334 candidati / 318 match. Ricompilazione completa: 1.091 prove senza relocazioni e 572 con relocazioni, tutte PASS. Target 10% ancora in corso.

Checkpoint 14: +625 funzioni e +46.242 byte inventariati. C SDK recuperato e ricompilato, argomenti e temporanei stack, trasferimenti multipli, literal puntatore e candidato modello LDR nativo. Tutte le 2.288 prove sono state ricompilate: PASS. I proof span completi sommano 109.304 byte; il numeratore conserva i 109.144 byte dei corpi Ghidra, escludendo 160 byte aggiuntivi (literal pool e un ritorno condiviso). Denominatore invariato: 1.913.676. Target 10% in corso.

Checkpoint 15: ROM EUR fornita e verificata; tutte le 2.288 prove precedenti ricompilate. Nuovo match Thumb CreateCESex_from_thumb: 76 byte e due chiamate Thumb/ARM risolte; ricompilazione Clang ARM riuscita. Tutte le 1.038 prove con relocazioni ricompilate. Copertura locale: 5,707340%; ROM completa e ABI globale non verificati.

Checkpoint 16: +90 funzioni e +16.940 byte inventariati (17.004 byte negli span completi) locali verificati da ricostruzioni C pubbliche di sm64ds-decomp e pokediamond, con commit, hash e flag registrati. Tutte le prove MW ricompilate; nessun corpo assembly importato. Copertura locale: 6.592548%.

Checkpoint 17: +75 funzioni; +9.460 byte inventariati (9.556 negli span completi). Ricerca ricorsiva di 1.912 sorgenti C pubblici di sm64ds-decomp, 11.472 varianti compilate. Tutte le 2.454 prove ricompilate e confrontate; le 75 nuove funzioni compilano anche con Clang ARM. Copertura locale: 7,086884%.

Checkpoint 18: +252 funzioni e +35.960 byte inventariati da NitroSDK e NitroSystem. Tutte le 2.706 prove ricompilate; 3.802 relocazioni risolte. L'assembly inline CLZ nell'header e stato sostituito da una sola dichiarazione esterna, senza implementazione; tutte le 252 nuove prove sono state confermate dopo la modifica. Copertura locale: 8,965990%.

Checkpoint 19: +405 funzioni ARM7 e +45.252 byte inventariati (47.336 negli span completi). Copertura locale: 11,330654%; target 10% raggiunto con denominatore invariato. Ricompilate tutte le 1.396 prove senza relocazioni e le 1.715 con relocazioni; 5.015 relocazioni risolte. Corretto il resolver ARM7, che disponeva del solo simbolo Arm7Entry: il supplemento usa l’inventario Ghidra originale e prove ISA riproducibili. Nessun BLX non supportato nelle 1.003 relocazioni branch delle nuove prove. ROM completa e ABI globale non verificati.

Checkpoint 23: due funzioni di gara ricostruite e verificate, +184 byte. Audit completo: 1.400 senza relocazioni e 1.717 con relocazioni. Confronto semantico ARM/C: 197.888 casi passati. Le prove mancanti del checkpoint 22 restano escluse.

Checkpoint 24 recuperato: +651 funzioni, +69.680 byte inventariati, 14,989267%. Audit completo riuscito.

Checkpoint 27: +12 funzioni e +568 byte inventariati; totale 3.789 funzioni,
288.062 byte, 15,052809%. Ricompilate 1.421 prove senza relocazioni e 2.368 con
relocazioni, tutte identiche; 7.372 relocazioni risolte. 20.792 casi ARM/Thumb-C
passati sui nuovi helper missioni/gara. Nessun matching della ROM intera dichiarato.

Checkpoint 28: +22 funzioni e +1.308 byte; totale 3.811 funzioni,
289.370 byte inventariati, 15,121159%. Accessori risorse 3D e menu/emblema;
42.235 nuovi casi semantici passati, senza equivalenza dell'intera ROM dichiarata.

Checkpoint 32: +11 funzioni Thumb e +752 byte; totale 3.848 funzioni,
293.278 byte inventariati (15,325374%). Comandi, liste e dispatcher.
Tutte le nuove prove ricompilate e confrontate da resolver indipendente;
33 relocazioni. Target 18% ancora aperto, 51.184 byte mancanti.

Checkpoint 33: 3.871 funzioni, 295.894 byte inventariati (15,462074%).
+23 funzioni e +2.616 byte; 40 byte di pool ulteriori verificati ma non contati.
Il 18% resta aperto: 48.568 byte mancanti. Nessuna ROM completa matching.

Checkpoint 34: +10 funzioni Thumb e +684 byte; 3.881 funzioni, 296.578 byte (15,497817%). Dieci prove ricompilate indipendentemente e 3.089 fixture semantiche passate. Nessuna nuova equivalenza globale dichiarata.

Checkpoint 35: famiglia selezione personaggi. Navigazione completa 6/6; controller 12/23 matching. +9 funzioni, +2.386 byte inventariati (2.760 nello span); totale 298.964 byte, 15,622498%. 2.240 casi C/Thumb passati con dipendenze grafiche controllate.

Checkpoint 36: quattro funzioni collegate al menu personaggi, +362 byte inventariati (370 nello span). Totale 299.326 byte e 3.894 funzioni; 15,641415%. Target16% non raggiunto, 6.863 byte mancanti. Famiglia personaggi 15/23.
