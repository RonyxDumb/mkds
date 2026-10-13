
unsigned int func_02095f38(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2095f38: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 176));
L_2095f3c: cmp_a = r0; cmp_b = 0x1u;
L_2095f40: if ((cmp_a == cmp_b)) { goto L_2095f4c; }
L_2095f44: cmp_a = r0; cmp_b = 0x4u;
L_2095f48: if ((cmp_a != cmp_b)) { goto L_2095f54; }
L_2095f4c: r0 = 0x1u;
L_2095f50: return r0;
L_2095f54: r0 = 0x0u;
L_2095f58: return r0;
}
