/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c47c(unsigned int, unsigned int);
unsigned int func_0208f434(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f43c: r5 = r0;
L_208f440: r2 = 0x1u;
L_208f444: r4 = r1;
L_208f448: *(unsigned int *)((unsigned char *)r5 + 16) = (unsigned int)r2;
L_208f44c: r0 = func_0207bfac(r0);
L_208f450: cmp_a = r0; cmp_b = 0x0u;
L_208f45c: if ((cmp_a == cmp_b)) { return r0; }
L_208f460: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f464: cmp_a = r0; cmp_b = 0x0u;
L_208f470: if ((cmp_a == cmp_b)) { return r0; }
L_208f474: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f478: r0 = 0x15f90u;
L_208f47c: cmp_a = r1; cmp_b = r0;
L_208f488: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f48c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f490: cmp_a = r0; cmp_b = 0x0u;
L_208f494: if ((cmp_a == cmp_b)) { goto L_208f4c8; }
L_208f498: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 188));
L_208f49c: r0 = 0xb33u;
L_208f4a0: cmp_a = r1; cmp_b = r0;
L_208f4ac: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_208f4b0: r0 = r5;
L_208f4b4: r1 = r4;
L_208f4b8: r0 = func_0207c47c(r0,r1);
L_208f4c4: return r0;
L_208f4c8: r0 = r5;
L_208f4cc: r1 = r4;
L_208f4d0: r0 = func_0207c47c(r0,r1);
L_208f4dc: return r0;
}
