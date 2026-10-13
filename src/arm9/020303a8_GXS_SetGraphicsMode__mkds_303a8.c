/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GXS_SetGraphicsMode__mkds_303a8(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(0x4001000u) + 0) = (unsigned int)(((((load_0)&~(0x1f00u)))|(((p0) << 8))));
    return ((((load_0)&~(0x1f00u)))|(((p0) << 8)));
}
