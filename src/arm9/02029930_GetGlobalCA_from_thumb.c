/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetGlobalCA_from_thumb(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x2174e1cu) + 0));
}
