/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02025eb0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2025eb0: r1 = (r0 << 2); cmp_a = r1; cmp_b = 0;
L_2025eb2: r0 = 0x21532a8u;
L_2025eb4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + r1)));
L_2025eb6: return r0;
}
