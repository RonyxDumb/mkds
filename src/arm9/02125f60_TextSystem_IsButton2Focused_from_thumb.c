/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int TextSystem_IsButton2Focused_from_thumb(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d3f0u) + 0))) + 44));
}
