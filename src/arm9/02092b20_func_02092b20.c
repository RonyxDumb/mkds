/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d2398(unsigned int);
extern unsigned int func_020d28e0(unsigned int);
unsigned int func_02092b20(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2092b24: r4 = r0;
L_2092b28: r0 = func_020d2398(r0);
L_2092b2c: r0 = r4;
L_2092b30: r0 = func_020d28e0(r0);
L_2092b38: return r0;
}
