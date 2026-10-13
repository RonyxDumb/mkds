/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int func_0212c668(unsigned int p0, unsigned int p1)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0));
    if (((load_0) != (0x0u))) *(unsigned char *)((unsigned char *)(unsigned int)(load_0) + 64) = (unsigned char)(p1);
    return load_0;
}
