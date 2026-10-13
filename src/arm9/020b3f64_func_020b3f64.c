/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020b3f64(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b35cu) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(load_0) + 4) = (unsigned int)(0x1u);
    return load_0;
}
