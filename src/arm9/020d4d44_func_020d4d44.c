/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020e6df0(unsigned int);
extern unsigned int func_020d7bec(unsigned int);
unsigned int func_020d4d44(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d4d48: r4 = r0;
L_20d4d4c: r0 = func_020e6df0(r0);
L_20d4d50: r0 = r4;
L_20d4d54: r0 = func_020d7bec(r0);
L_20d4d5c: return r0;
}
