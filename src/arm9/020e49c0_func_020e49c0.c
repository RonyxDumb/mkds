/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_020e49c0(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 184)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 192)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(0x3199u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 24) = (unsigned int)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))&~(0x2u)));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))&~(0x8u)));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 102) = (unsigned short)(0x1fu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 2)))&~(0x1u)));
}
