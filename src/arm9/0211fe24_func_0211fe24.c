/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_0211fe24(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d384u) + 0));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x8u))) + 16) = (unsigned short)(0x1u);
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x8u))) + 18) = (unsigned short)(0x1u);
    return ((load_0)+(0x8u));
}
