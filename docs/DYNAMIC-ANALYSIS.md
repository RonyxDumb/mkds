# Analisi dinamica DS e REA

Eseguire la ROM aiuta a osservare argomenti, registri, RAM, chiamate e overlay
caricati. Non recupera il sorgente originale e non dimostra il byte matching:
ogni ricostruzione deve ancora essere compilata e confrontata con la ROM.
Non tutta la logica viene eseguita durante una singola partita.

## Preparazione riproducibile

Dalla radice del repository, dopo aver installato `requirements.txt`:

```sh
python scripts/prepare_rom.py /percorso/AMCP.nds
python scripts/prepare_dynamic_analysis.py /percorso/AMCP.nds
python scripts/prepare_dynamic_analysis.py /percorso/AMCP.nds --cpu arm7 --output build/dynamic-arm7
```

Il primo comando controlla lo SHA-1 e ripristina le sezioni inizializzate senza
cambiare l'inventario. Il nuovo script registra indirizzi, ISA dichiarata,
dimensioni e hash delle sezioni locali e seleziona le 30 funzioni piu grandi
senza prova locale per la CPU scelta. Gli hash sono osservazioni dei file
estratti, non una prova di ricompilazione. Gli output sono in `build/`, ignorata
da Git; non contengono byte di codice della ROM.

In melonDS usare una build con GDB stub, avvio diretto DS e JIT disabilitato.
Abilitare il debugger, le porte ARM9 3333 e ARM7 3334 e lo stop iniziale.
Aprire la ROM, quindi collegare ogni CPU separatamente:

```sh
gdb-multiarch -x build/dynamic-analysis/arm9.gdb
gdb-multiarch -x build/dynamic-arm7/arm7.gdb
```

I comandi osservano lo stato fermo e non avviano automaticamente una traccia.
Scegliere un indirizzo in `targets.json`, mettere un solo breakpoint e riprendere.
Al punto di arresto registrare r0-r3, sp, lr, pc, cpsr, scenario e versione
dell'emulatore. Il bit T del CPSR distingue ARM da Thumb. Per assegnare un
indirizzo a un overlay bisogna verificare i byte caricati: diversi overlay
condividono lo stesso indirizzo. La lista iniziale esclude gli overlay proprio
per evitare di attribuire una chiamata al modulo sbagliato.

## Soluzione funzionante: core senza GUI

Il checkpoint 21 include `melonds_headless.cpp`, un frontend locale che esegue
il core melonDS al commit `906e9ebb27da8c6a715cd7abab4abfe8a8d29427` senza
Qt, SDL, OpenGL o JIT. Sono stati eseguiti 900 frame sia dell'originale sia
dell'ibrido: entrambi raggiungono il titolo, con buffer finali identici.
Questo non verifica l'intero gameplay. Le tracce CPU campionate non sono
identiche, quindi non viene dichiarata equivalenza completa del comportamento.

Su Linux, con Git, CMake e compilatore C++17:

```sh
sh scripts/build_headless_emulator.sh
tools/melonds-headless /percorso/AMCP.nds 900 build/reference
tools/melonds-headless build/hybrid/hybrid.nds 900 build/hybrid-run
```

Il frontend usa FreeBIOS e firmware generato upstream, RTC fissato al primo
gennaio 2026 e nessun input. Multiplayer, periferiche, microfono e persistenza
dei salvataggi sono disabilitati: non serve per verificarli. I buffer dei due
schermi sono salvati come byte grezzi, nel formato interno del core.

Per il debugger, avviare questo comando in un terminale:

```sh
tools/melonds-headless /percorso/AMCP.nds 900 build/debug --gdb
```

In un secondo terminale, osservare ARM9 e poi ARM7:

```sh
python scripts/observe_gdb.py --cpu arm9 --output build/arm9-observation.json
python scripts/observe_gdb.py --cpu arm7 --output build/arm7-observation.json
```

Entrambe le connessioni sono state testate realmente, con lettura dei registri
agli entry point `0x02000800` e `0x02380000` e detach `OK`. Lo script non espone
scritture di memoria o registri. E possibile usare GDB al posto dell'osservatore
per breakpoint e analisi mirata. Il frontend e distribuito come sorgente GPL;
il core resta una dipendenza upstream, non incluso nel repository.

## Limiti REA e precedenti tentativi

- Installato localmente `rea-agents@6.4.0`, versione CLI verificata.
- `rea doctor --json` segnala Ghidra/Hopper assenti; Java locale e 17.
- La CLI installata rifiuta `--architecture`. Un tentativo `rea inspect`
  sul binario ARM9 con provider Ghidra restituisce `target_unavailable`,
  motivo `unsupported binary format`.
- La documentazione del repository REA al commit
  `cbc0e97c29b8dcb3d6ff96eb3af9e0f519a22345` descrive invece una modalita
  raw-binary ARM con lingua Ghidra `ARM:LE:32:v7`. Non sostituire con questa
  il modello `ARM:LE:32:v5t` / `ARM:LE:32:v4t` del progetto. Serve verificare
  separatamente ISA, Thumb, sezioni, entry reale e overlay.
- melonDS 1.1 Linux scaricato. La build Ubuntu non parte per librerie Qt6,
  enet e faad mancanti. L'AppImage estratta risolve quelle librerie ma non
  include il plugin Qt offscreen; il tentativo termina prima dell'emulazione.
  Questo era il primo tentativo. Il blocco e stato superato compilando il core
  senza GUI, come descritto sopra. Il plugin Qt offscreen 6.2.4 e stato anche
  recuperato dalla wheel PySide6 della stessa versione, ma la soluzione
  riproducibile adottata non richiede Qt.

Misura checkpoint 21: 3.115 funzioni, 216.982 byte su
1.913.676 (11,338492%). I due nuovi match derivano da ricostruzioni C Thumb
ricompilate, non dalle osservazioni dinamiche.
Non modificare i registri di matching sulla base di hit o pseudocodice REA.

Fonti: [REA](https://github.com/morluto/rea),
[modalita raw](https://github.com/morluto/rea/blob/cbc0e97c29b8dcb3d6ff96eb3af9e0f519a22345/docs/raw-binary.md),
[melonDS](https://github.com/melonDS-emu/melonDS/releases/tag/1.1).

## Checkpoint 23: gameplay riprodotto

Il frontend ora accetta `--inputs` e `--capture-every`. Ogni riga del TSV:
`first last pressed_mask touch_x touch_y`. Frame a base zero, intervallo
`[first,last)`; maschera dei pulsanti premuti (A=1, B=2, Start=8,
Right=16, Left=32, Up=64, Down=128, R=256, L=512, X=1024, Y=2048).
Usare `-1 -1` per rilasciare lo stilo; coordinate ammesse 0..255/0..191.
Gli intervalli devono essere ordinati e senza sovrapposizioni. Il limite
massimo e 36.000 frame. Intervalli, maschere e coordinate errati sono rifiutati.

```sh
tools/melonds-headless /percorso/AMCP.nds 7200 build/reference --inputs scripts/inputs/grand-prix.tsv --capture-every 600
tools/melonds-headless build/hybrid/hybrid.nds 7200 build/hybrid-run --inputs scripts/inputs/grand-prix.tsv --capture-every 600
```

Entrambe le esecuzioni realmente completate: menu, Mario/B Dasher, Mushroom
Cup, Figure-8 Circuit, kart mosso con A fino alla barriera. Gara non completata.
3/12 coppie di snapshot identiche; schermate in gara, timer, ordinamento degli
avversari e puntatori RAM differiscono. Nessuna equivalenza completa dimostrata.
I campioni di PC a fine frame non sono hit di breakpoint. I nuovi campi JSON
sono letture grezze delle query posizione/giri; puntatori dereferenziati solo
se compresi nella RAM principale. Framebuffer software BGRA, 256x192x4 byte.
Risultati e hash: `verification/gameplay-checkpoint23.json`.

REA 6.5.0 e stato eseguito con Ghidra 12.1.4/JDK 21.0.12.1+1. L'import raw
supera la precedente assenza del provider, ma il controllo ownership fallisce:
Node vede PID 5, `/proc/self` 2690; un figlio Python vede PID 13, `/proc/self`
2698. `ps` avviato da Node termina con `fatal library error, lookup self`.
Non sono stati disabilitati i controlli o inventati risultati. REA non ha
prodotto pseudocodice per questa sessione; evidenza in
`verification/rea-checkpoint23.json`. La lingua ARMv7 generica resta inoltre
inadatta a certificare il modello DS ARMv5T/ARMv4T.
