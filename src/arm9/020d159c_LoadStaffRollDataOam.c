/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Arm_FlushRange(unsigned int, unsigned int);
extern unsigned int CopyToOamA(unsigned int, unsigned int, unsigned int);
extern unsigned int BrightCtx_SomeFn_0(unsigned int, unsigned int);
extern unsigned int BrightCtx_SomeFn_1(unsigned int, unsigned int);
unsigned int LoadStaffRollDataOam(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d15a4: r0 = 0x217b4acu;
L_20d15a8: r1 = 0x400u;
L_20d15ac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d15b0: r0 = (r0+0x10u);
L_20d15b4: r0 = Arm_FlushRange(r0,r1);
L_20d15b8: r0 = 0x217b4acu;
L_20d15bc: r1 = 0x0u;
L_20d15c0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d15c4: r2 = 0x400u;
L_20d15c8: r0 = (r0+0x10u);
L_20d15cc: r0 = CopyToOamA(r0,r1,r2);
L_20d15d0: r0 = 0x217b4acu;
L_20d15d4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d15d8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d15dc: cmp_a = r1; cmp_b = 0x1a4u;
L_20d15e0: if ((cmp_a != cmp_b)) { goto L_20d15fc; }
L_20d15e4: r0 = 0x78u;
L_20d15e8: r1 = 0x1u;
L_20d15ec: r0 = BrightCtx_SomeFn_0(r0,r1);
L_20d15f8: return r0;
L_20d15fc: r0 = 0x77au;
L_20d1600: cmp_a = r1; cmp_b = r0;
L_20d160c: if ((cmp_a != cmp_b)) { return r0; }
L_20d1610: r0 = 0x78u;
L_20d1614: r1 = 0x1u;
L_20d1618: r0 = BrightCtx_SomeFn_1(r0,r1);
L_20d1624: return r0;
}
