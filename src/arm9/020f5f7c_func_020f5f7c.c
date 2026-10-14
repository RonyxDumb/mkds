/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f29e8(unsigned int);
extern unsigned int func_020f1f98(unsigned int, unsigned int, unsigned int);
unsigned int func_020f5f7c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20f5f80: r6 = r0;
L_20f5f84: r5 = r1;
L_20f5f88: r4 = r2;
L_20f5f8c: r0 = func_020f29e8(r0);
L_20f5f90: r0 = r6;
L_20f5f94: r1 = r5;
L_20f5f98: r2 = r4;
L_20f5f9c: r0 = func_020f1f98(r0,r1,r2);
L_20f5fa0: r0 = (r6+0x200u);
L_20f5fa4: r1 = 0x1u;
L_20f5fa8: *(unsigned short *)((unsigned char *)r0 + 76) = (unsigned short)r1;
L_20f5fac: *(unsigned short *)((unsigned char *)r0 + 78) = (unsigned short)r1;
L_20f5fb4: return r0;
}
