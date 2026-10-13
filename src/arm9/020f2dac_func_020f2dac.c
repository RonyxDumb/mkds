/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f92e8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f2dac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f2db0: r4 = r0;
L_20f2db4: r1 = r2;
L_20f2db8: r0 = (r4+0x5cu);
L_20f2dbc: r0 = func_020f92e8(r0,r1,r2,r3);
L_20f2dc0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f2dc4: r1 = (r0&0x1000000u); cmp_a = r1; cmp_b = 0;
L_20f2dcc: if ((cmp_a != cmp_b)) { return r0; }
L_20f2dd0: r0 = (r0|0x1000000u);
L_20f2dd4: *(unsigned int *)((unsigned char *)r4 + 116) = (unsigned int)r0;
L_20f2dd8: r0 = 0x0u;
L_20f2ddc: *(unsigned int *)((unsigned char *)r4 + 264) = (unsigned int)r0;
L_20f2de0: *(unsigned int *)((unsigned char *)r4 + 268) = (unsigned int)r0;
L_20f2de4: *(unsigned int *)((unsigned char *)r4 + 272) = (unsigned int)r0;
L_20f2dec: return r0;
}
