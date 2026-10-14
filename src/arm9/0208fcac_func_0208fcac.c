/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c548(unsigned int, unsigned int);
extern unsigned int func_0207c47c(unsigned int, unsigned int);
unsigned int func_0208fcac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_208fcb4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 176));
L_208fcb8: cmp_a = r2; cmp_b = 0x0u;
L_208fcc4: if ((cmp_a == cmp_b)) { return r0; }
L_208fcc8: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 184));
L_208fccc: r2 = 0x15f90u;
L_208fcd0: cmp_a = r3; cmp_b = r2;
L_208fcdc: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208fce0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 180));
L_208fce4: cmp_a = r2; cmp_b = 0x0u;
L_208fce8: if ((cmp_a == cmp_b)) { goto L_208fd0c; }
L_208fcec: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 188));
L_208fcf0: r2 = 0xb33u;
L_208fcf4: cmp_a = r3; cmp_b = r2;
L_208fcf8: if (((int)cmp_a <= (int)cmp_b)) { goto L_208fd0c; }
L_208fcfc: r0 = func_0207c548(r0,r1);
L_208fd08: return r0;
L_208fd0c: r0 = func_0207c47c(r0,r1);
L_208fd18: return r0;
}
