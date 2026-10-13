/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int abs(unsigned int p0)
{
    return ((((int)(p0)) < ((int)(0x0u))) ? (((0x0u)-(p0))) : (p0));
}
