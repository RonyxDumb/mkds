# Progressi salvati

| Checkpoint | Compilabili ARM | Percentuale | Funzioni con byte locali identici | Byte identici |
|---|---:|---:|---:|---:|
| 3 | 5.419 | 45,02% | 613 | 8.728 |
| 4 | 5.903 | 49,04% | 613 | 8.728 |
| 5 | 6.364 | 52,87% | 613 | 8.728 |
| 6 | 7.598 | 63,12% | 613 | 8.728 |
| 7 | 7.598 | 63,12% | 776 | 13.142 |
| 8 | 7.598 | 63,12% | 1.024 | 21.978 |

Checkpoint 4: 846 puntatori tipizzati, 484 nuove compilazioni riuscite.

Checkpoint 5: 4.957 dichiarazioni di chiamate con indirizzo risolte verso definizioni indicizzate; +461 compilazioni.

Checkpoint 6: 8.280 reinterpretazioni esplicite di valori ARM32 e puntatori in 2.581 file; +1.234 compilazioni, nessuna regressione. Non cambia il numero di argomenti e non vengono rimossi errori disabilitando controlli. Le firme restano inferite e richiedono verifica.

L'intervento dal checkpoint 4 aggiunge 1.695 file compilabili. La verifica byte-exact resta a 613 funzioni. Non è stata verificata una ROM completa.


Checkpoint 7: +163 funzioni e +4.414 byte localmente identici. Ricompilazione MW e Clang di tutte le 776 riuscita.

Checkpoint 8: +248 funzioni; +8.836 byte. 937 senza relocazioni, 87 con tutte le relocazioni applicate. Copertura inventariata: 1,1485%.
