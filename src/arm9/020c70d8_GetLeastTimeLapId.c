/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetLeastTimeLapId(void)
{
    return ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b3f4u) + 0))) + 20));
}
