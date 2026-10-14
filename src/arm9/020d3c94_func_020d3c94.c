/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d2c2c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020d3c94(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0,stack_4;
L_20d3c9c: stack_0 = r1;
L_20d3ca0: r1 = r0;
L_20d3ca4: stack_4 = r2;
L_20d3ca8: r3 = (unsigned int)(*(short *)((unsigned char *)r1 + 100));
L_20d3cac: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 88));
L_20d3cb0: r0 = (r1+0x4u);
L_20d3cb4: r1 = (r1+0x10u);
L_20d3cb8: r0 = func_020d2c2c(r0,r1,r2,r3,stack_0,stack_4);
L_20d3cc4: return r0;
}
