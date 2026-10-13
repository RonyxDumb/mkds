
unsigned int func_020e1dc0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20e1dc0: r3 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 4));
L_20e1dc4: ip = 0x0u;
L_20e1dc8: cmp_a = r3; cmp_b = 0x0u;
L_20e1dcc: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_20e1dd0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20e1dd4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + (ip << 2))));
L_20e1dd8: ip = (ip+0x1u);
L_20e1ddc: *(unsigned int *)((unsigned char *)r2 + 320) = (unsigned int)r1;
L_20e1de0: cmp_a = ip; cmp_b = r3;
L_20e1de4: if (((int)cmp_a < (int)cmp_b)) { goto L_20e1dd0; }
L_20e1de8: return r0;
}
