/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02139e20(unsigned int);
extern unsigned int CheckZetaInvokeBeta(unsigned int);
unsigned int OnAssertionFailed(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2133fe0: r0 = 0x1u;
L_2133fe4: r0 = func_02139e20(r0);
L_2133fe8: r1 = 0x217e990u;
L_2133fec: r0 = 0x1u;
L_2133ff0: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2133ff4: r0 = CheckZetaInvokeBeta(r0);
L_2134000: return r0;
}
