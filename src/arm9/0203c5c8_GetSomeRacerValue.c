/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetSomeRacerValue(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203c5c8: r2 = 0x217561cu;
L_203c5cc: r1 = 0x8cu;
L_203c5d0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_203c5d4: r1 = (r0*r1+r2);
L_203c5d8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 88));
L_203c5dc: return r0;
}
