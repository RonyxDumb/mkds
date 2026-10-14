# Checkpoint 23: query gara e gameplay

Corpus disponibile: **3.117 funzioni, 217.166 / 1.913.676 byte (11,348107%)**.
Incremento verificato: due funzioni, 184 byte. Il corpus mancante del
checkpoint 22 non e incluso.

| Funzione | Indirizzo ARM9 | Byte locali completi |
|---|---|---:|
| GetDriverPlace | 0x0203c8dc | 116 |
| GetCurrentLapCount | 0x02044618 | 68 |

Ricostruzione da istruzioni originali: campi posizione a 7/4 bit, mapping signed,
override giri signed e fallback da impostazioni. MW 1.2/sp2p3 O4,p produce gli
stessi byte e la stessa lunghezza, zero relocazioni, nessuna maschera.
Audit completo: 1.400/1.400 senza relocazioni, 1.717/1.717 con 5.019 relocazioni
risolte. Confronto C host/ARM originale: 197.888 casi, risultati e letture RAM
identici. Prove hash-only senza distribuire nuovi dump ROM.

Il frontend melonDS accetta input TSV validati, stilo, capture periodiche e
letture grezze RAM. Otto casi validi/invalidi passati. Originale e ibrido hanno
terminato 7.200 frame ciascuno, raggiungendo Figure-8 Circuit. Il kart accelera
fino alla barriera; gara non completata. Tre delle dodici coppie di snapshot
sono identiche; in gara timer, avversari e buffer differiscono. La causa non e
stata stabilita. Non si dichiara equivalenza completa.

REA 6.5.0/Ghidra 12.1.4/JDK21 tentati realmente. Il controllo dei processi
fallisce per disallineamento dei PID con /proc; nessun output decompilato REA
ottenuto e nessun controllo ownership disabilitato. Il profilo raw ARMv7 non
certifica le ISA DS. Dettagli in docs/DYNAMIC-ANALYSIS.md e nei JSON verification.

L'ibrido mantiene tutti i moduli decompressi identici. La ROM fisica conserva
8.082.864 byte diversi o mancanti; non e una build autonoma dai sorgenti.
