/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ff9048(unsigned int, unsigned int, unsigned int);
unsigned int func_02015ef4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2015ef8: r4 = r0;
L_2015efc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_2015f00: r0 = (r1&0x4u); cmp_a = r0; cmp_b = 0;
L_2015f04: if ((cmp_a != cmp_b)) { goto L_2015f38; }
L_2015f08: r0 = (r1&0x2u); cmp_a = r0; cmp_b = 0;
L_2015f0c: if ((cmp_a != cmp_b)) { goto L_2015f24; }
L_2015f10: r1 = (r4+0x28u);
L_2015f14: r0 = 0x19u;
L_2015f18: r2 = 0xcu;
L_2015f1c: r0 = func_01ff9048(r0,r1,r2);
L_2015f20: goto L_2015f50;
L_2015f24: r1 = (r4+0x4cu);
L_2015f28: r0 = 0x1cu;
L_2015f2c: r2 = 0x3u;
L_2015f30: r0 = func_01ff9048(r0,r1,r2);
L_2015f34: goto L_2015f50;
L_2015f38: r0 = (r1&0x2u); cmp_a = r0; cmp_b = 0;
L_2015f3c: if ((cmp_a != cmp_b)) { goto L_2015f50; }
L_2015f40: r1 = (r4+0x28u);
L_2015f44: r0 = 0x1au;
L_2015f48: r2 = 0x9u;
L_2015f4c: r0 = func_01ff9048(r0,r1,r2);
L_2015f50: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_2015f54: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2015f5c: if ((cmp_a != cmp_b)) { return r0; }
L_2015f60: r1 = (r4+0x4u);
L_2015f64: r0 = 0x1bu;
L_2015f68: r2 = 0x3u;
L_2015f6c: r0 = func_01ff9048(r0,r1,r2);
L_2015f74: return r0;
}
