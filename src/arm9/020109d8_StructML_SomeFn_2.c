/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02010a40(unsigned int, unsigned int);
unsigned int StructML_SomeFn_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20109e0: r5 = r0;
L_20109e4: r0 = (r5+0x8u);
L_20109e8: r4 = r1;
L_20109ec: r0 = func_02010a40(r0,r1);
L_20109f0: cmp_a = r0; cmp_b = 0x0u;
L_20109f4: if ((cmp_a != cmp_b)) { goto L_2010a28; }
L_20109f8: r1 = r4;
L_20109fc: r0 = (r5+0x10u);
L_2010a00: r0 = func_02010a40(r0,r1);
L_2010a04: cmp_a = r0; cmp_b = 0x0u;
L_2010a08: if ((cmp_a != cmp_b)) { goto L_2010a28; }
L_2010a0c: r1 = r4;
L_2010a10: r0 = (r5+0x18u);
L_2010a14: r0 = func_02010a40(r0,r1);
L_2010a18: cmp_a = r0; cmp_b = 0x0u;
L_2010a24: if ((cmp_a == cmp_b)) { return r0; }
L_2010a28: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 0));
L_2010a2c: r0 = (r0|0x10u);
L_2010a30: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r0;
L_2010a3c: return r0;
}
