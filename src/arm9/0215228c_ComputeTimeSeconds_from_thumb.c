/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int ComputeTimeSeconds_from_thumb(unsigned int p0)
{
    return ((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 8)))+(((0x3cu)*(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 4)))+(((0x3cu)*(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0))))))))));
}
