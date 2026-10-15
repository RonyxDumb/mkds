/* C reconstructed from reference ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
unsigned func_02013344(void *base, unsigned index)
{
    char *block=(char *)base+*((unsigned *)base+2);
    unsigned offset=*(unsigned short *)(block+10);
    char *dictionary=block+4;
    unsigned stride=*(unsigned short *)(dictionary+offset);
    char *entry=dictionary+offset+stride*index;
    unsigned *material=(unsigned *)(block+*(unsigned *)(entry+4));
    return (material[3]&2031616u)>>16;
}
