/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_WaitDma(unsigned int);
extern unsigned int func_021494f0(unsigned int);
unsigned int func_0214c3c0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214c3c8: r0 = 0x216f074u;
L_214c3cc: r1 = ~(0x0u);
L_214c3d0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214c3d4: cmp_a = r0; cmp_b = r1;
L_214c3d8: if ((cmp_a == cmp_b)) { goto L_214c3e0; }
L_214c3dc: r0 = MI_WaitDma(r0);
L_214c3e0: r0 = 0x21802f4u;
L_214c3e4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214c3e8: r0 = func_021494f0(r0);
L_214c3ec: r1 = 0x21802f4u;
L_214c3f0: r2 = 0x0u;
L_214c3f4: r0 = 0x21802f0u;
L_214c3f8: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_214c3fc: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_214c408: return r0;
}
