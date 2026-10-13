/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Nsbmd_GetMDL0Block(unsigned int p0)
{
    return ((p0)+(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0 + (((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 12)))))));
}
