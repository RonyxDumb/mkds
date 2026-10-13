/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int ResetGlobalE8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c6f84: r0 = 0x21759c0u;
L_20c6f88: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c6f8c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20c6f90: cmp_a = r0; cmp_b = 0x1u;
L_20c6f94: if ((cmp_a == cmp_b)) { r0 = 0x217b3f4u; }
L_20c6f98: if ((cmp_a == cmp_b)) { r1 = 0x0u; }
L_20c6f9c: if ((cmp_a == cmp_b)) { *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1; }
L_20c6fa0: return r0;
}
