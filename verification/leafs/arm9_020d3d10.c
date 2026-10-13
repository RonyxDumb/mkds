
unsigned int func_020d3d10(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d3d10: r1 = 0x217b4d8u;
L_20d3d14: r3 = 0x0u;
L_20d3d18: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20d3d1c: cmp_a = r1; cmp_b = 0x0u;
L_20d3d20: if ((cmp_a == cmp_b)) { goto L_20d3d3c; }
L_20d3d24: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20d3d28: r1 = 0x32000u;
L_20d3d2c: r2 = (r0-r2);
L_20d3d30: r0 = (0x0u-r1);
L_20d3d34: cmp_a = r2; cmp_b = r0;
L_20d3d38: if (((int)cmp_a < (int)cmp_b)) { r3 = 0x1u; }
L_20d3d3c: r0 = r3;
L_20d3d40: return r0;
}
