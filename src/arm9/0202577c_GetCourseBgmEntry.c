/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetCourseBgmEntry(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_202577c: r1 = 0x215316cu;
L_2025780: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + (0 + (r0 << 2))));
L_2025784: return r0;
}
