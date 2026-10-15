# Checkpoint 26 — menu e funzioni Wi-Fi

**3.777 funzioni; 287.494 / 1.913.676 byte inventariati: 15,023128%.**
Dal checkpoint 25: **5 funzioni, 252 byte**, +0,013168 punti percentuali.
Il denominatore rimane invariato. È copertura locale dei corpi funzione
identificati, non matching della ROM intera.

| Funzione ARM9 | Byte | Codice | Ottimizzazione |
|---|---:|---|---|
| `Logo_StateHandler_CheckWiFiStatus_Second` | 88 | ARM | `-O4,p` |
| `Scene_Emblem_Initialize` | 40 | ARM | `-O4,p` |
| `FormatCharacterEmblemName` | 48 | ARM | `-O4,p` |
| `GetMaybeSomeWifiIdx` | 36 | ARM | `-O4,p` |
| `ClearRaceOptionMenuEntries_from_thumb` | 40 | Thumb | `-O4,s` |

Ricompilate tutte le prove della sessione: 1.411 senza relocazioni, 2.366 con
relocazioni, 7.364 relocazioni risolte. Le versioni finali dei cinque sorgenti
sono state ricompilate individualmente dopo la formattazione e l'ultima aggiunta.
Ogni byte viene confrontato: nessuna relocazione mascherata. Prove hash-only in
`checkpoint26-search-summary.json`; quattro nuovi binding sono controllati
indipendentemente da `scripts/verify_menu_symbols.py` contro literal e BLX originali.

REA/Ghidra ha prodotto quattro nuove esportazioni in `reports/rea/menus/`,
inclusa una funzione Wi-Fi di 1.076 byte. Il relativo pseudocodice non è contato
nel matching se non esiste una ricostruzione compilata e verificata. Queste
esportazioni usano ancora il profilo raw ARM generico di REA; non dimostrano
un profilo DS ARMv5T/Thumb completo o un collegamento live tra emulatore e Ghidra.

L'esplorazione dei menu è documentata separatamente nel
[report con schermate](MENU-EXPLORATION-2026-10-15.md). Sono state eseguite copie
della ROM di riferimento, non una build indipendente del progetto C.
Linking globale, ABI tra tutte le funzioni ed equivalenza della ROM completa
rimangono non verificati.
