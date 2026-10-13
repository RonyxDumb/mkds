/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02013468(unsigned int, unsigned int, unsigned int);
unsigned int Maybe_helper_01308c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013090: r6 = r0;
L_2013094: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013098: r5 = r1;
L_201309c: r4 = 0x0u;
L_20130a0: cmp_a = r0; cmp_b = 0x0u;
L_20130a8: if ((cmp_a <= cmp_b)) { return r0; }
L_20130ac: r0 = r6;
L_20130b0: r1 = r4;
L_20130b4: r2 = r5;
L_20130b8: r0 = func_02013468(r0,r1,r2);
L_20130bc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20130c0: r4 = (r4+0x1u);
L_20130c4: cmp_a = r4; cmp_b = r0;
L_20130c8: if ((cmp_a < cmp_b)) { goto L_20130ac; }
L_20130d0: return r0;
}
