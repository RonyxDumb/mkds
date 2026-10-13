/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Mem_SetExpHeapGroupId(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(((p0)+(0x24u))) + 16));
    *(unsigned short *)((unsigned char *)(unsigned int)(((p0)+(0x24u))) + 16) = (unsigned short)(p1);
    return load_0;
}
