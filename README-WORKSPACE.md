# Mario Kart DS EUR — checkpoint 6

**7.598 file compilabili su 12.038 (63,12%); 4.440 da correggere.**

Sorgenti, prove e istruzioni di ripresa sono inclusi. La percentuale indica compilabilità di singoli file, non decompilazione completa o correttezza del gioco. Le 613 funzioni localmente byte-exact sono inalterate. Leggere `RISULTATI.md`, `PROGRESSO.json` e `RIPRENDI.md`.

ROM di origine: Mario Kart DS EUR, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

Sono presenti **12.038 bozze C per funzione**, con tipi, dichiarazioni per funzione e riferimenti agli indirizzi originali. Non sono un sorgente originale recuperato, una decompilazione matching completa o un gioco ricompilabile.

- `src/arm9/`: codice principale e ITCM, 7.807 file C.
- `src/arm9_ov000/`, `arm9_ov001/`, `arm9_ov003/`: 1.381, 844 e 1.024 file C.
- `src/arm9_ov002/`: dati e BSS; nessuna funzione identificata.
- `src/arm7/`: 982 file C.
- `src/*/index.tsv`: indirizzi, nomi e stato dell'esportazione.
- `src/*/deps/`: dichiarazioni specifiche e variabili globali agli indirizzi della ROM.
- `src/ghidra_compat.h`: tipi e operazioni a larghezza fissa usate dal decompilatore.
- `manual/race_queries.c`: due ricostruzioni manuali alternative; non aggiungerle insieme alle versioni omonime decompilate.
- `scripts/`: generazione delle bozze e verifica della compilazione.

## Stato di questa versione

Esportazione C completata. Verificati 12038 file: **7598 producono oggetti ARM**, **4440 hanno ancora errori**. Il dettaglio è in `RISULTATI.md`, `checks/arm-build.tsv` e `checks/summary.json`. La presenza di un file C e la compilazione non ne dimostrano la correttezza.

## Compilare per controllare i file

```cmd
python -m pip install ziglang==0.14.1
python scripts\check_arm.py
```

Questo produce oggetti per ARM946E-S (ARM9) e ARM7TDMI (ARM7), non una ROM. Controlla errori di tipi, dichiarazioni e compilazione; non verifica la corrispondenza dei byte, il comportamento del gioco o la correttezza dell'ABI tra funzioni.

## Limiti rilevati

Tipi e firme inferiti possono essere errati. Sono presenti chiamate indirette non risolte, pseudo-operazioni non ricostruite e avvisi nel C. I simboli `Maybe_*` sono ipotesi. Le funzioni trovate automaticamente possono essere falsi positivi. Gli indirizzi delle variabili sono assoluti e gli overlay devono essere caricati separatamente nel rispettivo spazio RAM.

Le funzioni `func_0213d398` e `func_0213deec` sono state recuperate correggendo il modello Ghidra delle letture ARM di word non allineate. In questa rigenerazione il modello ARM5t usa il comportamento legacy little-endian di lettura allineata e rotazione, con controllo di allineamento disabilitato; il modello Thumb e quello ARM7 restano invariati. Il dettaglio è in `scripts/arm9-ldr-alignment.txt`. La ROM non è stata modificata.

Le notazioni di accesso a parti di variabili, come `x._2_2_`, sono state convertite in accessi C ai byte dell'oggetto. `checks/slice-normalization.tsv` elenca i file modificati. Questi adattamenti non convalidano eventuali tipi sbagliati a monte.

Per il matching occorrono il compilatore originale `mwccarm`, confronto delle relocazioni e una build completa verificata. La verifica locale ora è disponibile per un sottoinsieme, ma linking completo e avvio in emulatore non sono stati verificati.

Per rigenerare il C servono Ghidra 11.3.2, JDK 21, i file GZF del primo archivio e il modello ARM descritto in `scripts/arm9-ldr-alignment.txt`. Lo script `run_exports.py --projects PERCORSO --ghidra PERCORSO` esegue l’esportazione; il modello ARM va applicato prima. `prepare_c.py` prepara dichiarazioni e helper una sola volta su una nuova esportazione; non va rieseguito sui sorgenti già preparati.

## Checkpoint 2 — verifica locale dei byte

84 funzioni semplici sono state riscritte in C e ricompilate con mwccarm 1.2/sp2p3. Le sequenze complete, lunghezze incluse, coincidono con la ROM per 644 byte. Nessuna relocazione, differenza mascherata, assembly inline o array di byte eseguibile. Prove e sorgenti sono in `verification/`. Questa verifica locale non equivale a una ROM completa matching. Il conteggio ARM generale è quello del checkpoint precedente finché non viene ricontrollato.

## Checkpoint 3 — 613 funzioni verificate localmente

613 funzioni, pari a 8.728 byte di codice, ricompilano con byte identici all’originale usando mwccarm 1.2/sp2p3. Tutte producono anche oggetti ARM con Clang. I byte non sono mascherati e non ci sono relocazioni, assembly inline o array eseguibili. `verification/local-byte-exact.tsv` registra indirizzi, dimensioni e hash dei byte e dei sorgenti. `verification/clang-recheck.json` contiene il controllo ARM delle 613 sostituzioni.

Il totale generale resta 5.419 file compilabili (45,02%): tutte le 613 sostituzioni riguardano file già compilabili, ora meglio verificati. 613/12.038 = 5,09% delle funzioni individuate ha questa verifica locale; NON è la percentuale di matching della ROM completa e NON è una misura pesata sui byte del gioco. Restano ABI fra funzioni, linking completo e avvio da verificare.

## Aggiornamento del checkpoint 4

Tipizzati 846 puntatori caricati da literal pool PC-relative verso una funzione indicizzata. Il tipo segue la firma del destinatario, senza inventare argomenti o alterare i corpi delle funzioni. 484 nuove compilazioni sono riuscite. Le firme inferite non verificate e la compatibilità ABI globale restano da controllare. Nessun linking completo o test in emulatore è stato eseguito.

## Copertura misurata

Matching locale ponderato per dimensione: **0,4561%** (8.728 / 1.913.676 byte attribuiti alle funzioni identificate). Per numero di funzioni: 613 / 12.038, cioè 5,0922%. Vedere reports/MISURA-DECOMP.md e reports/progress-measured.json per metodo, limiti e dati per funzione. Non è una misura della correttezza funzionale dell’intero decomp.
