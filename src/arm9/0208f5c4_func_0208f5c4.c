/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c548(unsigned int, unsigned int);
extern unsigned int func_0207c47c(unsigned int, unsigned int);
unsigned int func_0208f5c4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f5cc: r5 = r0;
L_208f5d0: r4 = r1;
L_208f5d4: r0 = func_0207bfac(r0);
L_208f5d8: cmp_a = r0; cmp_b = 0x0u;
L_208f5e4: if ((cmp_a == cmp_b)) { return r0; }
L_208f5e8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_208f5ec: cmp_a = r0; cmp_b = 0x0u;
L_208f5f8: if ((cmp_a == cmp_b)) { return r0; }
L_208f5fc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 184));
L_208f600: r0 = 0x15f90u;
L_208f604: cmp_a = r1; cmp_b = r0;
L_208f610: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208f614: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 180));
L_208f618: cmp_a = r0; cmp_b = 0x0u;
L_208f61c: if ((cmp_a == cmp_b)) { goto L_208f650; }
L_208f620: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 188));
L_208f624: r0 = 0xb33u;
L_208f628: cmp_a = r1; cmp_b = r0;
L_208f634: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_208f638: r0 = r5;
L_208f63c: r1 = r4;
L_208f640: r0 = func_0207c548(r0,r1);
L_208f64c: return r0;
L_208f650: r0 = r5;
L_208f654: r1 = r4;
L_208f658: r0 = func_0207c47c(r0,r1);
L_208f664: return r0;
}
