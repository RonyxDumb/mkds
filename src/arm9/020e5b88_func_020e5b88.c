/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ec41c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020e5b88(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e5b8c: r4 = r3;
L_20e5b90: r0 = func_020ec41c(r0,r1,r2,r3);
L_20e5b94: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20e5b9c: return r0;
}
