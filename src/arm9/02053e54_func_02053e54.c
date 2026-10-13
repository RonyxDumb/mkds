/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_02053e54(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa00u) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x400u))) + 84));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x400u))) + 84) = (unsigned short)(((load_1)&~(0x8u)));
    return ((load_0)+(0x400u));
}
