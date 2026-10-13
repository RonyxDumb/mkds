
unsigned int GetDriverKartIndexMod3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2079b40: r2 = 0x217ad00u;
L_2079b44: r1 = 0xb4u;
L_2079b48: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2079b4c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2079b50: r1 = (r0*r1+r2);
L_2079b54: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 104));
L_2079b58: return r0;
}
