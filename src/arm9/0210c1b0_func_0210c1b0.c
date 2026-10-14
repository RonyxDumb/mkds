/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210c238(unsigned int, unsigned int);
extern unsigned int func_0210bc54(unsigned int, unsigned int);
unsigned int func_0210c1b0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_210c1b8: r5 = r0;
L_210c1bc: r1 = 0x0u;
L_210c1c0: r0 = func_0210c238(r0,r1);
L_210c1c4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_210c1c8: cmp_a = r1; cmp_b = 0x0u;
L_210c1cc: if ((cmp_a == cmp_b)) { goto L_210c1e8; }
L_210c1d0: r4 = (r5+0xcu);
L_210c1d4: r0 = r4;
L_210c1d8: r0 = func_0210bc54(r0,r1);
L_210c1dc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_210c1e0: cmp_a = r1; cmp_b = 0x0u;
L_210c1e4: if ((cmp_a != cmp_b)) { goto L_210c1d4; }
L_210c1e8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 24));
L_210c1ec: cmp_a = r2; cmp_b = 0x3u;
L_210c1f0: if ((cmp_a == cmp_b)) { goto L_210c210; }
L_210c1f4: r1 = 0x217d048u;
L_210c1f8: r0 = 0xcu;
L_210c1fc: r0 = (r2*r0+r1);
L_210c200: r1 = r5;
L_210c204: r0 = func_0210bc54(r0,r1);
L_210c208: r0 = 0x3u;
L_210c20c: *(unsigned int *)((unsigned char *)r5 + 24) = (unsigned int)r0;
L_210c210: r0 = 0x217d028u;
L_210c214: r1 = r5;
L_210c218: r0 = func_0210bc54(r0,r1);
L_210c21c: r0 = 0x0u;
L_210c220: *(unsigned int *)((unsigned char *)r5 + 56) = (unsigned int)r0;
L_210c22c: return r0;
}
