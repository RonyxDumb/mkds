/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0209bf8c(void);
unsigned int func_0209a728(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a730: r0 = func_0209bf8c();
L_209a734: r1 = 0x84u;
L_209a738: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)r1;
L_209a744: return r0;
}
