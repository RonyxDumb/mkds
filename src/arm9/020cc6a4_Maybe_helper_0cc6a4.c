/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int Maybe_helper_0cc6a4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cc6a4: r2 = 0x21759c0u;
L_20cc6a8: r1 = 0x30u;
L_20cc6ac: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20cc6b0: r1 = (r0*r1+r2);
L_20cc6b4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 120));
L_20cc6b8: return r0;
}
