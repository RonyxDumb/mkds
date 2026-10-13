/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f8e78(unsigned int);
extern unsigned int func_0210b850(unsigned int);
extern unsigned int func_020f1ea4(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f5ffc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f6000: r4 = r0;
L_20f6004: r0 = func_020f8e78(r0);
L_20f6008: r0 = (r4+0x16cu);
L_20f600c: r0 = func_0210b850(r0);
L_20f6010: r1 = 0x210a77cu;
L_20f6014: r0 = r4;
L_20f6018: *(unsigned int *)((unsigned char *)r4 + 48) = (unsigned int)r1;
L_20f601c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 360));
L_20f6020: r1 = 0x9u;
L_20f6024: r3 = 0x0u;
L_20f6028: r0 = func_020f1ea4(r0,r1,r2,r3);
L_20f6030: return r0;
}
