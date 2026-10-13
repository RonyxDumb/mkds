/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetBootIndicatorPointer_1(void)
{
    return 0x27ffc40u;
}
