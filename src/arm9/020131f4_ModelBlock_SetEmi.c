/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_7(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SetEmi(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20131f8: r6 = r0;
L_20131fc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013200: r5 = r1;
L_2013204: r4 = 0x0u;
L_2013208: cmp_a = r0; cmp_b = 0x0u;
L_2013210: if ((cmp_a <= cmp_b)) { return r0; }
L_2013214: r0 = r6;
L_2013218: r1 = r4;
L_201321c: r2 = r5;
L_2013220: r0 = ModelBlock_SomeTexPltFn_7(r0,r1,r2);
L_2013224: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013228: r4 = (r4+0x1u);
L_201322c: cmp_a = r4; cmp_b = r0;
L_2013230: if ((cmp_a < cmp_b)) { goto L_2013214; }
L_2013238: return r0;
}
