/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int GetKeyboardContextNextSceneId_from_thumb(void)
{
    return ((unsigned int)*(const short *)((unsigned char *)(unsigned int)(((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x217d400u) + 0))) + 0 + (0x72u)));
}
