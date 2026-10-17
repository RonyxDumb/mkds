/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void MaybeReadCharBlock_1(void *,void *);
extern void Gfx_ReadPaletteRelative(void *,void *);
extern void MaybeReadScreenBlock(void *,void *);
void func_02025904(int *out,int characters,int palette,int screen,int layer,void *(*load)(int)){if(characters)MaybeReadCharBlock_1(out+layer,load(characters));if(palette)Gfx_ReadPaletteRelative(out+4,load(palette));if(screen)MaybeReadScreenBlock(out+5+layer,load(screen));}