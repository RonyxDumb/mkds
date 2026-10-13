/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208f8ac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f8b4: r5 = r0;
L_208f8b8: r4 = r1;
L_208f8bc: r0 = func_0207bfac(r0);
L_208f8c0: cmp_a = r0; cmp_b = 0x0u;
L_208f8cc: if ((cmp_a == cmp_b)) { return r0; }
L_208f8d0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f8d4: cmp_a = r0; cmp_b = 0x0u;
L_208f8e0: if ((cmp_a == cmp_b)) { return r0; }
L_208f8e4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f8e8: r0 = 0x15f90u;
L_208f8ec: cmp_a = r1; cmp_b = r0;
L_208f8f8: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f8fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f900: cmp_a = r0; cmp_b = 0x0u;
L_208f90c: if ((cmp_a == cmp_b)) { return r0; }
L_208f910: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 188));
L_208f914: r0 = 0x666u;
L_208f918: cmp_a = r1; cmp_b = r0;
L_208f924: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_208f928: r0 = r5;
L_208f92c: r1 = r4;
L_208f930: r0 = func_0207c614(r0,r1);
L_208f93c: return r0;
}
