/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207e4a4(unsigned int);
extern unsigned int func_0207d6a4(unsigned int, unsigned int);
unsigned int func_0208bdc0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_208bdc4: r4 = r0;
L_208bdc8: r0 = func_0207e4a4(r0);
L_208bdcc: r1 = r4;
L_208bdd0: r0 = (r4+0xe8u);
L_208bdd4: r0 = func_0207d6a4(r0,r1);
L_208bddc: return r0;
}
