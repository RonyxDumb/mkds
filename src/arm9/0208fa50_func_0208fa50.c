/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c548(unsigned int, unsigned int);
extern unsigned int func_0207c47c(unsigned int, unsigned int);
unsigned int func_0208fa50(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208fa58: r5 = r0;
L_208fa5c: r2 = 0x1u;
L_208fa60: r4 = r1;
L_208fa64: *(unsigned int *)((unsigned char *)r5 + 16) = (unsigned int)r2;
L_208fa68: r0 = func_0207bfac(r0);
L_208fa6c: cmp_a = r0; cmp_b = 0x0u;
L_208fa78: if ((cmp_a == cmp_b)) { return r0; }
L_208fa7c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208fa80: cmp_a = r0; cmp_b = 0x0u;
L_208fa8c: if ((cmp_a == cmp_b)) { return r0; }
L_208fa90: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208fa94: r0 = 0x15f90u;
L_208fa98: cmp_a = r1; cmp_b = r0;
L_208faa4: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208faa8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208faac: cmp_a = r0; cmp_b = 0x0u;
L_208fab0: if ((cmp_a == cmp_b)) { goto L_208fadc; }
L_208fab4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 188));
L_208fab8: r0 = 0xb33u;
L_208fabc: cmp_a = r1; cmp_b = r0;
L_208fac0: if (((int)cmp_a <= (int)cmp_b)) { goto L_208fadc; }
L_208fac4: r0 = r5;
L_208fac8: r1 = r4;
L_208facc: r0 = func_0207c548(r0,r1);
L_208fad8: return r0;
L_208fadc: r0 = r5;
L_208fae0: r1 = r4;
L_208fae4: r0 = func_0207c47c(r0,r1);
L_208faf0: return r0;
}
