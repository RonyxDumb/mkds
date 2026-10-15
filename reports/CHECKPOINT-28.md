# Checkpoint 28 — accessori risorse 3D e menu

**3.811 funzioni; 289.370 / 1.913.676 byte inventariati: 15,121159%.**
Dal checkpoint 27: **22 funzioni, 1.308 byte**, +0,068350 punti percentuali.
Denominatore invariato; copertura locale dell'inventario, non matching della ROM intera.

| Gruppo ARM9 | Funzioni | Byte |
|---|---:|---:|
| Accesso per indice a dati JNT0/BMA0/BTA0/BTP0/BVA0 | 5 | 160 |
| Lettura di campi dei materiali | 4 | 204 |
| Modifica di bit/campi dei materiali | 11 | 784 |
| Selezione menu opzioni e aggiornamento emblema | 2 | 160 |

Le risorse usano offset relativi e tabelle con stride memorizzato nei dati.
I nuovi C conservano le letture a 16/32 bit, le maschere e gli shift originali,
compreso il comportamento dei setter per valori con bit fuori dal campo.
I nomi preesistenti sono mantenuti: non vengono presentati come identificazioni
semantiche nuove e certe.

I due near miss del checkpoint precedente ora coincidono: la forma `switch`
permette di riprodurre disposizione dei rami e degli epiloghi del compilatore.
`GetCurrentOptionMenuKind_from_thumb` usa `-O4,s`; `Scene_Emblem_Update` usa
`-O4,p`. Non sono stati aggiunti assembly, byte opachi o stub ai sorgenti del gioco.
Il binding della query overlay a `0x021a23c8` è provato dalla BLX originale a
`0x0204a5a0`, verificabile con `scripts/verify_menu_symbols.py`.

Verifiche semantiche aggiuntive:

- **40.960 casi** per gli accessori risorse: istruzioni ARM originali in Unicorn
  contro gli attuali C compilati per host, confrontando risultati e tutti i
  4.096 byte del buffer dopo ogni chiamata. Fixture allineate con otto entry;
  non è una validazione dei file corrotti o di indici arbitrari.
- **1.275 casi** per menu ed emblema: risultati, ordine delle chiamate e buffer
  emblema completi. I risultati dei soli callees esterni sono controllati da
  fixture; non si tratta di un'esecuzione del gioco completo.

Audit e prove hash-only in `verification/checkpoint28-search-summary.json`.
I test sono riproducibili con `scripts/test_resource_semantics.py` e
`scripts/test_menu_helper_semantics.py` (Unicorn e gcc).

Ricerca di copie identiche delle venti nuove funzioni nell'inventario restante:
zero nuovi candidati. Le prime ricostruzioni dei dizionari per nome a
`0x02013754` e `0x020138b4` non coincidono e restano escluse. Nessuna nuova
esplorazione runtime o esportazione REA in questo checkpoint. Linking globale,
ABI e matching dell'intera ROM rimangono non verificati.

Ricompilate tutte le 1.441 prove senza relocazioni e le 2.370 con relocazioni:
3.811/3.811 passate, 7.379 relocazioni risolte. Span completi 291.894 byte;
i 2.524 byte extra storici restano esclusi dal numeratore.
