/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int ResetGlobalB358(void)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x217b358u) + 0) = (unsigned int)(0x0u);
    return 0x217b358u;
}
