# REA/Ghidra: correzione verificata — 15 ottobre 2026

Il collegamento CLI REA 6.5.0 → Ghidra 12.1.4 ha restituito pseudocodice
per la funzione ARM di Mario Kart DS a `0x02083a24` (188 byte di riferimento).
Evidenza completa: [02083a24-evidence.json](rea/02083a24-evidence.json).
Il matching resta 15,009960%: questo lavoro ripara gli strumenti e non aggiunge
prove di byte matching.

## Due cause e due correzioni

1. Il runtime usa il PID della namespace interna, mentre `/proc` espone PID
   esterni. La nuova implementazione legge `NSpid`/`NSpgid` e usa `pidfd_open`
   più `/proc/self/fdinfo` per verificare la corrispondenza kernel tra PID interno
   e processo esterno. Non basta scegliere l'ultimo numero di `NSpid`: processi
   di namespace sorelle possono avere lo stesso numero. Token di proprietà,
   identità start-time, controlli contro il riutilizzo dei PID e verifiche prima
   dei segnali restano attivi. Le letture non verificabili falliscono.
2. Dopo la correzione PID, Ghidra completava l'analisi ma Java riceveva
   `SocketException: Operation not permitted` creando il socket Unix del ponte.
   Un'opzione locale esplicita seleziona il trasporto REA già esistente
   `authenticated-loopback-tcp`, con autenticazione e sessione in sola lettura.

La patch è locale, non una release ufficiale o una correzione approvata dai
maintainer REA. Le altre letture dirette di `/proc` usate da capture/debugger
non sono state convertite: non dichiarare compatibilità generale di tutte le
funzioni REA in namespace disallineate. Il percorso verificato è il provider
Ghidra per analisi statica tramite CLI.

## Verifiche eseguite

- Build TypeScript/runtime riuscita con Node 24.19.0.
- 29 test dei processi passati, inclusi due test Linux con processi reali;
  token errato rifiutato e regressioni di identità/ownership passate.
- 72 test del comportamento provider Ghidra passati.
- Discovery: 1.299 file test scoperti esattamente una volta.
- Chiamata reale REA `decompile` riuscita con Ghidra 12.1.4 e Temurin JDK21.
  La prova JSON identifica il provider, hash del target e profilo analitico.

Il test usa il profilo raw ARM generico `ARM:LE:32:v7` attualmente fornito da REA.
Non verifica un profilo ARMv5T completo per DS, Thumb, overlay, simboli globali,
né il collegamento live dell'emulatore a Ghidra. La funzione è stata estratta
dalla ROM di riferimento, non ricompilata dal C per questa prova.

## Ripristino riproducibile

REA sorgente fissato al commit `fffb0741936067530d1ce9777461cd53e87398c2`.
Richiede Linux con `pidfd_open`, Python3, Node compatibile, Ghidra e JDK21.
La patch non cambia configurazione MCP o software di sistema.

```sh
git clone https://github.com/morluto/rea.git tools/rea-source
git -C tools/rea-source checkout --detach fffb0741936067530d1ce9777461cd53e87398c2
python scripts/rea/apply_fix.py
```

Nel checkout REA eseguire `npm ci` e `npm run build:cached`. Il file
`scripts/rea/pid-namespace.patch` include anche il helper Python nel manifest
del pacchetto. L'installer controlla il commit e l'applicabilità; è idempotente.

Ghidra usato: archivio ufficiale
`ghidra_12.1.4_PUBLIC_20260921.zip`, estratto in `tools/ghidra_12.1.4_PUBLIC`.
JDK usato: Temurin `21.0.12.1+1`, in `tools/jdk21/jdk-21.0.12.1+1`.
Il launcher accetta percorsi alternativi mediante `GHIDRA_INSTALL_DIR` e
`JAVA_HOME`. Gli archivi, i runtime e i byte della ROM non vengono pubblicati.

```sh
sh scripts/rea/run.sh decompile /percorso/funzione-arm.bin 0x02083a24 \
  --provider ghidra --target-format raw-binary --architecture arm \
  --entry-point 0x02083a24 --format json
```

La funzione di esempio inizia al byte zero del file ed è caricata a
`0x02083a24`; non passare questo indirizzo base a un intero modulo ARM9.
La prova è solo di analisi statica: eseguire il gioco e osservare GDB rimangono
operazioni separate.

## Aggiornamento checkpoint 30

La patch locale ora include profili DS, modalità ARM/Thumb attestata e controllo
PID degli inferior debugger. Vedere [CHECKPOINT-30.md](CHECKPOINT-30.md) per prove,
comandi e limiti attuali. Ricostruire REA dopo aver applicato la nuova patch.
