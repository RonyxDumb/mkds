# Mario Kart DS EUR — decompilazione in corso

Workspace C ricostruito dalla versione EUR di Mario Kart DS. **Non produce ancora una ROM completa ricompilabile e funzionante.**

ROM di riferimento: game code `AMCP`, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`.

## Stato verificato — checkpoint 6

| Misura | Risultato |
|---|---:|
| Funzioni esportate in C | 12.038 |
| File compilabili singolarmente per ARM | 7.598 / 12.038 — 63,12% |
| File con errori di compilazione | 4.440 |
| Funzioni localmente byte-exact | 613 / 12.038 — 5,09% |
| Copertura locale per byte dei corpi funzione identificati | 8.728 / 1.913.676 — 0,4561% |
| Linking di una ROM e avvio del gioco | Non verificati |

La compilabilità non dimostra correttezza funzionale o ABI. La copertura byte-exact è locale, ponderata per le dimensioni dell'inventario Ghidra; non certifica la totalità del codice del gioco. Le funzioni identificate possono includere dati, falsi positivi o byte condivisi.

## Contenuto

- `src/`: tutti i sorgenti ARM9, ARM7 e overlay, tipi e dipendenze per funzione.
- `verification/`: prove byte-exact, hash, modifiche registrate e sorgenti precedenti.
- `checks/`: risultati della compilazione e log degli errori per funzione.
- `reports/`: misurazione ponderata e dati completi per una treemap.
- `baseline/`: inventario delle funzioni, simboli, manifest e script iniziali Ghidra.
- `scripts/`: controllo ARM, verifiche locali e script di esportazione/ricostruzione.
- `manual/`: ricostruzioni alternative; non compilare insieme alle funzioni omonime.

Sono inclusi tutti i sorgenti e i registri del checkpoint. ROM, sezioni binarie, progetti Ghidra GZF e compilatori non sono inclusi. Le sezioni si estraggono da una copia locale della ROM; i progetti GZF dell'analisi precedente sono necessari per riesportare lo stesso database con `run_exports.py`, oppure bisogna ricreare l'analisi Ghidra. Il dettaglio storico è in `README-WORKSPACE.md`.

## Controllare i sorgenti

Richiede Python 3 e le dipendenze:

```sh
python -m pip install -r requirements.txt
python scripts/check_arm.py build/arm-objects
python scripts/recheck_verified.py
```

Il primo comando di controllo compila ogni file separatamente per ARM946E-S o ARM7TDMI e aggiorna `checks/`. Non esegue linking o test del gioco. Il secondo ricontrolla la compilazione dei 613 sorgenti byte-exact.

## Estrarre la ROM di riferimento

```sh
python scripts/prepare_rom.py /percorso/mkds_eu.nds
python scripts/measure_progress.py
```

La ROM viene verificata tramite SHA-1 prima dell'estrazione; le sezioni finiscono in `baseline/binaries/`, escluse da Git. L'inventario originale resta conservato. La misurazione confronta i sorgenti attuali e le prove hex con la ROM estratta; se sono presenti oggetti MW in `build/leaf-candidates`, confronta anche il loro testo completo.

## Riprodurre le prove MW

Serve il compilatore `mwccarm 1.2/sp2p3` (banner Version 2.0 build 82), con Wibo su Linux. Impostare `MWCCARM` e `WIBO`, oppure installare i tool nei percorsi di default sotto `tools/`. `MKDS_BASELINE` può indicare una baseline alternativa.

```sh
python scripts/verify_leafs.py
python scripts/measure_progress.py
```

`verify_leafs.py` ricostruisce e verifica candidati corti, aggiorna le prove e può sostituire sorgenti accettati. Eseguirlo su un branch dedicato e controllare il diff. Gli oggetti generati non vengono versionati. Nessuna differenza dei byte è mascherata e nessuno stub è usato come prova matching.

## Continuare

Leggere `RIPRENDI.md`, `RISULTATI.md` e `reports/MISURA-DECOMP.md`. Recuperare parametri e ritorni dai registri e dallo stack originali, verificare le firme, poi i chiamanti. Non eliminare argomenti o introdurre ritorni soltanto per ottenere una compilazione. La rigenerazione sperimentale con firme bloccate è stata respinta e non è integrata.

Questo repository non ha ancora un Makefile che ricostruisce il gioco: non usare il 63,12% come percentuale di completamento della decompilazione.
