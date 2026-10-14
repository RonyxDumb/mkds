/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_6(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SomeMatFn_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013240: r6 = r0;
L_2013244: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013248: r5 = r1;
L_201324c: r4 = 0x0u;
L_2013250: cmp_a = r0; cmp_b = 0x0u;
L_2013258: if ((cmp_a <= cmp_b)) { return r0; }
L_201325c: r0 = r6;
L_2013260: r1 = r4;
L_2013264: r2 = r5;
L_2013268: r0 = ModelBlock_SomeTexPltFn_6(r0,r1,r2);
L_201326c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013270: r4 = (r4+0x1u);
L_2013274: cmp_a = r4; cmp_b = r0;
L_2013278: if ((cmp_a < cmp_b)) { goto L_201325c; }
L_2013280: return r0;
}
