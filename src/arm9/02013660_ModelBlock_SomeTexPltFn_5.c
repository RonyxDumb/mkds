/* C reconstructed from reference ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
void ModelBlock_SomeTexPltFn_5(void *base, unsigned index, unsigned value)
{
    char *block=(char *)base+*((unsigned *)base+2);
    unsigned offset=*(unsigned short *)(block+10);
    char *dictionary=block+4;
    unsigned stride=*(unsigned short *)(dictionary+offset);
    char *entry=dictionary+offset+stride*index;
    unsigned *material=(unsigned *)(block+*(unsigned *)(entry+4));
    material[1]=(material[1] & ~0x7fff0000u) | (value<<16);
}
