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

## Limiti REA verificati il 14 ottobre 2026

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
  Nessuna sessione runtime o connessione GDB e stata verificata qui.

Misura rieseguita contro la ROM corretta: 3.113 funzioni, 216.924 byte su
1.913.676 (11,335461%). Nessun nuovo match e attribuito a questa preparazione.
Non modificare i registri di matching sulla base di hit o pseudocodice REA.

Fonti: [REA](https://github.com/morluto/rea),
[modalita raw](https://github.com/morluto/rea/blob/cbc0e97c29b8dcb3d6ff96eb3af9e0f519a22345/docs/raw-binary.md),
[melonDS](https://github.com/melonDS-emu/melonDS/releases/tag/1.1).
