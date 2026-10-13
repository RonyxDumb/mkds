
unsigned int func_020a128c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a128c: r1 = 0x217b1fcu;
L_20a1290: r0 = 0x0u;
L_20a1294: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20a1298: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 948));
L_20a129c: cmp_a = r1; cmp_b = 0x0u;
L_20a12a0: if (((int)cmp_a < (int)cmp_b)) { return r0; }
L_20a12a4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 936));
L_20a12a8: cmp_a = r1; cmp_b = 0x0u;
L_20a12ac: if (((int)cmp_a < (int)cmp_b)) { r0 = 0x1u; }
L_20a12b0: return r0;
}
