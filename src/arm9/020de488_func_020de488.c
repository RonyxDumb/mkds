/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ec41c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020de488(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20de48c: r4 = r3;
L_20de490: r0 = func_020ec41c(r0,r1,r2,r3);
L_20de494: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20de49c: return r0;
}
