/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f8e78(unsigned int);
extern unsigned int func_02102eb8(unsigned int, unsigned int);
unsigned int func_02102744(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2102748: r4 = r0;
L_210274c: r0 = func_020f8e78(r0);
L_2102750: r0 = r4;
L_2102754: r1 = 0x1u;
L_2102758: r0 = func_02102eb8(r0,r1);
L_2102760: return r0;
}
