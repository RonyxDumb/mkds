/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int Maybe_helper_03c5ac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203c5ac: r2 = 0x217561cu;
L_203c5b0: r1 = 0x8cu;
L_203c5b4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_203c5b8: r1 = (r0*r1+r2);
L_203c5bc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 92));
L_203c5c0: return r0;
}
