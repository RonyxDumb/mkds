/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208f754(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f75c: r5 = r0;
L_208f760: r4 = r1;
L_208f764: r0 = func_0207bfac(r0);
L_208f768: cmp_a = r0; cmp_b = 0x0u;
L_208f774: if ((cmp_a == cmp_b)) { return r0; }
L_208f778: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f77c: cmp_a = r0; cmp_b = 0x0u;
L_208f788: if ((cmp_a == cmp_b)) { return r0; }
L_208f78c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f790: r0 = 0x15f90u;
L_208f794: cmp_a = r1; cmp_b = r0;
L_208f7a0: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f7a4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f7a8: cmp_a = r0; cmp_b = 0x0u;
L_208f7b4: if ((cmp_a == cmp_b)) { return r0; }
L_208f7b8: r0 = r5;
L_208f7bc: r1 = r4;
L_208f7c0: r0 = func_0207c614(r0,r1);
L_208f7cc: return r0;
}
