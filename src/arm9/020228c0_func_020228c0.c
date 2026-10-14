/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0202212c(unsigned int, unsigned int);
extern unsigned int func_0202294c(unsigned int);
unsigned int func_020228c0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20228c4: r4 = r0;
L_20228c8: r0 = func_0202212c(r0,r1);
L_20228cc: cmp_a = r0; cmp_b = 0x0u;
L_20228d4: if ((cmp_a == cmp_b)) { return r0; }
L_20228d8: r0 = r4;
L_20228dc: r0 = func_0202294c(r0);
L_20228e4: return r0;
}
