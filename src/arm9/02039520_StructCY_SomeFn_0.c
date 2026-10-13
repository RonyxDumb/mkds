/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void StructCY_SomeFn_0(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned short)(p1);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 14) = (unsigned short)(p2);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned short)(p3);
}
