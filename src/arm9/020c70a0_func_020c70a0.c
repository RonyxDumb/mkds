/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020c70a0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c70a0: r0 = 0x217b3f4u;
L_20c70a4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c70a8: cmp_a = r0; cmp_b = 0x0u;
L_20c70ac: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 220)); }
L_20c70b0: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20c70b4: return r0;
}
