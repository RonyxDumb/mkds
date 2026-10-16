# Famiglia: selezione personaggi

Blocco controller fissato: **12/23 funzioni** con matching locale, **2500/7084 byte inventariati**.

Il sottogruppo di navigazione è completo: **6/6**, cinque griglie e dispatcher. Il menu intero non è completo. Le dipendenze UI/SDK condivise restano esterne al perimetro; i nomi descrittivi sono inferenze dai riferimenti statici.

Le griglie sono selezionate dal numero di personaggi visibili (8–12). Le quattro destinazioni signed corrispondono ai mask 0x40, 0x80, 0x10, 0x20; -1 impedisce il movimento. Il campo +0x64 è il cursore precedente, non un codice tasto.

| Indirizzo | Ruolo | Byte inventariati | Matching locale |
|---|---|---:|---|
| 0x02025f90 | Controllo risorse grafiche | 200 | Aperto |
| 0x02026058 | Configurazione blending/display | 140 | Aperto |
| 0x020260e4 | Uscita e distruzione heap | 60 | Verificato |
| 0x02026120 | Controller principale: input e fasi | 1914 | Aperto |
| 0x02026910 | Inizializzazione menu | 1702 | Aperto |
| 0x02027084 | Aggiornamento parametri delle icone | 76 | Aperto |
| 0x020270d0 | Controllo blocco interazione | 44 | Verificato |
| 0x020270fc | Dispatcher griglia e cambio selezione | 124 | Verificato |
| 0x02027188 | Dispatcher aggiornamento icone | 18 | Verificato |
| 0x0202719c | Evidenziazione icona | 76 | Aperto |
| 0x020271e8 | Aggiornamento celle selezionate | 52 | Aperto |
| 0x0202721c | Aggiornamento grafica associata | 112 | Aperto |
| 0x0202728c | Aggiornamento parametro grafico | 52 | Verificato |
| 0x020272c0 | Aggiornamento coordinate grafiche | 44 | Verificato |
| 0x020272ec | Rimozione evidenziazione | 96 | Aperto |
| 0x0202734c | Visibilità icone | 116 | Aperto |
| 0x020273c0 | Avvio transizione di uscita | 100 | Aperto |
| 0x02027424 | Inoltro azione condizionale | 36 | Verificato |
| 0x02027448 | Griglia con 12 personaggi | 434 | Verificato |
| 0x02027648 | Griglia con 11 personaggi | 444 | Verificato |
| 0x02027850 | Griglia con 10 personaggi | 446 | Verificato |
| 0x02027a58 | Griglia con 9 personaggi | 332 | Verificato |
| 0x02027be0 | Griglia con 8 personaggi | 466 | Verificato |

Prove: `checkpoint35-character-select-audit.json`, `checkpoint35-navigation-semantics.json`. 2.240 confronti C host/Thumb originale sui buffer completi e sulle chiamate ordinate. Il dispatcher esegue le cinque griglie reali; quattro dipendenze grafiche/animazioni sono fixture controllate su entrambi i lati. Non è equivalenza del menu in gioco.

Prossimo lavoro nella stessa famiglia: 0202719c/020271e8/0202721c e visibilità icone; poi inizializzatore 02026910 e controller input/fasi 02026120. Non cambiare perimetro per migliorare la percentuale.
