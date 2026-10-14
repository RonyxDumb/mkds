/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_UnlockCard(unsigned int);
extern unsigned int Card_UnlockResource(unsigned int, unsigned int);
unsigned int Card_UnlockRomResource(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_21457b0: r4 = r0;
L_21457b4: r0 = Os_UnlockCard(r0);
L_21457b8: r0 = r4;
L_21457bc: r1 = 0x1u;
L_21457c0: r0 = Card_UnlockResource(r0,r1);
L_21457c8: return r0;
}
