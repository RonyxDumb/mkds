
unsigned int CreateAnimBlock_BVA(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_2015e6c: r3 = 0x21617d4u;
L_2015e70: ip = 0x0u;
L_2015e74: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_2015e78: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r3;
L_2015e7c: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 23));
L_2015e80: *(unsigned char *)((unsigned char *)r0 + 25) = (unsigned char)r2;
L_2015e84: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r1;
L_2015e88: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 25));
L_2015e8c: cmp_a = r1; cmp_b = 0x0u;
L_2015e90: if ((cmp_a <= cmp_b)) { return r0; }
L_2015e94: r2 = (ip|0x100u);
L_2015e98: r1 = (r0+(ip << 1));
L_2015e9c: *(unsigned short *)((unsigned char *)r1 + 26) = (unsigned short)r2;
L_2015ea0: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 25));
L_2015ea4: ip = (ip+0x1u);
L_2015ea8: cmp_a = ip; cmp_b = r1;
L_2015eac: if ((cmp_a < cmp_b)) { goto L_2015e94; }
L_2015eb0: return r0;
}
