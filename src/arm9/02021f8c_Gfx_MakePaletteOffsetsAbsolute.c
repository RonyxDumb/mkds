/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void Gfx_MakePaletteOffsetsAbsolute(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 12)))+(p0)));
}
