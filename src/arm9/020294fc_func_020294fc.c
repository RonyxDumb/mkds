/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020294fc(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x2174e1cu) + 0))) + 0 + (((0x18u)*(p0)))) = (unsigned int)(p1);
    return ((0x18u)*(p0));
}
