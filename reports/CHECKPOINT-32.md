# Checkpoint 32 — helper Thumb, comandi e liste

**3.848 funzioni, 293.278 / 1.913.676 byte: 15,325374%.**
Incremento: 11 funzioni, 752 byte, 0,039296 punti percentuali.
Copertura locale dell’inventario; ROM completa e ABI globale non verificati.

| Indirizzo | Byte |
|---|---:|
| 0x020068f4 | 32 |
| 0x02006914 | 22 |
| 0x02006954 | 30 |
| 0x02006c2c | 272 |
| 0x02006d3c | 60 |
| 0x02006d78 | 54 |
| 0x02006db0 | 44 |
| 0x02006ddc | 26 |
| 0x02006df8 | 122 |
| 0x02006f14 | 58 |
| 0x02007014 | 32 |

Ricostruiti i parametri delle chiamate Thumb, la conversione del risultato a
16 bit, i layout dei pacchetti stack e la rimozione di un nodo dalla lista
con ripristino dello stato IRQ. Il dispatcher da 272 byte conserva l’ordine
delle prove, il cursore circolare e il percorso di fallback. I nomi restano
quelli dell’inventario; la corrispondenza locale non certifica tutti i chiamanti.

Tutte le nuove funzioni coincidono in lunghezza e in ogni byte dopo risoluzione
di 33 relocazioni. L’accettazione ricompila e confronta con due resolver
indipendenti. Audit mirati: verification/checkpoint32-*-audit.json.
Nessuna nuova osservazione REA, sessione di gameplay o prova semantica aggiunta.

Ripresa riproducibile: python scripts/search_thumb_command_family.py, poi
python scripts/accept_batch_matches.py build/family32.json --audit-name NOME_NUOVO.json.
I candidati senza match restano esclusi e le prove già registrate non sono ricontate.

Mancano 51.184 byte inventariati verificati per raggiungere il 18%.

Audit globale fresco completato: **1.454/1.454** prove senza relocazioni e
**2.394/2.394** con relocazioni, **7.477 relocazioni** risolte.
Tutte le 3.848 funzioni ricompilate sul corpus attuale; zero differenze.
I 20 test di regressione batch/cache e hash-only sono passati.
Misura, treemap e report objdiff rigenerati con esito positivo.
