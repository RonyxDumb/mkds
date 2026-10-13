/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_0201e394(unsigned int p0, unsigned int p1, unsigned int p2)
{
    unsigned int load_0 = ((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p0) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p2) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 0) = (unsigned int)(((load_1)+(load_0)));
    unsigned int load_3 = ((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p0) + 2));
    unsigned int load_4 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p2) + 4));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 4) = (unsigned int)(((load_4)+(load_3)));
    unsigned int load_6 = ((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p0) + 4));
    unsigned int load_7 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p2) + 8));
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 8) = (unsigned int)(((load_7)+(load_6)));
    return ((load_7)+(load_6));
}
