/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_02134508(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 36) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 28)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 40) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 32)));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 40) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 40)))-(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 24)))&(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 44)))))));
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 52) = (unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 24)));
}
