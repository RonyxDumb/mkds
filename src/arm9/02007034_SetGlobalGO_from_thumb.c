/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void SetGlobalGO_from_thumb(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x216f3d8u) + 0) = (unsigned int)(p0);
}
