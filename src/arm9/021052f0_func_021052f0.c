/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_021052f0(unsigned int p0, unsigned int p1, unsigned int p2)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 256) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 260) = (unsigned int)(p2);
}
