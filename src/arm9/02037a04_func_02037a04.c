/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_02037a04(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x21755a0u) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned char *)((unsigned char *)(unsigned int)(load_0) + 216));
    *(unsigned char *)((unsigned char *)(unsigned int)(load_0) + 216) = (unsigned char)(((load_1)&~(0x1u)));
    return ((load_1)&~(0x1u));
}
