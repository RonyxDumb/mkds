/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int StructTEQ_GetNextFreeTEQSub(unsigned int p0)
{
    return ((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0)))+(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 10))) << 4)));
}
