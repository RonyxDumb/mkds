# Checkpoint 27 — missioni e query di gara

**3.789 funzioni; 288.062 / 1.913.676 byte inventariati: 15,052809%.**
Dal checkpoint 26: **12 funzioni, 568 byte**, +0,029681 punti percentuali.
Il denominatore rimane invariato. Questa è copertura locale dell'inventario
funzioni, non una percentuale di completamento o matching dell'intera ROM.

| Ricostruzioni ARM9 | Funzioni | Byte |
|---|---:|---:|
| Livello e stage della missione, incluse le copie in altri contesti | 6 | 192 |
| Identificazione giocatore e stato di arrivo del pilota | 2 | 80 |
| Selezione dei dati del menu modello kart | 1 | 44 |
| Controlli boss missione, incluso livello 6/7 | 2 | 100 |
| Conferma cancellazione salvataggio nella scena iniziale | 1 | 152 |

Le bozze delle query sono state sostituite da C con campi tipizzati e padding
esplicito. Livello/stage e ID locale sono signed a 8 bit; l'ID di rete è unsigned.
Le copie identiche sono contate ai rispettivi indirizzi dell'inventario, senza
presentarle come comportamenti nuovi distinti. Nomi preesistenti e layout
parziali non certificano l'ABI globale.

Ricompilate tutte le 1.421 prove senza relocazioni e le 2.368 con relocazioni;
risolte e confrontate tutte le 7.372 relocazioni. Confronto completo dei byte e
delle dimensioni, senza mascherare le chiamate. Gli span completi sommano
290.586 byte; i 2.524 byte extra già presenti nei checkpoint precedenti non
vengono aggiunti al numeratore. Prove pubblicabili tramite hash e audit in
`verification/checkpoint27-search-summary.json`.

`scripts/test_mission_semantics.py` esegue le istruzioni originali in Unicorn e
le confronta con gli attuali sorgenti C compilati per host: **20.792 casi
riusciti**, inclusi tutti i valori degli interi a 8 bit, modalità inattive,
short-circuit dei boss 6/7 e gli otto slot pilota. Solo i puntatori globali
vengono reindirizzati a buffer host; i campi e il flusso restano quelli dei C
verificati. È un controllo locale dei risultati, non dei tempi, delle tracce RAM
o dell'intero gioco.

Ricerca aggiuntiva: 3.537 candidati donor compilati nell'altra ISA rispetto alle
ricerche precedenti, **zero nuovi match**. Script riproducibile
`prepare_opposite_isa_candidates.py`, poi `verify_sdk_sources.py` con il config
generato. Non ripetere questa ricerca senza nuove varianti o ricostruzioni.

Non è stata eseguita nuova esplorazione runtime dei menu o nuova analisi REA
in questo checkpoint. Restano validi i limiti del report precedente. Prossimi
candidati: `GetCurrentOptionMenuKind_from_thumb` e `Scene_Emblem_Update`, ancora
non matching per differenze nel flusso generato; non inclusi nei progressi.

Controllo d'integrazione ibrido riuscito: inserite 3.789 funzioni compilate e
290.586 byte di span unici, poi riletti i moduli decompressi senza differenze.
Il contenitore risultante conserva codice e dati di riferimento non ricostruiti;
non è una build indipendente dai C. Il confronto fisico completo resta diverso
(25.562.152 contro 33.554.432 byte), come nei checkpoint precedenti.
