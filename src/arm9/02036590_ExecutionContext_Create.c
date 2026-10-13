/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void ExecutionContext_Create(unsigned int p0, unsigned int p1)
{
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 0) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 4) = (unsigned int)(p1);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 8) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 16) = (unsigned int)(0x0u);
    *(unsigned int *)((unsigned char *)(unsigned int)(p0) + 12) = (unsigned int)(0x0u);
}
