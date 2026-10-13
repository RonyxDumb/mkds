/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int OS_IsTickAvailable(void)
{
    return ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x217024cu) + 0));
}
