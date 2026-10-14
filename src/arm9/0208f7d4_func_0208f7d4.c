/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207bfac(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208f7d4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208f7dc: r5 = r0;
L_208f7e0: r4 = r1;
L_208f7e4: r0 = func_0207bfac(r0);
L_208f7e8: cmp_a = r0; cmp_b = 0x0u;
L_208f7f4: if ((cmp_a == cmp_b)) { return r0; }
L_208f7f8: r0 = r5;
L_208f7fc: r1 = r4;
L_208f800: r0 = func_0207c614(r0,r1);
L_208f80c: return r0;
}
