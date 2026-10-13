/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetRacePaletteBlock(unsigned int p0)
{
    return ((((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b3c4u) + 0)))+(0x7dcu)))+(((p0) << 4)));
}
