
unsigned int GetRacerType(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ae15c: r2 = 0x21759c0u;
L_20ae160: r1 = 0x30u;
L_20ae164: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20ae168: r1 = (r0*r1+r2);
L_20ae16c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 112));
L_20ae170: return r0;
}
