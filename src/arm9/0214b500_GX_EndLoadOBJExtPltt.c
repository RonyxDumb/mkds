/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_WaitDma(unsigned int);
extern unsigned int GX_SetBankForOBJExtPltt(unsigned int);
unsigned int GX_EndLoadOBJExtPltt(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214b508: r0 = 0x216f074u;
L_214b50c: r1 = ~(0x0u);
L_214b510: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b514: cmp_a = r0; cmp_b = r1;
L_214b518: if ((cmp_a == cmp_b)) { goto L_214b520; }
L_214b51c: r0 = MI_WaitDma(r0);
L_214b520: r0 = 0x21802d4u;
L_214b524: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b528: r0 = GX_SetBankForOBJExtPltt(r0);
L_214b52c: r1 = 0x21802d4u;
L_214b530: r2 = 0x0u;
L_214b534: r0 = 0x21802d0u;
L_214b538: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r2;
L_214b53c: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2;
L_214b548: return r0;
}
