/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int MaybeGetItemByIndex(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ed578: r1 = 0x217bbfcu;
L_20ed57c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + (0 + (r0 << 2))));
L_20ed580: return r0;
}
