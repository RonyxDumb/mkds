/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Wm_GetGlobal(void)
{
    return ((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217eed4u) + 0));
}
