# Checkpoint 24 recuperato e ricompilato

**3.768 funzioni, 286.846 / 1.913.676 byte: 14,989267% dell'inventario.**
+651 funzioni e +69.680 byte rispetto al checkpoint 23: +3,641160 punti.
Non e matching dell'intera ROM.

Dopo la perdita del workspace sono stati ricompilati 1.551 candidati C dal
commit c6e18fa4b346643b74c402b605a84b43cba16c01 di ai-tdd-labs/mkds-decomp.
651 match accettati dopo risoluzione completa delle relocazioni e confronto
integrale dei byte e delle lunghezze. Nessun dato e stato ricostruito dai soli
riepiloghi. ASM, include e array inizializzati opachi sono esclusi. Licenza e
commenti del donor preservati; nessun gap object, ROM, BIOS o asset importato.

Audit indipendente completo: 1.409/1.409 senza relocazioni, 2.359/2.359 con
7.342 relocazioni risolte. Span compilati 289.370 byte. Quattro nuove prove
hanno 120 byte di pool oltre l'inventario: controllati da proof_span e non
conteggiati. Hash-only con controlli espliciti, senza nuovi dump di codice.
Report objdiff e treemap rigenerati sul denominatore invariato.

Le sessioni precedenti avevano eseguito Ghidra e testato piu modalita, ma i
relativi nuovi artefatti sono stati persi nell'azzeramento e non sono inclusi
nella verifica riprodotta. I test e i limiti pubblicati del checkpoint 23
restano disponibili. Non si dichiara copertura completa del gameplay.
REA resta soggetto ai limiti di process ownership descritti nei documenti.
Il linking globale, l'ABI e una build autonoma completa della ROM non sono
verificati. La compilabilita complessiva non e stata rimisurata qui.
