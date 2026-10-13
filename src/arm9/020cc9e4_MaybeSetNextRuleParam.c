/* High-level reconstruction. Exact local bytes verified with mwccarm 1.2/sp2p3.
 * No relocations. Full ROM linking remains unverified. */
void MaybeSetNextRuleParam(unsigned int p0)
{
    *(unsigned short *)((unsigned char *)(unsigned int)(((((unsigned int)*(const unsigned int *)((unsigned char *)(unsigned int)(0x21759c0u) + 0)))+(0x300u))) + 216) = (unsigned short)(p0);
}
