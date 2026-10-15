# Checkpoint 30 — REA per le CPU del Nintendo DS

**3.820 funzioni, 291.874 / 1.913.676 byte: 15,252007%.**
Aumento rispetto al checkpoint 29: una funzione, 52 byte, 0,002717 punti.
È copertura locale dell'inventario, non matching della ROM completa.

## Riparazioni verificate

- Profili locali espliciti `nds-arm9` → `ARM:LE:32:v5t` e `nds-arm7` →
  `ARM:LE:32:v4t`; il generico ARMv7 resta il default fuori da questi profili.
- Modalità di ingresso `arm`/`thumb`, impostata prima della disassembly.
  Lingua e modalità entrano nel profilo con digest; il ponte misura `TMode`
  e l'attestazione del caricamento rifiuta un contesto assente o diverso.
- Il controllo delle identità degli inferior debugger usa la stessa traduzione
  PID autenticata dal kernel già usata dall'ownership. Un processo ancora vivo
  non viene più scambiato per concluso leggendo il `/proc` della namespace errata.
- Launcher con diagnostica per Ghidra mancante; comando per funzione che ricava
  span e ISA dall'inventario, seleziona il modulo e controlla l'evidenza restituita.

Build Node 24.19.0 riuscita; **149 test passati**, inclusi ownership con processo
reale, inferior ancora vivo, attestazione ARM/Thumb e regressioni provider Ghidra.
Prove reali REA/Ghidra 12.1.4 con JDK21 in `reports/rea/`:

| Modulo | Indirizzo | Modalità | Span analizzato |
|---|---|---|---:|
| ARM9 | `0200104c` | ARM | 52 byte |
| Overlay ARM9 000 | `02180500` | Thumb | 52 byte |
| ARM7 | `02380000` | ARM | 284 byte |

Ulteriore prova ARM9 a `02083a24`: profilo ARMv5T e pseudocodice restituiti.
Le prove non lanciano la ROM né stabiliscono equivalenza dell'emulazione.

## Nuovo C verificato

`func_0200104c` imposta il campo a offset 4 a 2, azzera il campo a offset
`0x82` e cancella il bit 3 a offset `0x8b` nell'oggetto puntato da `0217aa00`.
Il nuovo pseudocodice ha eliminato le espressioni di rotazione del vecchio draft;
la ricostruzione usa un simbolo globale e accessi tipizzati.
MWCC 1.2/sp2p3 `-O4,p`: 52/52 byte identici, inclusa l'unica relocazione dati
risolta dal resolver esistente. Nessuna istruzione o byte mascherato.
Audit mirato fresco in `verification/rea-ds-matching-audit.json`; le prove
precedenti conservano i propri audit storici. Misura e report objdiff rigenerati.

## Riproduzione e limiti

`apply_fix.py` applica la patch locale ampliata al medesimo commit REA fissato;
poi ricostruire REA con `npm run build:cached`. Non è una release upstream REA.

```sh
python scripts/rea/decompile_mkds.py arm9 0x0200104c
python scripts/rea/decompile_mkds.py arm9_ov000 0x02180500
python scripts/rea/decompile_mkds.py arm7 0x02380000
```

Il comando estrae solo lo span dell'inventario, conserva hash della sezione e
funzione e salva evidenza e draft sotto `build/rea-mkds`. I riferimenti a dati,
pool e chiamanti esterni allo span possono essere incompleti. Gli overlay sono
analizzati separatamente; non esiste ancora un modello live completo della
memoria DS né caricamento automatico di tutti gli overlay in una sessione.
I percorsi capture/sampling che leggono direttamente `/proc` restano da
convertire e verificare: non è dimostrata compatibilità generale di tutte le
funzioni REA. Matching globale e ABI dei chiamanti restano non verificati.
