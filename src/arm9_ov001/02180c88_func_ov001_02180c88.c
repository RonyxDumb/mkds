/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void func_ov001_02180c88(unsigned int p0)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(0x1000u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(0x1000u);
}
