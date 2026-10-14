/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0202210c(unsigned int);
extern unsigned int func_0202294c(unsigned int);
unsigned int func_02022898(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_202289c: r4 = r0;
L_20228a0: r0 = func_0202210c(r0);
L_20228a4: cmp_a = r0; cmp_b = 0x0u;
L_20228ac: if ((cmp_a == cmp_b)) { return r0; }
L_20228b0: r0 = r4;
L_20228b4: r0 = func_0202294c(r0);
L_20228bc: return r0;
}
