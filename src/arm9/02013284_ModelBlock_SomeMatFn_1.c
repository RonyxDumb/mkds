/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_5(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SomeMatFn_1(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013288: r6 = r0;
L_201328c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013290: r5 = r1;
L_2013294: r4 = 0x0u;
L_2013298: cmp_a = r0; cmp_b = 0x0u;
L_20132a0: if ((cmp_a <= cmp_b)) { return r0; }
L_20132a4: r0 = r6;
L_20132a8: r1 = r4;
L_20132ac: r2 = r5;
L_20132b0: r0 = ModelBlock_SomeTexPltFn_5(r0,r1,r2);
L_20132b4: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20132b8: r4 = (r4+0x1u);
L_20132bc: cmp_a = r4; cmp_b = r0;
L_20132c0: if ((cmp_a < cmp_b)) { goto L_20132a4; }
L_20132c8: return r0;
}
