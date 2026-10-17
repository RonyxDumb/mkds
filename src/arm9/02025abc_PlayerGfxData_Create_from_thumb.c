/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void Gfx_ReadCharGraphics(void *,void *);
extern void LoadCellBankFrom(void *,void *);
extern void Gfx_ReadPalette(void *,void *);
void PlayerGfxData_Create_from_thumb(int * out,int characters,int cells,int palette,int layout,int animation,int extra,void *(*load)(int)){
if(characters)Gfx_ReadCharGraphics(out,load(characters));
if(cells)LoadCellBankFrom((char *)out+8,load(cells));
if(palette)Gfx_ReadPalette((char *)out+4,load(palette));
if(layout)*(void **)((char *)out+12)=load(layout);
if(animation)*(void **)((char *)out+20)=load(animation);
if(extra)*(void **)((char *)out+16)=load(extra);
}