# Riprendere il lavoro

## Stato corrente — 14 ottobre 2026

Lavorare esclusivamente su `main`. La PR #2 e stata integrata nel commit
`0afa03b76f20883d636fb4e150e4cfef5221e2b7`; i riferimenti ai branch nelle
sezioni storiche sotto non descrivono piu lo stato corrente.

La ROM EUR fornita e stata verificata contro lo SHA-1 atteso ed estratta con
`python scripts/prepare_rom.py PERCORSO_ROM`. La toolchain e stata ripristinata
con `python scripts/setup_matching_toolchain.py`; dipendenze Python:
`ndspy`, `capstone`, `pyelftools`, `ziglang==0.14.1`.

Ricompilate e confrontate tutte le 2.288 funzioni del checkpoint 14:
1.251 senza relocazioni e 1.037 con tutte le 2.557 relocazioni risolte.
Confermati 109.144 byte inventariati (5,703369%) e 109.304 byte negli span
completi. Anche gli hash delle dipendenze SDK sono stati verificati.
La ROM completa e l'ABI globale restano non verificati.

I binari estratti e il compilatore restano nelle directory ignorate da Git.
Le sezioni successive sono la cronologia dei checkpoint.

## Checkpoint 9

1.143 funzioni; 27.044 byte verificati localmente. 984 senza relocazioni e 159 dopo linking locale completo delle relocazioni ARM. Nessuna ROM completa verificata.

Impostare MKDS_BASELINE alla cartella MarioKartDS-EUR-analysis del primo archivio, MWCCARM a mwccarm 1.2/sp2p3 e WIBO al runner. Installare capstone, pyelftools, ziglang==0.14.1.

Verifiche:
- python scripts/audit_local_matching.py
- python scripts/audit_resolved_calls.py
- python scripts/recheck_verified.py
- python scripts/measure_progress.py

Registri autorevoli: verification/local-byte-exact.tsv e verification/local-linked-byte-exact.tsv. Non sovrascriverli con gli script storici. I file compilati MW e le prove sono inclusi; il compilatore non è incluso.

Ricerca: verify_multiple_transfers.py per foglie e trasferimenti multipli; verify_draft_control_flow.py per bozze con condizioni/cicli; verify_resolved_calls.py per oggetti candidati con chiamate ARM. Conservare entrambi i registri quando si estendono gli script: non ricontare o modificare funzioni già verificate. Alcuni script storici conoscono solo il primo registro e richiedono adattamento prima di riutilizzarli.

Prossimi obiettivi: prologhi/stack e salti delle foglie; varianti di compilazione per funzioni più grandi; relocazioni Thumb/interworking mediante un linker verificato. Non usare stub, rimuovere argomenti o mascherare byte. La verifica locale non certifica firme, linking globale o comportamento in gioco.

Ricerca del checkpoint 9: verify_arm_flow_all.py, verify_large_drafts.py e verify_linked_variants.py. Il resolver supporta Thumb BL con controllo indipendente Capstone. Conservare entrambi i registri; non ricontare funzioni già verificate.

## Checkpoint 10 — Clang ARM flow

1.160 funzioni; 27.568 byte (1,440578%). Nuove prove: `verification/clang-arm-flow-recheck.json`. Ricompilare con `python scripts/recheck_clang_arm_flow.py` e misurare con `python scripts/measure_progress.py`. La ricerca `verify_clang_arm_flow.py` salva il registro dopo ogni match; non eseguirla insieme ad altri script che scrivono i registri. I nuovi record `clang_arm_control_flow` usano Clang, non MW. Le quattro prove in `clang-leafs/results.json` sono state ricompilate sul sorgente corrente e riconfermate: gli hash precedenti sono conservati nel campo `historical_source_sha256`. `python scripts/recheck_clang_matching.py` passa su tutte e quattro.

Ricerca aggiuntiva: 604 candidati ARM flow estesi e 275 candidati con trasferimenti multipli, nessun ulteriore match. Il tool `verify_clang_multiple_transfers.py` conserva i registri e salva dopo ogni match. Il recheck ARM flow riconosce anche questi eventuali futuri record e la modalita Thumb.

## Checkpoint 11

1.174 funzioni, 28.104 byte (1,468587%). Usare `audit_current_unrelocated.py` invece dello storico `audit_local_matching.py` quando ci sono prove Clang. Sono richiesti MKDS_BASELINE, WIBO e MWCCARM. Ricerca estesa: `verify_mw_extended_flow.py`; bozze C: `verify_mw_all_drafts.py`. Non eseguire due ricerche che scrivono i registri contemporaneamente. Il target 10% richiede 191.368 byte totali verificati; non e ancora raggiunto.

Ripristino del compilatore: `python scripts/setup_matching_toolchain.py` scarica strumenti con hash fissati in `tools/` (ignorata da Git). Il compilatore proprietario non e incluso nel repository. Nuova ricerca Thumb: `verify_mw_thumb_flow.py`. La pubblicazione del checkpoint 11 e nel ramo `codex/byte-matching-checkpoint-11`, PR #1; main resta al checkpoint 10 fino al merge autorizzato.

## Checkpoint 12

1.222 funzioni e 29.070 byte (1,519066%). Thumb flow: 122 candidati, 48 match, 966 byte. Tutte le 1.060 prove senza relocazioni sono state ricompilate dopo la ricerca; le 162 con relocazioni sono state ricompilate al checkpoint 11. Le 6.802 bozze C non hanno dato nuovi match con sei ottimizzazioni: evitare di ripetere quella ricerca senza cambiare la ricostruzione. Il prossimo lavoro deve migliorare le funzioni grandi (tipi, parametri, stack e flusso), non ricontare funzioni o variare il denominatore. Il 10% dei byte richiede ancora 162.298 byte verificati.

## Checkpoint 13 — lavoro verso il 10%

1.663 funzioni; 62.902 byte (3,286972%). Tutte le prove ricompilate con i compilatori dichiarati. Nuovi strumenti: `verify_mw_literal_drafts.py`, `verify_mw_cfg_flow.py`; resolver ARM BLX aggiornato sia nella ricerca sia nel recheck, con destinazione disassemblata e confrontata indipendentemente. Prossime ricerche: `verify_mw_stack_args.py`, `verify_mw_stack_locals.py`, `verify_mw_transfer_flow.py`. Un solo writer dei registri alla volta. Non ricontare funzioni gia registrate. Il target resta 191.368 byte, senza cambiare denominatore.

## Checkpoint 14

2.288 funzioni; 109.144 / 1.913.676 byte inventariati (5,703369%). Tutte le prove ricompilate. Gli span completi verificati sono 109.304 byte: `proof_span.py` verifica le differenze di literal pool/ritorno condiviso senza aggiungerle al numeratore. Le dipendenze SDK sono fissate in `sdk-header-manifest.json`, i sorgenti e flag in `sdk-source-proofs.json`, gli indirizzi dati osservati in `sdk-extra-symbols.tsv`. SDK ASM non importato. Prossima ricerca: `verify_mw_sdk_caller_drafts.py`, con arita/prototipi SDK osservati nei sorgenti appena verificati; nessun argomento inventato. Un solo writer dei registri alla volta. Stato remoto: ramo codex/matching-toward-10-percent, PR #2. Main resta al checkpoint 12 finche la nuova PR non e approvata.

## Blocco ambiente dopo il checkpoint 14

L'ambiente di esecuzione si e disconnesso: exec-server ha restituito `409 Conflict, environment_offline: Environment is not connected`. Il checkpoint 14 resta il risultato durevole e ricompilato: 2.288 funzioni, 109.144 byte inventariati (5,703369%). Il 10% richiede 191.368 byte: ne mancano 82.224.

`verify_mw_sdk_caller_drafts.py` ha terminato una ricerca su 5.688 candidati con un ulteriore match locale, non ricontrollato e non incluso nel checkpoint pubblicato. Un'esplorazione di sorgenti C/C++ da tangosdev/sm64ds-decomp era in corso quando l'ambiente e caduto; nessun risultato di quell'esperimento e incluso nel matching pubblicato. Ricreare un ambiente, ripristinare binari di riferimento e toolchain, ricompilare i registri pubblicati, quindi proseguire con le funzioni grandi e i sorgenti SDK. Non dichiarare raggiunto il target 10%.

## Checkpoint 15 — main

2.289 funzioni; 109.220 / 1.913.676 byte inventariati (5,707340%). Nuova prova CreateCESex_from_thumb, 76 byte e due relocazioni Thumb/ARM; compilazione Clang ARM indipendente riuscita. Ricompilate tutte le 1.038 prove con relocazioni dopo la nuova aggiunta. Le 1.251 prove senza relocazioni erano state ricompilate nella stessa sessione. Proseguire con nuove ricostruzioni di funzioni grandi; non ripetere la ricerca sdk_caller senza modifiche, perche ha prodotto un solo match su 5.688 candidati. Mancano 82.148 byte per raggiungere almeno il 10% dell'inventario.

## Checkpoint 16 — main

2379 funzioni; 126160 / 1.913.676 byte inventariati (6.592548%). +90 funzioni e +16.940 byte inventariati (17.004 byte negli span completi). Tutte le 1270 prove senza relocazioni e le 1109 con relocazioni ricompilate.
Nuovi strumenti: prepare_donor_candidates.py per C puro di sm64ds-decomp; prepare_sdk_variants.py per SDK pokediamond (rimozione documentata di main.h non pertinente, senza stub). Passare MKDS_DONOR_CONFIG al verificatore SDK. I candidati con ASM sono esclusi; gli hash dei nuovi header sono nel manifest SDK. I percorsi include delle funzioni installate devono puntare agli header fissati, evitando types.h omonimi nelle cartelle del gioco. ROM completa e ABI globale non verificati.

## Checkpoint 17 — main

2.454 funzioni; 135.620 / 1.913.676 byte inventariati (7,086884%); 135.940 byte negli span completi. Tutte le 1.278 prove senza relocazioni e le 1.176 con relocazioni sono state ricompilate; 3.133 relocazioni risolte. +75 funzioni dalla ricerca ricorsiva sm64ds-decomp, +9.460 byte inventariati. Le 75 nuove funzioni compilano anche con Clang ARM. Mancano 55.748 byte per raggiungere almeno il 10%.

Ricerca eseguita su 1.912 sorgenti C, 11.472 varianti compilate: evitare di ripeterla senza modifiche. Provenienza e hash sono nel ledger SDK. Prossimo lavoro: nuove famiglie di librerie DS o ricostruzioni delle funzioni grandi del gioco. Un solo writer dei registri alla volta; lavorare su main. ROM completa, ABI globale e comportamento del gioco restano non verificati.

## Checkpoint 18 — main

2.706 funzioni; 171.580 / 1.913.676 byte inventariati (8,965990%); 171.900 byte negli span completi. Ricompilate tutte le 1.331 prove senza relocazioni e le 1.375 con relocazioni; 3.802 relocazioni risolte. +252 funzioni e +35.960 byte. Mancano 19.788 byte per raggiungere almeno il 10%.

Nuova ricerca: prepare_nitro_candidates.py per ntrtwl/NitroSDK e ntrtwl/NitroSystem. Oggetti di ricerca possono contenere primitive ASM, ma i relativi corpi non vengono importati; anche i file completi contenenti ASM vengono esclusi. L'header CLZ inline contiene ora soltanto una dichiarazione esterna. Nessuna implementazione finta viene fornita e le 252 prove sono state ricompilate dopo questa modifica. La dipendenza standard C in vendor/nitro-stdinc fornisce dichiarazioni, non implementazioni. SDK e header restano fissati tramite hash e commit.

In questo ambiente le dipendenze Python sono state installate in tools/pythondeps (ignorata da Git). Impostare PYTHONPATH a quella directory per i verificatori; se manca, installare capstone==5.0.9, pyelftools==0.33, ziglang==0.14.1 e ndspy==4.2.0. Prossime ricerche: varianti di compilazione o altre versioni compatibili delle librerie; non ripetere le stesse ricerche senza modifiche. Un solo writer dei registri alla volta. ROM completa e ABI globale non verificati.

## Checkpoint 19 — main

3.111 funzioni; 216.832 / 1.913.676 byte inventariati (11,330654%); 219.236 byte negli span completi. Target locale 10% raggiunto. +405 funzioni ARM7, +45.252 byte inventariati e +47.336 byte negli span. Ricompilate tutte le 1.396 prove senza relocazioni e le 1.715 con relocazioni; 5.015 relocazioni risolte.

discover_arm7_modes.py ricostruisce ARM/Thumb da ingresso noto, allineamento e prologhi che escludono Thumb1 su ARM7TDMI, propagando flussi originali e indirizzi costanti. Evidenza riproducibile per 910 delle 982 funzioni indicizzate; zero conflitti. Le altre 72 restano escluse dal supplemento. supplemental_symbols.py verifica hash dei binari e dei corpi originali; non cambia il denominatore o i simboli baseline. Un nome veneer duplicato conserva il primo indirizzo noto e il secondo viene escluso, senza inventare binding.

Ricerca NitroSDK ARM7: 49 match dal primo inventario supplementare, 194 dal supplemento esteso, 162 dai file C completi. Esclusi corpi e file completi con assembly. Estensioni degli span ammesse soltanto da proof_span.py, senza contare i byte extra nel numeratore. Controllo ISA di tutte le 405 nuove prove: 1.003 branch relocations, zero BLX non supportati. La ricerca NitroSystem ARM9 auto-inline ha dato zero nuovi match: non ripeterla senza modifiche. Proseguire con altre varianti e funzioni del gioco; lavorare esclusivamente su main. ROM completa e ABI globale non verificati.

## Checkpoint 20 — main

3.113 funzioni; 216.924 / 1.913.676 byte inventariati (11,335461%); 219.328 byte negli span completi. +2 funzioni ARM7 e +92 byte: OS_Terminate (20), CARDi_SendtoPxi (72). Ricompilate tutte le 1.396 prove senza relocazioni e le 1.717 con relocazioni; 5.019 relocazioni risolte. Entrambi i nuovi corpi usano soltanto istruzioni ARMv4T compatibili. ROM completa e ABI globale non verificati.

Ricerca conclusa: NitroSDK ARM7 O1/O3 (isolata e unita completa), NitroSDK ARM9 O1/O3 (isolata e unita completa), NitroSDK ARM7 auto-inline O4,p/O4,s/O2 (isolata e unita completa), NitroSystem ARM9 O1/O3 (isolata e unita completa). 164 ricostruzioni ricompilate, 2 accettate; 1.932 varianti di file compilate, 1.486 oggetti prodotti. Non ripetere queste ricerche senza modifiche. Comandi: prepare_nitro_candidates.py con --optimization=-O1 --optimization=-O3 oppure --cpu arm7 --inline on,auto; verify_sdk_sources.py con MKDS_DONOR_CONFIG, extend_literal_spans per ARM7 e complete_translation_unit per le seconde fasi. Provenienza, flag e hash dei match sono nel ledger SDK; risultati in checkpoint20-search-summary.json.

Il verificatore audit_resolved_calls.py ora ricompila su quattro worker, carica una sola volta i metadati e segnala ogni 100 funzioni. Gli oggetti di audit sono separati dalle prove archiviate, in build/linked-audit-objects; ciascuna compilazione mantiene il timeout di 30 secondi. prepare_nitro_candidates.py crea anche la cartella build nei cloni puliti. Lavorare esclusivamente su main; un solo writer dei registri.

I due nuovi hex di codice restano locali e ignorati da Git. hash-only-proofs.json conserva hash e collegamento al checkpoint ricompilato; measure_progress.py confronta comunque i byte della ROM fornita, mentre export_objdiff_report.py accetta solo record hash-only espliciti, con span uguale al corpo inventariato, hash del sorgente e audit completo. Testato anche senza i due hex; hash alterato respinto.

## Checkpoint 21 — main

3.115 funzioni, 216.982 / 1.913.676 byte inventariati (11,338492%). Due ricostruzioni manuali Thumb: func_02006380 (28 byte), func_02006fdc (30 byte). Ricompilate 1.398 prove senza relocazioni e 1.717 con relocazioni (5.019 risolte). Prove nuove hash-only nel checkpoint21-search-summary.json. Ricerca stack_locals: 126 candidati, zero match; non ripeterla senza modifiche.

Soluzione emulator: core melonDS al commit 906e9ebb27da8c6a715cd7abab4abfe8a8d29427, senza Qt/SDL/JIT/OpenGL. build_headless_emulator.sh + melonds_headless.cpp; 900 frame original/hybrid arrivano al titolo con buffer finali identici. Tracce CPU campionate diverse: non dichiarare equivalenza completa. GDB osservato realmente su ARM9/ARM7, entry 02000800/02380000, detach OK. Observe_gdb.py legge soltanto stato/registri e si scollega. Rete, periferiche e salvataggi non persistiti.

build_hybrid_rom.py inserisce gli oggetti dell'audit in sezioni originali, rilegge la ROM e verifica che tutti i moduli decompressi restino identici. Non e una build indipendente dal C. compare_rom.py copre ogni byte fisico e non maschera padding/header; il confronto ibrido e non identico: 25.562.152 contro 33.554.432 byte, 8.082.864 diversi o mancanti. Dettagli in reports/FULL-ROM-COMPARISON.md e JSON completo. Sorgenti non matching, linking globale e contenitore esatto restano da ricostruire. Lavorare su main; un solo writer dei registri.

## Checkpoint 23 — main, corpus disponibile

3.117 funzioni, 217.166 / 1.913.676 byte (11,348107%). Due query gara
ricostruite dai byte ARM: GetDriverPlace, 116 byte; GetCurrentLapCount, 68.
Bitfield char/short per la posizione, slot signed e override giri signed.
1.400 prove senza relocazioni ricompilate; 1.717 con 5.019 relocazioni.
197.888 casi ARM originale/C host con risultati e letture RAM identici.
Timeline scripts/inputs/grand-prix.tsv: menu, Mario, B Dasher, Mushroom Cup,
Figure-8 Circuit; accelerazione scriptata. Nessuna equivalenza completa.
I sorgenti del checkpoint 22 citati nel report di recupero non sono accessibili;
non sommare quelle metriche al corpus corrente.
REA 6.5.0 + Ghidra 12.1.4 + JDK21 installati in tools/; controllo ownership
bloccato dal disallineamento tra PID Node e /proc dell'ambiente. Non disabilitare
il controllo o simulare ps. Raw ARM REA seleziona inoltre ARMv7, non ARMv5T.

## Checkpoint 24 recuperato — 14 ottobre

3.768 funzioni, 286.846 / 1.913.676 byte (14,989267%). +651 funzioni,
+69.680 byte inventariati e +69.800 negli span. 1.409 e 2.359 prove ricompilate,
7.342 relocazioni risolte. Quattro pool estesi: 120 byte extra non conteggiati.
Corpus nuovamente ricostruito da ai-tdd-labs/mkds-decomp c6e18fa4b346643b74c402b605a84b43cba16c01,
non dedotto dai riepiloghi dei precedenti checkpoint perduti. Script
prepare_mkds_candidates.py; config build/mkds-candidates/config.json; verificatore
verify_sdk_sources.py con MKDS_SDK_DONOR e MKDS_DONOR_CONFIG. Un solo writer.
Prove hash-only in checkpoint24-search-summary.json con span_checks espliciti.
Le nuove prove hex restano ignorate; non pubblicarle. Il pseudocodice Ghidra e
le osservazioni runtime estese delle sessioni interrotte non sono stati recuperati
come corpus di artefatti: restano distinti dal matching riprodotto qui.

## Checkpoint 25 — 15 ottobre 2026

3.772 funzioni, 287.242 / 1.913.676 byte (15,009960%). Quattro ricostruzioni C
pendenti recuperate e ricompilate: +396 byte. Tutte le 1.409 prove senza relocazioni
e 2.363 con relocazioni ricompilate, 7.356 relocazioni. Nessuna nuova analisi Ghidra.
Hash-only checkpoint25-search-summary.json; report CHECKPOINT-25.md.
REA resta bloccato: PID e /proc incoerenti; unshare user/PID rifiutato su uid_map.
Runtime REA e installazione Ghidra/JDK21 precedenti assenti dal ripristino.
GDB funziona avviando core e osservatore nello stesso subprocess: nuovo
run_gdb_observation.py, ARM9/ARM7 entry osservate e detach OK. Non supporre che
connessioni localhost tra comandi separati funzionino. Input missions/time-trials/battle
eseguiti 3600 frame ciascuno; Grand Prix 7200 e navigazione 2400. Osservazioni ROM
originale in RUNTIME-2026-10-15.json, nessuna gara/missione completata o intero gioco
esplorato. Proseguire con vere nuove ricostruzioni, VS/menu restanti e missioni ulteriori.
