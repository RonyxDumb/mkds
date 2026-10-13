/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0203c5e4(void);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int func_020e33c0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e33c4: r4 = r0;
L_20e33c8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 172));
L_20e33cc: r0 = 0x4800u;
L_20e33d0: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r1;
L_20e33d4: *(unsigned int *)((unsigned char *)r4 + 20) = (unsigned int)r0;
L_20e33d8: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 2));
L_20e33dc: r0 = (r0&~(0x1u));
L_20e33e0: *(unsigned short *)((unsigned char *)r4 + 2) = (unsigned short)r0;
L_20e33e4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 120));
L_20e33e8: r0 = (r0&0x3u); cmp_a = r0; cmp_b = 0;
L_20e33ec: if ((cmp_a == cmp_b)) { goto L_20e3400; }
L_20e33f0: r0 = func_0203c5e4();
L_20e33f4: cmp_a = r0; cmp_b = 0x0u;
L_20e33fc: if ((cmp_a == cmp_b)) { return r0; }
L_20e3400: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 156));
L_20e3404: r0 = 0x30u;
L_20e3408: r0 = func_0208b7bc(r0,r1);
L_20e3410: return r0;
}
