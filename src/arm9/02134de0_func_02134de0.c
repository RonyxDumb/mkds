/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02134f18(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02134de0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2134de4: r4 = r0;
L_2134de8: r0 = func_02134f18(r0,r1,r2,r3);
L_2134dec: r0 = r4;
L_2134df4: return r0;
}
