/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210b7ec(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_02109078(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f6220(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f6224: r4 = r0;
L_20f6228: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f622c: r0 = (r0&0x400000u); cmp_a = r0; cmp_b = 0;
L_20f6234: if ((cmp_a == cmp_b)) { return r0; }
L_20f6238: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 212));
L_20f623c: r0 = (r4+0x16cu);
L_20f6240: r1 = (r1&~(0xc000001fu));
L_20f6244: r0 = func_0210b7ec(r0,r1,r2,r3);
L_20f6248: r0 = r4;
L_20f624c: r1 = 0xd7u;
L_20f6250: r2 = 0x7fu;
L_20f6254: r3 = 0x0u;
L_20f6258: r0 = func_02109078(r0,r1,r2,r3);
L_20f6260: return r0;
}
