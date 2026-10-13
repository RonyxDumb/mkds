
unsigned int func_02013b20(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2013b20: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 18));
L_2013b24: r0 = (r0+0xcu);
L_2013b28: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + (0 + r3)));
L_2013b2c: r0 = (r0+r3);
L_2013b30: r0 = (r0+0x4u);
L_2013b34: r0 = (r2*r1+r0);
L_2013b38: return r0;
}
