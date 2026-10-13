/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetB488_B5(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b488u) + 0))) + 16));
}
