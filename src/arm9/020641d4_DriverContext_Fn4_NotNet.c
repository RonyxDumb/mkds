/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ffcb58(unsigned int);
extern unsigned int func_020641f0(unsigned int);
unsigned int DriverContext_Fn4_NotNet(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20641d8: r4 = r0;
L_20641dc: r0 = func_01ffcb58(r0);
L_20641e0: r0 = r4;
L_20641e4: r0 = func_020641f0(r0);
L_20641ec: return r0;
}
