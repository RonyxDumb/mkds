/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02013588(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SetLight(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20131b0: r6 = r0;
L_20131b4: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20131b8: r5 = r1;
L_20131bc: r4 = 0x0u;
L_20131c0: cmp_a = r0; cmp_b = 0x0u;
L_20131c8: if ((cmp_a <= cmp_b)) { return r0; }
L_20131cc: r0 = r6;
L_20131d0: r1 = r4;
L_20131d4: r2 = r5;
L_20131d8: r0 = func_02013588(r0,r1,r2);
L_20131dc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20131e0: r4 = (r4+0x1u);
L_20131e4: cmp_a = r4; cmp_b = r0;
L_20131e8: if ((cmp_a < cmp_b)) { goto L_20131cc; }
L_20131f0: return r0;
}
