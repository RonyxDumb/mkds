/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208f810(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f818: r5 = r0;
L_208f81c: r4 = r1;
L_208f820: r0 = func_0207bfac(r0);
L_208f824: cmp_a = r0; cmp_b = 0x0u;
L_208f830: if ((cmp_a == cmp_b)) { return r0; }
L_208f834: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f838: cmp_a = r0; cmp_b = 0x0u;
L_208f844: if ((cmp_a == cmp_b)) { return r0; }
L_208f848: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f84c: r0 = 0x15f90u;
L_208f850: cmp_a = r1; cmp_b = r0;
L_208f85c: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f860: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f864: cmp_a = r0; cmp_b = 0x0u;
L_208f870: if ((cmp_a == cmp_b)) { return r0; }
L_208f874: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 188));
L_208f878: r0 = 0x666u;
L_208f87c: cmp_a = r1; cmp_b = r0;
L_208f888: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_208f88c: r0 = r5;
L_208f890: r1 = r4;
L_208f894: r0 = func_0207c614(r0,r1);
L_208f8a0: return r0;
}
