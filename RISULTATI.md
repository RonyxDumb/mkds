# Stato attuale — checkpoint 8

1.024 funzioni e 21.978 byte verificati localmente contro le sezioni originali. Incremento rispetto al checkpoint 7: 248 funzioni, 8.836 byte (+67,23%). Copertura ponderata: 1,1485% di 1.913.676 byte inventariati; per numero: 8,5064% di 12.038 funzioni.

| Metodo | Funzioni | Byte |
|---|---:|---:|
| Byte identici senza relocazioni | 937 | 17.362 |
| Byte identici dopo risoluzione di tutte le relocazioni | 87 | 4.616 |

Nel secondo gruppo vengono applicate 161 relocazioni ARM PC24/ABS32 usando gli indirizzi dei simboli originali, gli addend ELF e l’indirizzo originale di ogni funzione. Il risultato completo deve coincidere; nessun byte viene ignorato. Simboli ambigui, relocazioni non supportate e interworking di chiamate vengono esclusi. Prove, oggetti e valori applicati sono in verification/resolved-calls/.

Le 1.024 sorgenti salvate sono state ricompilate con MW: entrambi gli audit passano. Clang ARM946E-S/ARM7TDMI: 1.024 successi. Hash delle 776 sorgenti precedenti inalterati.

Compilabilità generale invariata: 7.598; 4.440 falliti. Il controllo completo risale al checkpoint 6; questa sessione verifica il sottoinsieme matching. Linking della ROM intera, ABI dei chiamanti e gioco in emulatore restano non verificati. Il denominatore Ghidra può contenere sovrapposizioni, dati e identificazioni errate.
