/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetMaybeNetErrorCode(void)
{
    return ((0x0u)-(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d384u) + 0)))+(0x1000u))) + 3912))));
}
