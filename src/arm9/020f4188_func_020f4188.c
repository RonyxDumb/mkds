/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_020f4188(unsigned int p0, unsigned int p1)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 18) = (unsigned short)(((((unsigned int)*(const short *)((unsigned char *)(unsigned int)(p0) + 16)))-(p1)));
}
