/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210b2a8(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02071980(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0;
L_2071988: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 1280));
L_207198c: stack_0 = r2;
L_2071990: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 992));
L_2071994: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 996));
L_2071998: r0 = func_0210b2a8(r0,r1,r2,r3,stack_0);
L_20719a4: return r0;
}
