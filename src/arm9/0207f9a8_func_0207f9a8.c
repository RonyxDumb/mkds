/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02080cd0(unsigned int, unsigned int);
extern unsigned int func_0207f9cc(unsigned int, unsigned int);
unsigned int func_0207f9a8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_207f9ac: r4 = r0;
L_207f9b0: r0 = (r4+0x8u);
L_207f9b4: r0 = func_02080cd0(r0,r1);
L_207f9b8: r0 = r4;
L_207f9bc: r1 = 0x1u;
L_207f9c0: r0 = func_0207f9cc(r0,r1);
L_207f9c8: return r0;
}
