/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_02051640(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa00u) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 16) = (unsigned int)(0x0u);
    return load_0;
}
