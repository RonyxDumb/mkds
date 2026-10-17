/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void *GetPortraitNceNcgr_from_thumb(int);
extern void *GetPortraitNceNcer_from_thumb(int);
extern void *GetPortraitPalette_from_thumb(int);
extern void *GetPortraitBNCL_from_thumb(int);
void LoadPlayerGfxData_from_thumb(int player,void **out){out[0]=GetPortraitNceNcgr_from_thumb(player);out[2]=GetPortraitNceNcer_from_thumb(player);out[1]=GetPortraitPalette_from_thumb(player);out[3]=GetPortraitBNCL_from_thumb(player);}