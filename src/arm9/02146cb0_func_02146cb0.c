/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_02146cb0(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(p2);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(((0x0u)-(p1)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(p2);
}
