/* C reconstructed from reference ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
void *BTA0_LoadRawData(void *base, unsigned index)
{
    unsigned offset=*(unsigned short *)((char *)base+14);
    char *dictionary=(char *)base+8;
    unsigned stride=*(unsigned short *)(dictionary+offset);
    char *entry=dictionary+offset+stride*index;
    return (char *)base+*(unsigned *)(entry+4);
}
