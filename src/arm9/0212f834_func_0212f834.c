/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212f7f8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0212f834(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_212f838: r6 = r0;
L_212f83c: r5 = r1;
L_212f840: r4 = r2;
L_212f844: r0 = func_0212f7f8(r0,r1,r2,r3);
L_212f848: *(unsigned int *)((unsigned char *)r6 + 0) = (unsigned int)r0;
L_212f84c: *(unsigned int *)((unsigned char *)r6 + 4) = (unsigned int)r5;
L_212f850: *(unsigned int *)((unsigned char *)r6 + 12) = (unsigned int)r4;
L_212f854: r0 = 0x0u;
L_212f858: *(unsigned int *)((unsigned char *)r6 + 8) = (unsigned int)r0;
L_212f860: return r0;
}
