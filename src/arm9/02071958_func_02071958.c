/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210b564(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02071958(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_2071960: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 1280));
L_2071964: stack_0 = r2;
L_2071968: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 992));
L_207196c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 996));
L_2071970: r0 = func_0210b564(r0,r1,r2,r3,stack_0);
L_207197c: return r0;
}
