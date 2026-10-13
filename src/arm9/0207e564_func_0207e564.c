/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02080cd0(unsigned int, unsigned int);
extern unsigned int func_0207f9cc(unsigned int, unsigned int);
unsigned int func_0207e564(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_207e568: r4 = r0;
L_207e56c: r0 = (r4+0x8u);
L_207e570: r0 = func_02080cd0(r0,r1);
L_207e574: r0 = r4;
L_207e578: r1 = 0x1u;
L_207e57c: r0 = func_0207f9cc(r0,r1);
L_207e580: r0 = r4;
L_207e584: r1 = 0x1u;
L_207e588: r0 = func_0207f9cc(r0,r1);
L_207e590: return r0;
}
