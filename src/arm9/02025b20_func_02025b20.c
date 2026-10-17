/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void Gfx_ReadCharGraphicsRelative(void *,void *);
extern void func_020b48b4(void *,void *);
extern void Gfx_ReadPaletteRelative(void *,void *);
void func_02025b20(int * out,int characters,int cells,int palette,int layout,int animation,int extra,void *(*load)(int)){
if(characters)Gfx_ReadCharGraphicsRelative(out,load(characters));
if(cells)func_020b48b4((char *)out+8,load(cells));
if(palette)Gfx_ReadPaletteRelative((char *)out+4,load(palette));
if(layout)*(void **)((char *)out+12)=load(layout);
if(animation)*(void **)((char *)out+20)=load(animation);
if(extra)*(void **)((char *)out+16)=load(extra);
}