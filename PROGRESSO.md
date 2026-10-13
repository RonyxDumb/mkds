# Progressi salvati

| Checkpoint | Compilabili ARM | Percentuale | Funzioni con byte locali identici | Byte identici |
|---|---:|---:|---:|---:|
| 3 | 5.419 | 45,02% | 613 | 8.728 |
| 4 | 5.903 | 49,04% | 613 | 8.728 |
| 5 | 6.364 | 52,87% | 613 | 8.728 |
| 6 | 7.598 | 63,12% | 613 | 8.728 |

Checkpoint 4: 846 puntatori tipizzati, 484 nuove compilazioni riuscite.

Checkpoint 5: 4.957 dichiarazioni di chiamate con indirizzo risolte verso definizioni indicizzate; +461 compilazioni.

Checkpoint 6: 8.280 reinterpretazioni esplicite di valori ARM32 e puntatori in 2.581 file; +1.234 compilazioni, nessuna regressione. Non cambia il numero di argomenti e non vengono rimossi errori disabilitando controlli. Le firme restano inferite e richiedono verifica.

L'intervento dal checkpoint 4 aggiunge 1.695 file compilabili. La verifica byte-exact resta a 613 funzioni. Non è stata verificata una ROM completa.
