/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_020d6538(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 92) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p1) + 0)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 100) = (unsigned int)(((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p1) + 4)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 104) = (unsigned int)(((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p1) + 6)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 108) = (unsigned int)(((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p1) + 8)));
}
