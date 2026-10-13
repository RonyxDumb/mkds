
unsigned int func_02033dfc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2033dfc: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2033dfe: r1 = 0x2174e60u;
L_2033e00: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2033e02: r1 = 0x148u;
L_2033e04: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_2033e06: cmp_a = r1; cmp_b = 0x0u;
L_2033e08: if ((cmp_a == cmp_b)) { goto L_2033e14; }
L_2033e0a: r1 = 0x14cu;
L_2033e0c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_2033e0e: cmp_a = r1; cmp_b = 0x0u;
L_2033e10: if ((cmp_a != cmp_b)) { goto L_2033e14; }
L_2033e12: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_2033e14: return r0;
}
