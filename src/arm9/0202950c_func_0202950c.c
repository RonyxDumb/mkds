/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_0202950c(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x2174e1cu) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(((load_0)+(((0x18u)*(p0))))) + 12) = (unsigned int)(p1);
    return ((load_0)+(((0x18u)*(p0))));
}
