/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ff1b8(unsigned int, unsigned int);
extern unsigned int func_020fecdc(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ff1a0(unsigned int, unsigned int);
extern unsigned int func_020fe8ac(unsigned int);
unsigned int func_020ff2b0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20ff2b4: r6 = r1; cmp_a = r6; cmp_b = 0;
L_20ff2b8: r4 = r0;
L_20ff2bc: r5 = r2;
L_20ff2c0: if ((cmp_a == cmp_b)) { goto L_20ff2d8; }
L_20ff2c4: cmp_a = r5; cmp_b = 0x0u;
L_20ff2c8: if ((cmp_a == cmp_b)) { goto L_20ff2d8; }
L_20ff2cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 316));
L_20ff2d0: r1 = (r6+0x60u);
L_20ff2d4: r0 = func_020ff1b8(r0,r1);
L_20ff2d8: r0 = r4;
L_20ff2dc: r1 = r6;
L_20ff2e0: r2 = r5;
L_20ff2e4: r0 = func_020fecdc(r0,r1,r2);
L_20ff2e8: r4 = r0;
L_20ff2ec: cmp_a = r6; cmp_b = 0x0u;
L_20ff2f0: if ((cmp_a == cmp_b)) { goto L_20ff308; }
L_20ff2f4: cmp_a = r5; cmp_b = 0x0u;
L_20ff2f8: if ((cmp_a != cmp_b)) { goto L_20ff308; }
L_20ff2fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 96));
L_20ff300: r1 = (r6+0x13cu);
L_20ff304: r0 = func_020ff1a0(r0,r1);
L_20ff308: cmp_a = r6; cmp_b = 0x0u;
L_20ff30c: if ((cmp_a == cmp_b)) { goto L_20ff328; }
L_20ff310: cmp_a = r5; cmp_b = 0x0u;
L_20ff314: if ((cmp_a == cmp_b)) { goto L_20ff328; }
L_20ff318: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 68));
L_20ff31c: r0 = func_020fe8ac(r0);
L_20ff324: return r0;
L_20ff328: r0 = r4;
L_20ff330: return r0;
}
