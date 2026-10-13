/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void SetB488SinglePlayerMenuTarget(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217b488u) + 0))) + 8) = (unsigned int)(p0);
}
