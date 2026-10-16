# Checkpoint 35 — famiglia selezione personaggi

Navigazione completa: **6/6** (cinque griglie + dispatcher). Controller totale:
**12/23** con matching locale, 2.500 / 7.084 byte. Inizializzatore e controller
principale ancora aperti: vedere [mappa completa](CHARACTER-SELECT-FAMILY.md).

Incremento corpus: nove funzioni, 2.386 byte inventariati; 2.760 byte di span
confrontati, 374 esclusi dal numeratore. Totale 3.890 funzioni, 298.964 byte
(15,622498%). Denominatore invariato.

Ricostruiti in C tipizzato tutti i layout 8–12 personaggi, il dispatcher,
la distruzione heap, un aggiornamento grafico e l'inoltro azione condizionale.
Usato MWCC 1.2/base, richiesto dallo switch originale; executable hash e flag
registrati. Nove nuove ricompilazioni indipendenti e 71 relocazioni risolte.
La misura rilegge hash del corpus e binari originali; nessun nuovo audit di
compilazione globale dichiarato.

2.240 casi C host/Thumb originale: buffer512 completi, cursori validi e invalidi
per le griglie, tutti i layout e cursori precedenti 0–15. Per il dispatcher,
quattro dipendenze grafiche/animazioni sono fixture controllate; le cinque
griglie reali vengono eseguite. Nessuna osservazione runtime/REA nuova.

Esteso il certificatore degli span allo schema switch Thumb MW con limite
esplicito, tabelle signed di destinazioni Thumb e NOP terminale identificato.
Non conta tali dati come nuovi byte C. Sei test positivi/negativi sullo
span e cinque sulle prove hash-only passati. Report objdiff e treemap aggiornati.

La famiglia resta la priorità per le prossime sessioni. ROM completa e ABI
globale non verificati; per il 18% mancano 45.498 byte.
