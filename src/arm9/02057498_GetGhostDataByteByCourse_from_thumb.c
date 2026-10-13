/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetGhostDataByteByCourse_from_thumb(unsigned int p0, unsigned int p1)
{
    return ((p1)+(((((p0) << 21)) >> 24)));
}
