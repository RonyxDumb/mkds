/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void Gfx_ReadCharGraphicsV2(void *,void *);
extern void Gfx_ReadPalette(void *,void *);
extern void MaybeReadScreenBlock_0(void *,void *);
void func_02025884(int *out,int characters,int palette,int screen,int layer,void *(*load)(int)){if(characters)Gfx_ReadCharGraphicsV2(out+layer,load(characters));if(palette)Gfx_ReadPalette(out+4,load(palette));if(screen)MaybeReadScreenBlock_0(out+5+layer,load(screen));}