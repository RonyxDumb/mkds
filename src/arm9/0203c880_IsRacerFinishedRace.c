/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int IsRacerFinishedRace(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203c880: r2 = 0x217561cu;
L_203c884: r1 = 0x8cu;
L_203c888: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_203c88c: r3 = 0x0u;
L_203c890: r1 = (r0*r1+r2);
L_203c894: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 20));
L_203c898: cmp_a = r0; cmp_b = 0x1u;
L_203c89c: if ((cmp_a == cmp_b)) { goto L_203c8b0; }
L_203c8a0: cmp_a = r0; cmp_b = 0x2u;
L_203c8a4: if ((cmp_a == cmp_b)) { goto L_203c8b0; }
L_203c8a8: cmp_a = r0; cmp_b = 0x3u;
L_203c8ac: if ((cmp_a != cmp_b)) { goto L_203c8b4; }
L_203c8b0: r3 = 0x1u;
L_203c8b4: r0 = r3;
L_203c8b8: return r0;
}
