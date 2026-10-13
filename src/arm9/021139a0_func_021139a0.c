/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_021139a0(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d348u) + 0));
    unsigned int load_1 = ((unsigned int)*(const short *)((unsigned char *)(unsigned int)(load_0) + 0 + (0x6au)));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x6au))) + 0) = (unsigned short)(((load_1)+(0x1u)));
    return ((load_1)+(0x1u));
}
