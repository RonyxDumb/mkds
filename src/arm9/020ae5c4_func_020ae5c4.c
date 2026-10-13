/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_020ae5c4(unsigned int p0)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((p0)+(0x402u))) + 0));
    *(unsigned short *)((unsigned char *)(unsigned int)(((p0)+(0x402u))) + 0) = (unsigned short)(((load_0)+(0x1u)));
    return load_0;
}
