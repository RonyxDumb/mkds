# Checkpoint 25 — 15 ottobre 2026

**3.772 funzioni; 287.242 / 1.913.676 byte inventariati: 15,009960%.**
Incremento dal checkpoint 24: quattro funzioni, 396 byte, 0,020693 punti
percentuali. Sono ricostruzioni C pendenti recuperate dal workspace, non nuovo
pseudocodice prodotto da REA. Denominatore invariato; ROM completa non verificata.

Le quattro prove sono `func_02083a24` (188 byte), `Scene_Logo_UpdateImpl` (72),
`Logo_StateHandler_NotifyWiFiHelp_First` (72), `LogThrowAssertion` (64).
Ricompilate tutte le 1.409 prove senza relocazioni e le 2.363 con relocazioni:
3.772/3.772 riuscite, 7.356 relocazioni risolte. Esportazione objdiff e treemap
rigenerate. Le 8.589 funzioni marcate compilabili derivano dall'inventario dei
controlli esistenti: non sono una nuova compilazione globale di tutti i sorgenti.

## Emulatore e debugger

ROM di riferimento, core melonDS fissato a
`906e9ebb27da8c6a715cd7abab4abfe8a8d29427`:

| Sequenza | Frame | Evidenza osservata |
|---|---:|---|
| Gran Premio | 7.200 | Sequenza già disponibile rieseguita, stato gara `mode_raw=0` |
| Navigazione | 2.400 | Menu iniziale, dialogo emblema, selezione modalità e kart |
| Missioni | 3.600 | Ingresso missione, conto alla rovescia e gioco, `mode_raw=4` |
| Prove a tempo | 3.600 | Selezione Figure-8 Circuit e gioco, `mode_raw=1` |
| Battaglia | 3.600 | Balloon Battle in arena lunare, `mode_raw=2` |

Le sequenze non completano gare/missioni e non esplorano ogni circuito, boss,
missione, menu, oggetto o multiplayer. Non verificano il comportamento della
build ibrida. Registri campionati e hash framebuffer sono in
`RUNTIME-2026-10-15.json`; input ripetibili in `scripts/inputs/`.

Le connessioni GDB lanciate da comandi separati sono state rifiutate. Il lancio
con emulatore e osservatore nello stesso ambiente subprocess riesce su entrambe
le CPU: ARM9 PC `0x02000800`, ARM7 PC `0x02380000`; distacco `OK` per entrambe.
La causa precisa dell'isolamento dei comandi separati non è dimostrata. Il metodo
riuscito è riproducibile con:

```sh
python scripts/run_gdb_observation.py /percorso/AMCP.nds
```

## REA/Ghidra: blocco ancora presente

Riprovato `check_analysis_host.py`: PID runtime e `/proc/self/status` differenti;
`ps` può anche fallire con `fatal library error, lookup self`. Tentata una nuova
namespace user/PID con `/proc` coerente: `unshare` rifiutato su `uid_map` con
`Operation not permitted`. Nessun controllo di proprietà disattivato.

Il runtime compilato REA e le sue dipendenze Node non sono presenti nel workspace
ripristinato; non trovata l'installazione Ghidra/JDK21 precedente (Java17 presente).
Non dichiarare collegato REA, né attribuire a Ghidra nuove esportazioni. Serve un
ambiente con namespace PID e `/proc` coerenti per riprovare l'integrazione; il
debugger ora utilizzabile resta un risultato distinto dalla decompilazione.
