/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
unsigned int FriendCode_GetFlags_from_thumb(unsigned int p0)
{
    return ((((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(p0) + 0))) >> 11))&(0x1fffffu));
}
