# Checkpoint 36 — avanzamento verso il 16%

**Il 16% non è raggiunto.** Totale 299.326 / 1.913.676 byte inventariati
(15,641415%); mancano 6.863 byte. Incremento: quattro funzioni e 362 byte inventariati (370 nello span).

Ricostruiti nel menu personaggi l'evidenziazione icona (76), aggiornamento celle
(52), helper animazione (34 byte inventariati, 42 nello span) e controllo risorse grafiche (200). Il controller
è a 15/23 funzioni matching; navigazione completa resta 6/6.
Le due routine icone richiedono il blocco grafico annidato a state+0x1c.

Quattro nuove ricompilazioni senza cache, confrontate anche con il resolver
indipendente; 24 relocazioni. Riconfermati i 2.240 casi semantici di navigazione
del checkpoint35; non sono nuovi test delle quattro aggiunte. Misura e hash
del corpus controllati; nessuna nuova ricompilazione globale dichiarata.

Esteso il recupero prototipi alle prove batch del gioco, con controllo hash e
cache invalidata dai registri. Sette test verificano prototipi SDK/gioco,
sorgenti alterati, argomenti mancanti ed effetti collaterali.

Ricerche nei report JSON: 581 tentativi menu, 1.013 sulle dipendenze a tre
livelli, 68 sul rendering tipizzato e 10 sul controller principale. Diversi
match sono duplicati delle prove precedenti. Il controller principale corretto
compila ma resta non matching: escluso. Nessun progresso da compilabilità
o assembly conteggiato. Nessuna equivalenza globale o nuova prova runtime.
