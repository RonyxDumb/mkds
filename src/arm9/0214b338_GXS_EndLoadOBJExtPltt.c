/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_WaitDma(unsigned int);
extern unsigned int GX_SetBankForSubOBJExtPltt(unsigned int);
unsigned int GXS_EndLoadOBJExtPltt(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214b340: r0 = 0x216f074u;
L_214b344: r1 = ~(0x0u);
L_214b348: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b34c: cmp_a = r0; cmp_b = r1;
L_214b350: if ((cmp_a == cmp_b)) { goto L_214b358; }
L_214b354: r0 = MI_WaitDma(r0);
L_214b358: r0 = 0x21802e4u;
L_214b35c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b360: r0 = GX_SetBankForSubOBJExtPltt(r0);
L_214b364: r0 = 0x21802e4u;
L_214b368: r1 = 0x0u;
L_214b36c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_214b378: return r0;
}
