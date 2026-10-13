/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void DisplayConfig_SetBottomEngineObjVramModeBmp(unsigned int p0, unsigned int p1)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(p0) + 178) = (unsigned short)(p1);
}
