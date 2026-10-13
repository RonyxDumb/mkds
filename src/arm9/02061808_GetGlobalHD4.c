/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetGlobalHD4(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa6cu) + 0));
}
