/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int SelectChoisesContext_InitializeBg_from_thumb(void)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(0x4001008u) + 0) = (unsigned short)(((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x4001008u) + 0)))&~(0x3u)));
    *(unsigned short *)((unsigned char *)(unsigned int)(0x4001008u) + 0) = (unsigned short)(((((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(0x4001008u) + 0)))&(0x43u)))|(0xb00u)));
    return 0xb00u;
}
