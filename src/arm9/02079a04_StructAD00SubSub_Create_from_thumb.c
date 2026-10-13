/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void StructAD00SubSub_Create_from_thumb(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 20) = (unsigned int)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 24) = (unsigned short)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned short)(0x0u);
}
