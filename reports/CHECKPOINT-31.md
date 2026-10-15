# Checkpoint 31 — accelerazione misurata del processo

**3.837 funzioni; 292.526 / 1.913.676 byte inventariati: 15,286078%.**
Rispetto al checkpoint 30: **17 funzioni, 652 byte**, +0,034071 punti.
Il denominatore è invariato; non è il matching dell'intera ROM.

## Cambiamenti operativi

- REA usa una sola sessione MCP/Ghidra per un gruppo di funzioni della stessa
  sezione e ISA, con semi espliciti e controllo di hash, profilo e selettore.
- Il motore MWCC esegue ricerche parallele riprendibili, con cache positiva e
  negativa legata a sorgente, compilatore, flag, riferimento, librerie e simboli.
  I positivi in cache sono ricollegati e riconfrontati; l'accettazione ricompila.
- Scansione anche delle funzioni ARM7 con modalità già documentata nelle prove
  supplementari, prima escluse dai driver basati solo sulla symbol map iniziale.
- Errori frontend riconosciuti evitano tentativi su altre ottimizzazioni dello
  stesso C; gli altri errori restano esplorati. Esiste un'opzione esaustiva.
- Sorgenti condivisi per hash tra ottimizzazioni; lookup dei simboli dati
  preindicizzato, cache dei tipi per modulo e lock per tentativo.
- Coda dei cento candidati più vicini al match, senza accettare differenze di byte.

Il resolver della ricerca è ora un modulo importabile senza eseguire scansioni.
L'audit storico conserva la propria implementazione indipendente.

## Misure

Quattro funzioni, stesso target e semi, pseudocodice identico: **53,98 → 13,61 s**
passando da quattro sessioni CLI a una sessione persistente, circa **3,97×**.
La prova Thumb su due funzioni di overlay è riuscita anche con il comando finale.

Prima passata: **6.578 varianti in 29,75 s**. Ripetizione identica: **5,62 s**, senza
compilazioni. Una ricerca esaustiva successiva ha completato **59.470 tentativi**
su **9.913 varianti** in **191,92 s**.

Su 500 candidati con sei ottimizzazioni, riconoscere gli errori frontend riduce
**3.000 → 1.015 compilazioni**, **16,77 → 11,16 s**; la ripetizione con cache
richiede **6,59 s**, zero compilazioni. Misure del motore finale, CPU e RSS
sono conservate separatamente nel benchmark JSON; cache OS non azzerata.
Questi rapporti non sono una promessa sulla velocità dell'intero decomp.

## Nuovo codice

| Gruppo | Funzioni | Byte |
|---|---:|---:|
| Prima ricerca: sei ARM7 e `IncrementRaceIntroFrameCounter` ARM9 | 7 | 480 |
| Helper ARM7 brevi | 8 | 52 |
| Due helper ARM7 a `06009710` e `0600974c`, MWCC `-O2` | 2 | 120 |
| Totale | 17 | 652 |

Dieci match senza relocazioni; sette con relocazioni, **29 relocazioni** risolte.
Tutti sono stati ricompilati separatamente e verificati anche dall'audit
indipendente, inclusi lunghezza, dati locali e ogni byte. Sorgenti candidati e
prove cache non sono stati considerati sufficienti per l'accettazione.
I nuovi audit sono mirati alle 17 funzioni; le precedenti conservano i propri
audit storici. Nessuna nuova rivendicazione di linking globale o ABI dei chiamanti.

Il validatore hash-only ammette ora anche batch composti solo da funzioni senza
relocazioni, richiedendo esito completo di entrambi i gruppi e totale non nullo.
Restano controllati hash, riga dell'audit e assenza di claim sulla ROM completa.

## Verifiche e ripresa

**15 test** del batch/cache, incluso compilatore MWCC reale e oggetto corrotto;
**5 test** dell'archivio hash-only; **3 test** del confronto ROM.
**22 oggetti** di regressione coincidono tra resolver della ricerca e audit
indipendente e con i rispettivi span originali. Non è un audit fresco di tutte
le 3.837 funzioni. Misura, treemap e report objdiff rigenerati con successo.

I comandi riproducibili, i prerequisiti e i limiti sono in
[`docs/BATCH-MATCHING.md`](../docs/BATCH-MATCHING.md).
I dati di tempo e gli hash dei risultati REA sono in
`verification/batch-acceleration-benchmark.json`; la coda di lavoro è in
`verification/batch-near-misses.json`.

Mancano ancora **51.936 byte inventariati** verificati per superare il 18%.
Nessun nuovo gameplay o confronto di ROM ricostruite in questo checkpoint.
