/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208f6d4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f6dc: r5 = r0;
L_208f6e0: r4 = r1;
L_208f6e4: r0 = func_0207bfac(r0);
L_208f6e8: cmp_a = r0; cmp_b = 0x0u;
L_208f6f4: if ((cmp_a == cmp_b)) { return r0; }
L_208f6f8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f6fc: cmp_a = r0; cmp_b = 0x0u;
L_208f708: if ((cmp_a == cmp_b)) { return r0; }
L_208f70c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f710: r0 = 0x15f90u;
L_208f714: cmp_a = r1; cmp_b = r0;
L_208f720: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f724: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f728: cmp_a = r0; cmp_b = 0x0u;
L_208f734: if ((cmp_a == cmp_b)) { return r0; }
L_208f738: r0 = r5;
L_208f73c: r1 = r4;
L_208f740: r0 = func_0207c614(r0,r1);
L_208f74c: return r0;
}
