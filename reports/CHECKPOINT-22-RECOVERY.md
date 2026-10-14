# Checkpoint 22: risultati verificati, pubblicazione incompleta

Il runtime di lavoro si è disconnesso prima del commit dei sorgenti. Questo documento registra il risultato dell'ultima verifica locale; non modifica le metriche pubblicate di main e non costituisce il corpus di prove.

## Risultati locali

Inventario invariato: 1.913.676 byte.
Checkpoint 21: 3.115 funzioni, 216.982 byte, 11,3384919913%.
Checkpoint 22 verificato localmente: 3.768 funzioni, 287.410 byte, 15,0187388043%.
Incremento: 653 funzioni, 70.428 byte, 3,68024681294 punti percentuali.
Il minimo di 3 punti è superato; 5 punti non sono raggiunti.

Audit completo: 1.409 funzioni senza rilocazioni e 2.359 con rilocazioni, tutte passate; 7.341 rilocazioni risolte. Span complessivi 289.938 byte, distinti dai 287.410 byte dell'inventario.
Questi dati sono registrati qui come risultati locali: i nuovi sorgenti e i report completi non sono ancora disponibili nel repository.

## Ripresa

Workspace da recuperare: /workspace/scratch/08c1180a1354/mkds
Preservare le modifiche locali prima di sincronizzare main.
File principali: verification/checkpoint22-search-summary.json, verification/sdk-source-proofs.json, verification/hash-only-proofs.json, reports/CHECKPOINT-22.md, scripts/prepare_mkds_candidates.py, scripts/matching_compiler.py.
Il commit di partenza era 84ed47a7a29d4ac32bcc4bdb511771ac2d8aa065.

Donor principale: ai-tdd-labs/mkds-decomp, commit c6e18fa4b346643b74c402b605a84b43cba16c01.
970 candidati C: 650 corpi accettati dopo compilazione, risoluzione delle rilocazioni e confronto completo con la ROM. Per i restanti 320, 1.600 compilazioni con cinque varianti di ottimizzazione non hanno aggiunto match. Le altre tre funzioni provengono dalle ricerche nelle librerie.
Compiler predefinito MW 1.2/sp2p3 build 82; ulteriori match con build 72. Conservare hash e compiler registrati per ciascuna prova.
Conservare integralmente licenza e avvisi del donor. Non pubblicare ROM o dump dei byte originali: i nuovi hex erano stati spostati nella cache privata ignorata.

Dopo recupero: verificare integrità dei sorgenti e delle prove, ripetere gli audit pertinenti, pubblicare corpus e report su main, quindi aggiornare le metriche. Non ricostruire i 653 sorgenti a partire da questo riepilogo.

## Confronto ROM

L'integrazione locale delle 3.768 funzioni mantiene tutti i moduli decompressi identici al riferimento. Il confronto fisico dell'intera ROM resta: originale 33.554.432 byte, ibrida 25.562.152; 25.471.568 byte uguali e 8.082.864 differenti o mancanti.
L'ibrida conserva codice, dati e asset del riferimento: non è una ricompilazione autonoma completa.
Nessun nuovo test emulatore è stato eseguito per checkpoint 22. I risultati runtime del checkpoint 21 restano limitati alla schermata titolo e non dimostrano equivalenza del gameplay.

La pubblicazione dei nuovi sorgenti è stata bloccata da 409 environment_offline; anche il trasferimento di recupero è fallito. Non è accertata la perdita dei file locali.
