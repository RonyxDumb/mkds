
unsigned int func_020d5a68(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d5a68: r1 = (r1&0x80000000u); cmp_a = r1; cmp_b = 0;
L_20d5a6c: if ((cmp_a != cmp_b)) { goto L_20d5a90; }
L_20d5a70: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d5a74: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 4));
L_20d5a78: cmp_a = r0; cmp_b = 0x0u;
L_20d5a7c: if ((cmp_a != cmp_b)) { goto L_20d5a90; }
L_20d5a80: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20d5a84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_20d5a88: cmp_a = r1; cmp_b = r0;
L_20d5a8c: if ((cmp_a == cmp_b)) { goto L_20d5a98; }
L_20d5a90: r0 = 0x1u;
L_20d5a94: return r0;
L_20d5a98: r0 = 0x0u;
L_20d5a9c: return r0;
}
