/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02025e28(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2025e28: r1 = (r0 << 2); cmp_a = r1; cmp_b = 0;
L_2025e2a: r0 = 0x215336cu;
L_2025e2c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + r1)));
L_2025e2e: return r0;
}
