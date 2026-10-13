/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void Tex0Block_SetPaletteVramKey(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 44) = (unsigned int)(p1);
}
