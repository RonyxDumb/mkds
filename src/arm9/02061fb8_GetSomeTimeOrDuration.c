/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetSomeTimeOrDuration(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aa54u) + 0))) + 4));
}
