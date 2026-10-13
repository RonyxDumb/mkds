/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_WaitDma(unsigned int);
extern unsigned int GX_SetBankForSubBGExtPltt(unsigned int);
unsigned int GXS_EndLoadBGExtPltt(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214b424: r0 = 0x216f074u;
L_214b428: r1 = ~(0x0u);
L_214b42c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b430: cmp_a = r0; cmp_b = r1;
L_214b434: if ((cmp_a == cmp_b)) { goto L_214b43c; }
L_214b438: r0 = MI_WaitDma(r0);
L_214b43c: r0 = 0x21802ccu;
L_214b440: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_214b444: r0 = GX_SetBankForSubBGExtPltt(r0);
L_214b448: r0 = 0x21802ccu;
L_214b44c: r1 = 0x0u;
L_214b450: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_214b45c: return r0;
}
