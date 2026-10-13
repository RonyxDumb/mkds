# Riprendere il lavoro

Questo ZIP contiene sorgenti, script e risultati del checkpoint 6.

1. Leggere `PROGRESSO.json`, `RISULTATI.md` e `checks/arm-build.tsv`.
2. Non confondere compilabilità con decompilazione completa. Non eliminare errori usando stub, ritorni inventati o prototype permissivi.
3. Conservare le 613 funzioni in `verification/local-byte-exact.tsv`; ogni modifica richiede ricompilazione e nuovo confronto dei byte.
4. Il checkpoint 4 ha tipizzato 846 puntatori con un caricamento PC-relative verso una funzione indicizzata. Dettagli e vecchi header sono in `verification/pointer_typing/`.
5. Prossimo lavoro: riconciliare le firme dei destinatari con registri e stack effettivi, quindi rigenerare i chiamanti. Non aggiungere o rimuovere argomenti soltanto per compilare.
6. Per analizzare i binari, usare il primo archivio `MarioKartDS-EUR-Ghidra-pseudocode.zip`, contenente sezioni decompresse, simboli e programmi Ghidra. Il workspace C non contiene tutte le risorse del gioco.
7. Per verificare la compilazione: Python e Zig 0.14.1, poi `scripts/check_arm.py`. Per verificare i byte locali: Capstone, pyelftools, mwccarm 1.2/sp2p3 e `scripts/verify_leafs.py`.
8. Dopo ogni gruppo: controllare i file modificati, aggiornare i registri e salvare un checkpoint completo.

Stato: 7.598 compilabili, 4.440 falliti; 613 funzioni localmente identiche, 8.728 byte. Linking completo e avvio non verificati.

Checkpoint 6: vedere verification/explicit_arm_casts/ per espressioni, tipi, sorgenti precedenti e audit reversibile. Questi cast non certificano le firme. Le modifiche di rigenerazione sperimentale non sono state integrate: non usare i soli risultati del compilatore per accettarle. Prossimo lavoro: recuperare parametri dai registri di ingresso e stack, verificare ogni ABI, poi rigenerare i chiamanti senza perdita di valori.
