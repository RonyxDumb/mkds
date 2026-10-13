/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void TextSystem_SetUseDirectInput_from_thumb(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d3f0u) + 0))) + 0 + (0x2248u)) = (unsigned int)(p0);
}
