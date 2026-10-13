/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_02089ecc(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned short)(0xau);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(0xcu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned short)(0x7fffu);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(0x1u);
}
