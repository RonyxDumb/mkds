/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207f8f8(unsigned int);
extern unsigned int func_0207de84(unsigned int, unsigned int);
extern unsigned int func_0207c270(unsigned int, unsigned int);
unsigned int func_0208c09c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_208c0a0: r4 = r0;
L_208c0a4: r0 = func_0207f8f8(r0);
L_208c0a8: r1 = r4;
L_208c0ac: r0 = (r4+0xe8u);
L_208c0b0: r0 = func_0207de84(r0,r1);
L_208c0b4: r1 = r4;
L_208c0b8: r0 = (r4+0x11cu);
L_208c0bc: r0 = func_0207c270(r0,r1);
L_208c0c4: return r0;
}
