/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020b1cdc(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b350u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(((load_0)+(((p0) << 2)))) + 2204) = (unsigned int)(p1);
    return ((load_0)+(((p0) << 2)));
}
