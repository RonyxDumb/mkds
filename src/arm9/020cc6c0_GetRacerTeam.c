/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetRacerTeam(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cc6c0: r2 = 0x21759c0u;
L_20cc6c4: r1 = 0x30u;
L_20cc6c8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20cc6cc: r1 = (r0*r1+r2);
L_20cc6d0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 116));
L_20cc6d4: return r0;
}
