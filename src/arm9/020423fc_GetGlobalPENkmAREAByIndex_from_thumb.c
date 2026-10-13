/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetGlobalPENkmAREAByIndex_from_thumb(unsigned int p0)
{
    return ((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x2175620u) + 0))) + 116)))+(((0x48u)*(p0))));
}
