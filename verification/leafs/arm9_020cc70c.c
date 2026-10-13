
unsigned int GetRacerKartId(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20cc70c: r2 = 0x21759c0u;
L_20cc710: r1 = 0x30u;
L_20cc714: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20cc718: r1 = (r0*r1+r2);
L_20cc71c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 108));
L_20cc720: return r0;
}
