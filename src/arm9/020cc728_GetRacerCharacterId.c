/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetRacerCharacterId(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cc728: r2 = 0x21759c0u;
L_20cc72c: r1 = 0x30u;
L_20cc730: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20cc734: r1 = (r0*r1+r2);
L_20cc738: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 104));
L_20cc73c: return r0;
}
