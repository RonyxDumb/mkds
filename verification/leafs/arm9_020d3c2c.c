
unsigned int GetIncrementSomeItemCounter(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d3c2c: r1 = 0x217b4d0u;
L_20d3c30: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 0));
L_20d3c34: r2 = (r0+0x1u);
L_20d3c38: *(unsigned short *)((unsigned char *)r1 + 0) = (unsigned short)r2;
L_20d3c3c: return r0;
}
