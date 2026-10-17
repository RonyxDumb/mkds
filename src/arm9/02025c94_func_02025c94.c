/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern short *func_0201ea30(void *,int);
void func_02025c94(int id,int x,int y,void *graphics){
    short *entry=func_0201ea30(graphics,id);
    entry[0]=(entry[0]&0xfffff000U)|(x&0xfff);
    entry[1]=(entry[1]&0xfffff000U)|(y&0xfff);
}
