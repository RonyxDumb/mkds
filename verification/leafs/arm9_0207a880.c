
unsigned int GetDriverYRotation(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_207a880: r2 = 0x217ad18u;
L_207a884: r1 = 0x5a8u;
L_207a888: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_207a88c: r1 = (r0*r1+r2);
L_207a890: r0 = (r1+0x200u);
L_207a894: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 54));
L_207a898: return r0;
}
