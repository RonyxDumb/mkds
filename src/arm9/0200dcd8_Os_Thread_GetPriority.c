/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Os_Thread_GetPriority(unsigned int p0)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 112));
}
