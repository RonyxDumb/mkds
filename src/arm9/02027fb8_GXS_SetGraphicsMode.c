/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GXS_SetGraphicsMode(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0) = (unsigned int)(((((load_0)&~(0xe000u)))|(((p0) << 13))));
    return ((((load_0)&~(0xe000u)))|(((p0) << 13)));
}
