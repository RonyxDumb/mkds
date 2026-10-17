# Checkpoint 38 — selezione personaggi: 22/23

L’obiettivo 23/23 non è ancora raggiunto. Cinque nuove funzioni C accettate con ricompilazione senza cache e resolver indipendente:

| Funzione | Byte inventariati | Span verificato | Relocazioni |
|---|---:|---:|---:|
| 02026058 — display/blending | 140 | 140 | 3 |
| 0202721c — grafica associata | 112 | 112 | 3 |
| 020272ec — rimozione evidenziazione | 96 | 96 | 2 |
| 0202734c — visibilità icone | 116 | 116 | 2 |
| 02026120 — controller input/stati | 1.914 | 2.032 | 104 |

Totale aggiunto: 2.378 byte inventariati, 2.496 byte di span e 114 relocazioni. Prove: `checkpoint38-character-helpers-audit.json` e `checkpoint38-character-controller-audit.json`. Famiglia fissata: 22/23, 5.382/7.084 byte inventariati.

Il controller è C ricompilato, senza sostituzioni dei byte oggetto. Recuperati i literal pool DAT, il sotto-oggetto grafico, le firme di divisione e animazione, la priorità dei tasti e l’ordine dei rami. Il verificatore degli span ora evita di interpretare i pool intermedi come istruzioni LDR e riconosce solo padding preceduto da salto esatto del pool o ritorno finale. I 118 byte esclusi dall’inventario del controller sono 92 byte di literal pool, 20 di switch e 6 di padding verificato.

Inizializzatore `02026910`: candidato C autosufficiente in `scripts/inputs/character-select/initializer-candidate.c`, 1.908 byte compilati contro 1.908 originali, 19 byte diversi in tre sequenze. Escluso integralmente dai progressi. Ricostruiti gli heap, i record grafici, i personaggi sbloccati e il layout, ma compilabilità e somiglianza non sono prova di equivalenza. Il candidato non sostituisce la bozza pubblicata in src. `scripts/check_character_initializer_candidate.py` riproduce il confronto e riporta tutti gli offset diversi.

Verifiche: audit indipendente delle cinque aggiunte; nove test del verificatore degli span; 2.240 regressioni C/Thumb della navigazione già esistente; misura globale di hash sorgenti e prove contro il riferimento. Nessuna nuova verifica runtime del controller o dell’inizializzatore; nessuna ricompilazione globale né equivalenza della ROM intera dichiarata.

Stato globale: 3.901 funzioni, 301.880/1.913.676 byte inventariati, 15,774875%. Mancano 4.309 byte inventariati per il 16%.
