/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_02013bcc(unsigned int p0, unsigned int p1)
{
    return ((((p0)+(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 8)))))+(((p1) << 4)));
}
