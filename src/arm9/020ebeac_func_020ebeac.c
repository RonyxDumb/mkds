/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_020ebeac(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))|(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x21594d8u) + 0)))));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))|(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x21594dcu) + 0)))));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))|(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x21594e0u) + 0)))));
}
