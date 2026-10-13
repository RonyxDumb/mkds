/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210b7ec(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_02109078(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f5fb8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f5fbc: r4 = r0;
L_20f5fc0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f5fc4: r0 = (r0&0x400000u); cmp_a = r0; cmp_b = 0;
L_20f5fcc: if ((cmp_a == cmp_b)) { return r0; }
L_20f5fd0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 212));
L_20f5fd4: r0 = (r4+0x258u);
L_20f5fd8: r1 = (r1&~(0xc000001fu));
L_20f5fdc: r0 = func_0210b7ec(r0,r1,r2,r3);
L_20f5fe0: r0 = r4;
L_20f5fe4: r1 = 0xd8u;
L_20f5fe8: r2 = 0x7fu;
L_20f5fec: r3 = 0x0u;
L_20f5ff0: r0 = func_02109078(r0,r1,r2,r3);
L_20f5ff8: return r0;
}
