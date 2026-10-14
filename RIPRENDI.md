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
