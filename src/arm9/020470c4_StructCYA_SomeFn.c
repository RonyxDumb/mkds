/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void StructCYA_SomeFn(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned short)(0xffffu);
    *(unsigned char *)((unsigned char *)(unsigned int)(p0) + 18) = (unsigned char)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned short)(0xffu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 2) = (unsigned short)(0xffu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned short)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 6) = (unsigned short)(0x3u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned short)(0xffu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 10) = (unsigned short)(0xffu);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned short)(0x0u);
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 14) = (unsigned short)(0x3u);
}
