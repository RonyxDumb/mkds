/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_01ffb9cc(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 608) = (unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 608)))+(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 200)))));
}
