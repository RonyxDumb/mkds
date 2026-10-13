/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Sound_SetFileFatDynamicOffsetField(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217dec4u) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(load_0) + 132));
    *(unsigned int *)((unsigned char *)(unsigned int)(((load_1)+(((p0) << 4)))) + 20) = (unsigned int)(p1);
    return ((load_1)+(((p0) << 4)));
}
