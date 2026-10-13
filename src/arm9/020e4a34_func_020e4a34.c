/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_020e4a34(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))|(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x2158fe8u) + 0)))));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))|(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x2158fecu) + 0)))));
}
