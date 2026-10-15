# Ricerca batch e sessioni REA riutilizzabili

I due comandi separano l'analisi dal matching: il pseudocodice resta un draft;
solo compilazione e confronto completi producono una nuova prova.
Richiedono Linux/Python, Capstone e pyelftools. La ricerca richiede il toolchain
MWCC/Wibo già previsto dal progetto e i binari estratti privati in `baseline/binaries`.
REA richiede inoltre il setup locale documentato in `reports/REA-PID-FIX.md`.
Nessuna ROM o dipendenza binaria viene pubblicata.

## Una sessione REA per gruppo

```sh
python scripts/rea/batch_decompile_mkds.py arm9 \
  0x0200104c 0x020016ac 0x020019b0 0x02001abc
```

Usa i contratti pubblici MCP `open_binary`, `procedure_pseudo_code`, `close_binary`.
Una sola importazione/analisi Ghidra serve tutte le richieste del gruppo. Le
funzioni sono seminate prima dell'analisi e ciascun risultato conserva l'evidenza
REA, hash del target e profilo CPU/ISA. Il comando rifiuta gruppi con sezioni o
modalità differenti. Suddividere ARM e Thumb e mantenere gli overlay separati.
Il target è lo span tra prima e ultima funzione, al massimo 1 MiB: non rappresenta
l'intera memoria DS. Dati e chiamanti esterni possono restare incompleti.

Il default salva sotto `build/rea-batch/<modulo_hash_modo>`. `--output` sceglie
una directory esplicita; `--one-shot` ripete le equivalenti chiamate CLI per
misurare il costo delle sessioni separate. Le bozze non vengono integrate nel C.

## Compilazioni parallele, cache e ripresa

```sh
python scripts/batch_matching.py --workers 4 --limit 2000 \
  --summary build/search.json
# Ripetere riprende con i risultati già disponibili:
python scripts/batch_matching.py --workers 4 --limit 2000 \
  --summary build/search-resumed.json
# Privilegiare le funzioni più vicine al match:
python scripts/batch_matching.py --queue build/search.json --limit 2000 \
  --summary build/near-misses.json
```

`--limit` conta varianti, non funzioni. Sono disponibili filtri per modulo e
size; `--optimization=-O4,p` limita una prima passata al flag più comune. La
scansione comprende le prove ISA supplementari ARM7 già presenti nel repository,
che i vecchi scanner basati solo su `baseline/symbols` lasciavano fuori.

La cache comprende risultati positivi e negativi e lega ogni tentativo a:

- sorgente completo, byte originali, indirizzo, modulo e modalità;
- hash di compilatore e Wibo, flag, versione Python e librerie di lettura;
- resolver, generatore e mappa completa dei simboli, incluse ambiguità.

Un positivo in cache viene comunque ricollegato e riconfrontato. Oggetti corrotti
vengono rigenerati. Timeout, segnali e problemi d'ambiente non sono hit negativi.
Le compilazioni dello stesso tentativo sono protette da un lock; i sorgenti sono
condivisi per hash tra ottimizzazioni. Cache e oggetti restano in `build/`.

Errori frontend riconosciuti (identificatori mancanti, sintassi, conversioni di
tipo e firme incompatibili) interrompono la ripetizione degli altri livelli di
ottimizzazione dello stesso sorgente. Gli altri errori conservano i tentativi.
`--exhaustive-errors` disabilita questa scorciatoia per confronto o diagnosi.

La coda `near_misses` riporta differenze di byte **dopo** risoluzione delle
relocazioni; è solo una priorità di lavoro, mai un matching parziale accettato.
Un'interruzione lascia i risultati dei tentativi già completati nella cache.

## Accettazione separata e audit indipendente

```sh
python scripts/accept_batch_matches.py build/search.json \
  --audit-name batch-my-session-audit.json
```

Il comando richiede un nuovo nome di audit, ricompila senza fidarsi della cache,
confronta nuovamente tutti i byte e usa anche il resolver indipendente dell'audit
storico. Solo dopo registra il match, conserva il draft precedente e aggiunge
prove hash-only. Non cambia i progressi del checkpoint automaticamente. Riprendere
un'accettazione interrotta con un nuovo nome di audit: le funzioni già registrate
sono saltate e conservano la propria prova precedente.

La misura e il report objdiff si aggiornano con `measure_progress.py` e
`export_objdiff_report.py`. Matching locale, ABI dei chiamanti, linking globale
e corrispondenza dell'intera ROM restano verifiche distinte.

## Misure del checkpoint 31

| Prova | Prima | Dopo |
|---|---:|---:|
| Quattro funzioni REA, stesso target/seeds e output identici | 53,98 s, quattro sessioni | 13,61 s, una sessione |
| 6.578 candidati, una ottimizzazione | 29,75 s, 6.578 compilazioni | 5,62 s, zero compilazioni alla ripetizione |
| 500 candidati, sei ottimizzazioni | 16,77 s, 3.000 compilazioni | 11,16 s, 1.015 compilazioni con riconoscimento frontend |
| Ripetizione degli stessi 500 candidati con cache | — | 6,59 s, zero compilazioni |

Una ricerca successiva ha provato 9.913 varianti e 59.470 combinazioni in 191,92 s.
I confronti misurano tempo reale nello stesso ambiente; la cache del filesystem
non è stata azzerata. Non sono stime della velocità dell'intero decomp. Il dettaglio
con fingerprint, CPU e RSS disponibili è in `verification/batch-acceleration-benchmark.json`.
L'RSS massimo dei figli non è la memoria totale della famiglia di processi.

Verifiche: `test_batch_matching.py`, `test_hash_only_proof.py`, `test_compare_rom.py`.
Il test reale di compilazione viene saltato se il toolchain privato non è presente.
