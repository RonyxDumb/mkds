/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void StructTEQ_Initialize(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 10) = (unsigned short)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned short)(((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 10)));
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned short)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned int)(0x0u);
}
