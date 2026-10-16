# Checkpoint 34

3.881 funzioni, 296.578 / 1.913.676 byte inventariati: **15,497817%**.
Incremento: dieci funzioni, 684 byte; nessun byte extra conteggiato.

Ricostruzioni Thumb con strutture tipizzate: transizione di stato, avanzamento
e append di lista, conteggio di una maschera, lettura file con controllo dimensione,
notifiche callback e predicato di disponibilità. Ricerca: 22 varianti, dieci match.
Il candidato 0200bd34 è escluso perché non matching.

Tutte le dieci aggiunte sono state ricompilate senza cache, risolte e confrontate
anche con il resolver indipendente; 15 relocazioni. Nessun sorgente precedente
verificato è stato modificato. Misura e report controllano gli hash dell'intero corpus;
l'audit di compilazione di questa sessione è mirato alle nuove aggiunte.

3.089 fixture valide sulle routine originali Thumb confrontate con modelli
espliciti: 1.024 transizioni, 1.024 maschere, 1.024 predicati, 17 append
a liste acicliche. Controllati anche i buffer completi delle fixture.
Questi test verificano l'interpretazione dei campi; non sono confronto C host
o equivalenza del gioco completo. Le sei routine con chiamate esterne non
hanno un nuovo test semantico.

Per il 18% mancano 47.884 byte. ROM completa, ABI globale e build indipendente
dal C restano non verificati. Nessuna nuova osservazione REA o runtime.
