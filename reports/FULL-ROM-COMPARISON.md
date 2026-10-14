# Confronto completo con la ROM — checkpoint 21

Il confronto fisico include tutti i **33.554.432 byte** della ROM di riferimento
AMCP, SHA-1 `ce97d9b43f0d3ca0d48b781983e8a16f6393378f`: nessuna maschera per
header, relocazioni, dati o padding. La ROM candidata e un **ibrido**, costruito
inserendo gli oggetti compilati nelle sezioni derivate dall'originale.
Codice non ricostruito, dati e asset sono ancora quelli originali.

| Verifica | Risultato |
|---|---|
| Ricompilazione locale dei sorgenti | 3.115 / 3.115 funzioni passate |
| Relocazioni risolte e confrontate | 5.019 |
| Copertura dell'inventario funzioni | 216.982 / 1.913.676 byte, 11,338492% |
| Tutte le sezioni inizializzate ARM9, ARM7 e overlay decompressi dell'ibrido | Identiche all'originale, indirizzi compresi |
| Confronto fisico dell'intero `.nds` ibrido | Non identico |
| Originale e ibrido eseguiti nel core melonDS | 900 frame ciascuno, schermata del titolo osservata |
| Buffer finali dei due schermi | Identici tra originale e ibrido |
| Tracce CPU campionate | Non identiche; nessuna equivalenza completa dichiarata |
| Build completa dal C senza codice originale | Non disponibile e non verificata |

La candidata contiene **25.562.152 byte**. Nel confronto agli stessi offset,
**25.471.568 byte sono uguali**; **8.082.864 byte sono diversi o mancanti**.
Di questi, 7.992.280 sono la coda assente e 90.584 differiscono nell'estensione
comune. I moduli decompressi uguali non implicano compressione fisica uguale.

| Regione fisica dell'originale | Byte | Diversi o mancanti nell'ibrido |
|---|---:|---:|
| Header | 16.384 | 7 |
| ARM9 | 947.484 | 1 |
| ARM7 | 166.308 | 0 |
| Tabelle overlay ARM9 | 128 | 0 |
| File overlay | 350.564 | 88.966 |
| Tabella nomi | 11.934 | 0 |
| FAT | 4.880 | 0 |
| Banner | 2.112 | 0 |
| Altri file del filesystem | 23.893.292 | 0 |
| Padding e intervalli non classificati | 8.161.346 | 7.993.890 |

Il controllo separato che risalva l'originale senza inserire codice ricompilato
produce gia un file piu corto e 7.993.897 byte diversi o mancanti. Questo
controllo isola i cambiamenti di ricomposizione; non e una prova di decompilazione.
Il rapporto [JSON completo](full-rom-comparison.json) copre 1.168 intervalli
fisici, con hash, dimensioni e conteggi delle differenze. Provenienza e risultati
dinamici sono in `verification/checkpoint21-integration.json`.

## Riprodurre

Installare le dipendenze Python, fornire la propria ROM e ripristinare la
toolchain tramite `scripts/setup_matching_toolchain.py`. Impostare `MKDS_BASELINE`,
`WIBO` e `MWCCARM` come indicato da quello script, quindi:

```sh
python scripts/prepare_rom.py /percorso/AMCP.nds
python scripts/audit_current_unrelocated.py
python scripts/audit_resolved_calls.py
python scripts/build_hybrid_rom.py /percorso/AMCP.nds
python scripts/compare_rom.py /percorso/AMCP.nds build/hybrid/hybrid.nds --provenance hybrid
python scripts/test_compare_rom.py
```

Il comparatore restituisce codice 1 quando i file differiscono, 0 quando sono
identici e 2 per errore di input. Anche un file identico non viene automaticamente
certificato come ricostruzione indipendente dal C. L'ibrido e i binari di
riferimento restano locali e ignorati da Git.

Per arrivare a un matching completo servono ancora i sorgenti mancanti,
il linking globale con sezioni e ABI originali, i dati non ancora separati,
il formato/compressore originali e una ricomposizione che conservi ogni byte
del contenitore. Non viene dichiarato il 100% sulla base di asset copiati.
