/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_0205a4b0(unsigned int p0, unsigned int p1)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 14) = (unsigned short)(0x0u);
    unsigned int load_1 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa14u) + 0));
    unsigned int load_2 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(load_1) + 1832));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned short)(0x2u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(((load_2)+(0x78u)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(0x13u);
}
