/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Int32ToInt8(unsigned int p0)
{
    return ((p0)&(0xffu));
}
