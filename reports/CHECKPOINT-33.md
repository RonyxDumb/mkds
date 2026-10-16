# Checkpoint 33 — il target 18% resta aperto

**3.871 funzioni; 295.894 / 1.913.676 byte inventariati: 15,462074%.**
Incremento dal checkpoint 32: **23 funzioni e 2.616 byte inventariati**,
pari a 0,136700 punti percentuali. I nuovi span confrontati sono 2.656 byte;
40 byte di literal pool restano esclusi dal numeratore.
Per raggiungere il 18% mancano **48.568 byte inventariati verificati**.

## Risultati verificati

| Modulo | Indirizzo | Byte confrontati |
|---|---|---:|
| arm7 | 0x037fc420 | 88 |
| arm9 | 0x02122794 | 100 |
| arm9 | 0x02122734 | 68 |
| arm9 | 0x020f82c4 | 36 |
| arm9 | 0x020f82e8 | 36 |
| arm9 | 0x02146d28 | 28 |
| arm9 | 0x02024868 | 20 |
| arm9 | 0x02024960 | 20 |
| arm9_ov001 | 0x021807e4 | 28 |
| arm7 | 0x037ff000 | 296 |
| arm9 | 0x02028f08 | 24 |
| arm7 | 0x037fbf70 | 52 |
| arm7 | 0x037fb96c | 72 |
| arm7 | 0x037fc584 | 96 |
| arm7 | 0x037fcc70 | 36 |
| arm7 | 0x037fc3d0 | 56 |
| arm9 | 0x02012cbc | 616 |
| arm9 | 0x0210b564 | 172 |
| arm9 | 0x02133f84 | 84 |
| arm9 | 0x0214e0f4 | 136 |
| arm9 | 0x0214f060 | 320 |
| arm9 | 0x0214f418 | 140 |
| arm7 | 0x037f8b64 | 132 |

- Audio ARM7 da una versione precedente delle ricostruzioni SDK: avvio,
  note, capture, confronto volume, attack, fine sleep e generatore casuale.
- Caricamento risorse 3D: il percorso storico libera tutte e tre le chiavi
  sul fallimento. Questa differenza è ricostruita in C e provata su tutti i byte.
- RTC, microfono e lock: isolate le funzioni C in unità che contengono anche
  primitive assembly; quelle primitive sono dichiarate esterne, senza corpi finti.
  Nessun corpo assembly è stato importato come nuovo match C.
- Due chiamanti SDK da 172 e 84 byte dopo la riparazione dei prototipi.
- Sette nuove foglie da 308 byte richiedono MWCC 2.0/base. Il percorso, hash
  e flag sono conservati in batch-source-proofs.json; gli audit li rispettano.

## Correzione dei prototipi

sdk_signatures.py cercava il nome del donor nel C già rinominato e non trovava
molte definizioni. Ora usa il simbolo effettivo e indicizza le prove per modulo.
Non inventa argomenti mancanti e non elimina argomenti con effetti collaterali.
Quattro test coprono rinomina, argomenti mancanti, effetti collaterali e moduli.

## Ricerche e limiti

20.352 varianti di ottimizzazione del donor MKDS: zero nuovi match.
MWCC 2.0/base sui draft: 11.108 varianti, 49.949 compilazioni, sette nuove
funzioni uniche accettate; otto candidati esatti includevano un duplicato.
Prototipi corretti: 719 varianti/2.034 compilazioni, due funzioni;
ripetizione con 1.2/base: 716 varianti/2.031 compilazioni, zero nuovi match.
Altri profili SDK, librerie precedenti e unità C sono registrati in
verification/checkpoint33-search-profiles.json, distinguendo tentativi e accettazioni.
Non ripetere queste stesse ricerche senza cambiare ricostruzioni o ipotesi.

## Verifica

Audit globale fresco della passata: 1.455/1.455 senza relocazioni e
2.409/2.409 con relocazioni (7.536 relocazioni risolte). Le successive sette
foglie 2.0/base sono ricompilate anche dal resolver indipendente. Un ulteriore
audit mirato ha ricompilato tutte le 23 aggiunte sotto il compilatore registrato:
verification/checkpoint33-new-audit.json, con certificati espliciti degli span.
Le precedenti funzioni non sono state modificate.
28 test su prototipi, trasformazioni, batch/cache e prove hash-only passati.
Misura, treemap e report objdiff rigenerati. Nessuna nuova prova runtime,
equivalenza globale, build C indipendente o completamento della ROM dichiarato.

## Ripresa

Continuare con ricostruzioni di famiglie del gioco e confronti semantici.
La scansione automatica dei flag non ha fornito i 48.568 byte mancanti.
Lavorare su main; non cambiare denominatore e non contare assembly o draft come C verificato.
