/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_0210f208(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(p2);
    *(unsigned char *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned char)(0x28u);
    *(unsigned char *)((unsigned char *)(unsigned int)(p0) + 13) = (unsigned char)(0x50u);
    *(unsigned char *)((unsigned char *)(unsigned int)(p0) + 14) = (unsigned char)(0x7fu);
}
