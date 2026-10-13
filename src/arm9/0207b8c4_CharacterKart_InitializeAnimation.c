/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int CharacterKart_InitializeAnimation(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 36) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(((p0)+(0x24u))) + 20) = (unsigned int)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(((p0)+(0x24u))) + 24) = (unsigned short)(0x0u);
    return ((p0)+(0x24u));
}
