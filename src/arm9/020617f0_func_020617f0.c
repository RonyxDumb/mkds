/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020617f0(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa54u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 52) = (unsigned int)(0x1u);
    return load_0;
}
