# Checkpoint 29 — dizionari, animazioni e audio

**3.819 funzioni; 291.822 / 1.913.676 byte inventariati: 15,249290%.**
Dal checkpoint 28: **8 funzioni, 2.452 byte**, +0,128130 punti percentuali.
Denominatore invariato; copertura locale delle funzioni censite, non ROM completa.
Per arrivare al 18% mancano **52.640 byte inventariati** verificati.

| Indirizzo ARM9 | Funzione / sorgente ricostruito | Byte |
|---|---|---:|
| `02013754` | Ricerca indice nel dizionario, lineare e Patricia | 352 |
| `020138b4` | Ricerca dati per nome nel dizionario | 380 |
| `020155d8` | Valori animazione colore materiale | 432 |
| `02015894` | Animazione SRT delle texture | 256 |
| `02016638` | Aggiornamento animazione materiale | 68 |
| `0205fe1c` | Generazione codice Prove a tempo | 488 |
| `0212baa8` | Inizializzazione audio | 168 |
| `0212e0b8` | Caricamento tabella archivio onde audio | 308 |

Quattro ricostruzioni pendenti sono state recuperate e ricontrollate; quattro
nuove coincidono dopo correzioni dell'importatore e degli helper inline.
I nomi esistenti dell'inventario restano invariati.

I sorgenti provengono dai donor già fissati nelle prove SDK. Le ipotesi sulla
versione storica rimuovono controlli di null e, per due helper dei dizionari,
i controlli di validità di dizionario e indice. L'accettazione richiede comunque
ricompilazione e confronto esatto di lunghezza e di ogni byte originale,
risolvendo tutte le relocazioni. Nessun opcode o assembly aggiunto ai C.
I file possono contenere altre funzioni del donor: è verificata esclusivamente
la funzione nominata nella relativa prova, non l'intera unità di traduzione.

L'importatore preserva i campi di struct durante la rinomina, gestisce i
suffissi dei simboli statici locali MW e mantiene le dichiarazioni SDK delle
chiamate pubbliche. Il compilatore può essere scelto per funzione: percorso e
SHA-256 della variante `1.2/base` sono registrati e controllati prima dell'audit.
Il setup recupera le varianti dalla medesima distribuzione con hash fissato.

Audit completo: **1.444/1.444** funzioni senza relocazioni e **2.375/2.375**
con relocazioni; **7.414 relocazioni** risolte. Span confrontati: 294.346 byte;
i 2.524 byte extra storici restano esclusi dal numeratore dell'inventario.
Dopo la pulizia degli spazi finali, le tre funzioni interessate sono state
ricompilate e riconfrontate, poi i test dei dizionari sono stati rieseguiti.

Test semantici: **9.792 casi** confrontano le istruzioni ARM originali in
Unicorn con i corpi C attuali compilati per host e con un risultato atteso
indipendente. Dizionari allineati con 0, 1, 2, 7, 15, 16 o 32 elementi,
ricerche riuscite e fallite, stride diversi; confronto dell'intero buffer
prima/dopo ogni chiamata. Non coprono input corrotti o tutte le possibili
strutture Patricia. Eseguire `scripts/test_dictionary_semantics.py` con gcc e
Unicorn; le dichiarazioni host riproducono i layout SDK a larghezza fissa.

Prove hash-only e riepilogo in `verification/checkpoint29-search-summary.json`.
Nessuna nuova esplorazione runtime del gioco in questo checkpoint.
Linking globale, ABI dei chiamanti e matching dell'intera ROM restano non verificati.

Ricerca ulteriore con MWCC `1.2/sp2`, `sp3` e `sp4`: 4.149 oggetti SDK ARM9,
SDK ARM7 e NitroSystem; nessuna corrispondenza nuova accettata. Dettagli, hash
dei compilatori e conteggi in `verification/checkpoint29-compiler-search.json`.
Il report objdiff è stato controllato anche senza gli archivi binari privati,
usando le prove hash-only per tutte le otto funzioni nuove.
