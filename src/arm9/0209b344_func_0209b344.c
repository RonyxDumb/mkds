/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0209b388(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_020d26f8(unsigned int, unsigned int);
unsigned int func_0209b344(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_209b348: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_209b34c: r6 = r0;
L_209b350: r5 = r1;
L_209b354: cmp_a = r2; cmp_b = 0x1u;
L_209b358: r4 = (unsigned int)(*(unsigned char *)((unsigned char *)r3 + 0));
L_209b35c: if ((cmp_a != cmp_b)) { goto L_209b37c; }
L_209b360: r1 = (r5+0x80u);
L_209b364: r2 = (r5+0x68u);
L_209b368: r3 = (r5+0xa4u);
L_209b36c: r0 = func_0209b388(r0,r1,r2,r3);
L_209b370: r0 = r6;
L_209b374: r1 = r5;
L_209b378: r0 = func_020d26f8(r0,r1);
L_209b37c: r0 = (r4&0xffu);
L_209b384: return r0;
}
