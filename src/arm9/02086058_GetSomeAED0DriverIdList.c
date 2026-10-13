/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetSomeAED0DriverIdList(void)
{
    return ((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217aed0u) + 0)))+(0x94u));
}
