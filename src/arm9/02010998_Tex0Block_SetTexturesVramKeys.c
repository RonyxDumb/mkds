/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void Tex0Block_SetTexturesVramKeys(unsigned int p0, unsigned int p1, unsigned int p2)
{
    if (((p1) != (0x0u))) *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(p1);
    if (((p2) != (0x0u))) *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 24) = (unsigned int)(p2);
}
