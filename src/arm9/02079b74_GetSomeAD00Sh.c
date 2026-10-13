/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetSomeAD00Sh(void)
{
    return ((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217ad00u) + 0)))+(0x98u));
}
