/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020f9880(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f9880: r1 = 0x217bc34u;
L_20f9884: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 68));
L_20f9888: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20f988c: r0 = 0xa8u;
L_20f9890: r0 = (r2*r0+r1);
L_20f9894: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 132));
L_20f9898: return r0;
}
