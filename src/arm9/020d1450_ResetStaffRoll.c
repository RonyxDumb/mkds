/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int ResetStaffRoll(void)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(0x217b4acu) + 0) = (unsigned int)(0x0u);
    return 0x217b4acu;
}
