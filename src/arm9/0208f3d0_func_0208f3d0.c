/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c47c(unsigned int, unsigned int);
unsigned int func_0208f3d0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f3d8: r5 = r0;
L_208f3dc: r4 = r1;
L_208f3e0: r0 = func_0207bfac(r0);
L_208f3e4: cmp_a = r0; cmp_b = 0x0u;
L_208f3e8: if ((cmp_a != cmp_b)) { goto L_208f418; }
L_208f3ec: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f3f0: cmp_a = r0; cmp_b = 0x0u;
L_208f3fc: if ((cmp_a == cmp_b)) { return r0; }
L_208f400: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f404: r0 = 0x15f90u;
L_208f408: cmp_a = r1; cmp_b = r0;
L_208f414: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f418: r0 = r5;
L_208f41c: r1 = r4;
L_208f420: r0 = func_0207c47c(r0,r1);
L_208f42c: return r0;
}
