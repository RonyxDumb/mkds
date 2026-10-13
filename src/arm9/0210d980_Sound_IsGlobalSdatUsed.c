/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Sound_IsGlobalSdatUsed(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d064u) + 0));
}
