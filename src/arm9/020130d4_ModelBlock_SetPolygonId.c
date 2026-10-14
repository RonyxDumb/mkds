/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_3(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SetPolygonId(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20130d8: r6 = r0;
L_20130dc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20130e0: r5 = r1;
L_20130e4: r4 = 0x0u;
L_20130e8: cmp_a = r0; cmp_b = 0x0u;
L_20130f0: if ((cmp_a <= cmp_b)) { return r0; }
L_20130f4: r0 = r6;
L_20130f8: r1 = r4;
L_20130fc: r2 = r5;
L_2013100: r0 = ModelBlock_SomeTexPltFn_3(r0,r1,r2);
L_2013104: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013108: r4 = (r4+0x1u);
L_201310c: cmp_a = r4; cmp_b = r0;
L_2013110: if ((cmp_a < cmp_b)) { goto L_20130f4; }
L_2013118: return r0;
}
