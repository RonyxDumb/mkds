/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_WaitDma(unsigned int);
extern unsigned int func_021493b0(unsigned int);
unsigned int func_0214c1bc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214c1c4: r0 = 0x216f074u;
L_214c1c8: r1 = ~(0x0u);
L_214c1cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214c1d0: cmp_a = r0; cmp_b = r1;
L_214c1d4: if ((cmp_a == cmp_b)) { goto L_214c1dc; }
L_214c1d8: r0 = MI_WaitDma(r0);
L_214c1dc: r0 = 0x21802e8u;
L_214c1e0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214c1e4: r0 = func_021493b0(r0);
L_214c1e8: r1 = 0x21802e8u;
L_214c1ec: r2 = 0x0u;
L_214c1f0: r0 = 0x21802f8u;
L_214c1f4: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_214c1f8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_214c204: return r0;
}
