/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void Mem_SetWramcnt(unsigned int p0)
{
    *(unsigned char *)((unsigned char *)(unsigned int)(0x4000247u) + 0) = (unsigned char)(p0);
}
