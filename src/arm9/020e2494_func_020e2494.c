/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020e24d0(unsigned int, unsigned int);
extern unsigned int func_020d26f8(unsigned int, unsigned int);
unsigned int func_020e2494(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20e2498: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_20e249c: r6 = r0;
L_20e24a0: r5 = r1;
L_20e24a4: r4 = r3;
L_20e24a8: cmp_a = r2; cmp_b = 0x1u;
L_20e24ac: if ((cmp_a != cmp_b)) { goto L_20e24c4; }
L_20e24b0: r1 = (r5+0x80u);
L_20e24b4: r0 = func_020e24d0(r0,r1);
L_20e24b8: r0 = r6;
L_20e24bc: r1 = r5;
L_20e24c0: r0 = func_020d26f8(r0,r1);
L_20e24c4: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20e24cc: return r0;
}
