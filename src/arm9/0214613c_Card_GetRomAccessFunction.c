/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Card_GetRomAccessFunction(void)
{
    return 0x21463a4u;
}
