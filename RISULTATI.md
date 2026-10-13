# Stato attuale — checkpoint 9

1.143 funzioni e 27.044 byte verificati localmente: +119 funzioni e +5.066 byte rispetto al checkpoint 8. Copertura ponderata: 1,4132% di 1.913.676 byte inventariati. Compilabilità: 7.615/12.038; 4.423 da correggere.

| Metodo | Funzioni | Byte |
|---|---:|---:|
| Identici senza relocazioni | 984 | 19.274 |
| Identici dopo risoluzione completa delle relocazioni | 159 | 7.770 |

Sono risolte 272 relocazioni ARM PC24/ABS32 e Thumb PC22. Per Thumb BL, intervallo e allineamento sono verificati e la destinazione viene ricontrollata indipendentemente con Capstone. Chiamate interworking che richiedono veneer non verificati restano escluse.

La ricostruzione dei flussi ARM conserva confronti, salti interni e condizioni di zero dei cicli. Accettati solo risultati con lunghezza e sequenza di byte complete identiche all’originale, senza mascheramenti, stub o assembly inline. Le firme dei chiamanti restano da verificare: la coincidenza locale non certifica l’ABI globale.

Ricompilazione MW e confronto: 984/984 senza relocazioni e 159/159 con linking locale. Clang ARM: 1.143/1.143. Tutti i 1.024 hash dei sorgenti precedenti sono inalterati. 17 bozze precedentemente fallite sono ora compilabili grazie a ricostruzioni byte-exact. Il controllo generale usa la base completa del checkpoint 6 e i successivi controlli dei sorgenti matching modificati.

Nessun linking della ROM completa o avvio nel gioco verificato. L’inventario Ghidra può avere sovrapposizioni, dati nei corpi o identificazioni errate; questa percentuale non misura l’intera ROM.
