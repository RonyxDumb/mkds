/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Os_AllocateThreadId(void)
{
    unsigned int load_0 = ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x216ff4cu) + 0));
    *(unsigned int *)((unsigned char *)(unsigned int)(0x216ff4cu) + 0) = (unsigned int)(((load_0)+(0x1u)));
    return ((load_0)+(0x1u));
}
