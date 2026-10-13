/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int Sound_Context_GetMaybeSavedFrameHeapStateId(unsigned int p0)
{
    return ((((unsigned int)*(const unsigned short *)((unsigned char *)(unsigned int)(p0) + 12)))-(0x1u));
}
