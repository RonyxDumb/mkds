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
