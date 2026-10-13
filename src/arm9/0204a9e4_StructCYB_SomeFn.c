/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void StructCYB_SomeFn(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned short)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 6) = (unsigned short)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(0x0u);
}
