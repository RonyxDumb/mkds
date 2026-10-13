/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020a10ac(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b1fcu) + 0));
    unsigned int load_1 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x50u))) + 0 + (((p0)*(0x70u)))));
    *(unsigned short *)((unsigned char *)(unsigned int)(((load_0)+(0x50u))) + 0 + (((p0)*(0x70u)))) = (unsigned short)(((load_1)+(p1)));
    return ((load_1)+(p1));
}
