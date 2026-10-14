/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210e434(unsigned int);
unsigned int func_0210dc7c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210dc84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 16));
L_210dc88: r0 = func_0210e434(r0);
L_210dc8c: r0 = 0x217d060u;
L_210dc90: r1 = 0x0u;
L_210dc94: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_210dca0: return r0;
}
