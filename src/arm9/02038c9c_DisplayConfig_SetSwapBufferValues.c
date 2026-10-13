/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int DisplayConfig_SetSwapBufferValues(unsigned int p0, unsigned int p1, unsigned int p2)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 108));
    *(unsigned char *)((unsigned char *)(unsigned int)(load_0) + 2) = (unsigned char)(p1);
    unsigned int load_2 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 108));
    *(unsigned char *)((unsigned char *)(unsigned int)(load_2) + 3) = (unsigned char)(p2);
    return load_2;
}
