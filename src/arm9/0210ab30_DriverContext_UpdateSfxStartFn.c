/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void DriverContext_UpdateSfxStartFn(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 44) = (unsigned int)(0x210ab40u);
}
