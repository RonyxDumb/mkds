# Checkpoint 37 — selezione personaggi

Due nuove funzioni C verificate localmente: `02027084` (76 byte, aggiornamento parametri icone) e `020273c0` (100 byte, avvio transizione di uscita).

Il confronto con il Thumb originale mostra che `02128310` riceve zero in r0. Nel ciclo icone l’offset viene inizializzato solo dopo il controllo del numero di elementi. Questi dettagli sono stati corretti nei candidati C; non sono patch ai byte oggetto.

Accettazione: due ricompilazioni senza cache, 176 byte e nove relocazioni, confermate dal resolver indipendente. Prova: `verification/checkpoint37-character-render-audit.json`; sorgenti e metadati nei registri delle prove. Ricerca riproducibile: `scripts/search_character_render_followup.py` (117 tentativi; solo due indirizzi exact). Gli altri candidati restano esclusi.

Totale: 3.896 funzioni, 299.502 / 1.913.676 byte inventariati, 15,650612%. Controller selezione personaggi: 17/23; 3.004/7.084 byte. Mancano 6.687 byte inventariati per il 16%. Nessuna nuova prova runtime e nessun matching della ROM intera dichiarato. La misura globale ricontrolla hash e prove storiche; non ricompila tutte le funzioni precedenti.
