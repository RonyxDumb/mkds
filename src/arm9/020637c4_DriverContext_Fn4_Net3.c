/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02064f50(unsigned int);
extern unsigned int func_020641f0(unsigned int);
unsigned int DriverContext_Fn4_Net3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20637c8: r4 = r0;
L_20637cc: r0 = func_02064f50(r0);
L_20637d0: r0 = r4;
L_20637d4: r0 = func_020641f0(r0);
L_20637dc: return r0;
}
