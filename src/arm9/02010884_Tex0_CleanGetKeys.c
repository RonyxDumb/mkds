/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void Tex0_CleanGetKeys(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 16)))&~(0x1u)));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 32) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 32)))&~(0x1u)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p1) + 0) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 8)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p2) + 0) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 24)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 24) = (unsigned int)(0x0u);
}
