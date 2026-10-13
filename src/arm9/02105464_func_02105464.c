/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020de6a8(unsigned int, unsigned int);
extern unsigned int func_020d2398(unsigned int);
unsigned int func_02105464(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2105468: r4 = r0;
L_210546c: r0 = func_020de6a8(r0,r1);
L_2105470: r0 = r4;
L_2105474: r0 = func_020d2398(r0);
L_210547c: return r0;
}
