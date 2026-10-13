/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_8(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SomeMatFn_4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013168: r6 = r0;
L_201316c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013170: r5 = r1;
L_2013174: r4 = 0x0u;
L_2013178: cmp_a = r0; cmp_b = 0x0u;
L_2013180: if ((cmp_a <= cmp_b)) { return r0; }
L_2013184: r0 = r6;
L_2013188: r1 = r4;
L_201318c: r2 = r5;
L_2013190: r0 = ModelBlock_SomeTexPltFn_8(r0,r1,r2);
L_2013194: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013198: r4 = (r4+0x1u);
L_201319c: cmp_a = r4; cmp_b = r0;
L_20131a0: if ((cmp_a < cmp_b)) { goto L_2013184; }
L_20131a8: return r0;
}
