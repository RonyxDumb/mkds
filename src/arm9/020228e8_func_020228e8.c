/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02022030(unsigned int, unsigned int);
extern unsigned int func_0202294c(unsigned int);
unsigned int func_020228e8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20228ec: r4 = r0;
L_20228f0: r0 = func_02022030(r0,r1);
L_20228f4: r0 = r4;
L_20228f8: r0 = func_0202294c(r0);
L_2022900: return r0;
}
