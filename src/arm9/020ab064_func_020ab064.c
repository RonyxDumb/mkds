/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020ab064(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ab064: r1 = 0x217b278u;
L_20ab066: *(unsigned int *)((unsigned char *)r1 + 76) = (unsigned int)r0;
L_20ab068: return r0;
}
