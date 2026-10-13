/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_1(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SomeTexPltFn_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013120: r6 = r0;
L_2013124: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013128: r5 = r1;
L_201312c: r4 = 0x0u;
L_2013130: cmp_a = r0; cmp_b = 0x0u;
L_2013138: if ((cmp_a <= cmp_b)) { return r0; }
L_201313c: r0 = r6;
L_2013140: r1 = r4;
L_2013144: r2 = r5;
L_2013148: r0 = ModelBlock_SomeTexPltFn_1(r0,r1,r2);
L_201314c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013150: r4 = (r4+0x1u);
L_2013154: cmp_a = r4; cmp_b = r0;
L_2013158: if ((cmp_a < cmp_b)) { goto L_201313c; }
L_2013160: return r0;
}
