/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f2228(unsigned int, unsigned int);
extern unsigned int func_0210ddf4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f56d0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,stack_0;
L_20f56d8: r4 = r0;
L_20f56dc: r1 = 0xc000u;
L_20f56e0: r0 = func_020f2228(r0,r1);
L_20f56e4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f56e8: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_20f56f4: if ((cmp_a != cmp_b)) { return r0; }
L_20f56f8: r0 = 0x0u;
L_20f56fc: stack_0 = r0;
L_20f5700: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 212));
L_20f5704: r0 = 0x217d294u;
L_20f5708: r2 = 0x20f5fb8u;
L_20f570c: r3 = r4;
L_20f5710: r1 = (r1&~(0xc000001fu));
L_20f5714: r0 = func_0210ddf4(r0,r1,r2,r3,stack_0);
L_20f5720: return r0;
}
