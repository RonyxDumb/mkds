/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210008c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0209bc5c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_209bc60: r4 = r1;
L_209bc64: r0 = func_0210008c(r0,r1,r2,r3);
L_209bc68: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + (r4 << 2))));
L_209bc70: return r0;
}
