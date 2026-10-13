/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetRacerType_0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cc6f0: r2 = 0x21759c0u;
L_20cc6f4: r1 = 0x30u;
L_20cc6f8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20cc6fc: r1 = (r0*r1+r2);
L_20cc700: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 112));
L_20cc704: return r0;
}
