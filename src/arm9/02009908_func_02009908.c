/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_02009908(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x216fc38u) + 0) = (unsigned int)(p0);
    *(unsigned int *)((unsigned char *)(unsigned int)(0x216fc34u) + 0) = (unsigned int)(p1);
    return 0x216fc34u;
}
