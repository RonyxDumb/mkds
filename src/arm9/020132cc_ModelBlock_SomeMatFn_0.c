/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_4(unsigned int, unsigned int, unsigned int);
unsigned int ModelBlock_SomeMatFn_0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20132d0: r6 = r0;
L_20132d4: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_20132d8: r5 = r1;
L_20132dc: r4 = 0x0u;
L_20132e0: cmp_a = r0; cmp_b = 0x0u;
L_20132e8: if ((cmp_a <= cmp_b)) { return r0; }
L_20132ec: r0 = r6;
L_20132f0: r1 = r4;
L_20132f4: r2 = r5;
L_20132f8: r0 = ModelBlock_SomeTexPltFn_4(r0,r1,r2);
L_20132fc: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013300: r4 = (r4+0x1u);
L_2013304: cmp_a = r4; cmp_b = r0;
L_2013308: if ((cmp_a < cmp_b)) { goto L_20132ec; }
L_2013310: return r0;
}
