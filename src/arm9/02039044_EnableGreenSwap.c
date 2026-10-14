/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int WaitForIRQ(unsigned int, unsigned int);
extern unsigned int func_021489c4(void);
unsigned int EnableGreenSwap(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203904c: r0 = 0x1u;
L_2039050: r1 = r0;
L_2039054: r0 = WaitForIRQ(r0,r1);
L_2039058: r0 = func_021489c4();
L_203905c: r1 = 0x4001000u;
L_2039060: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2039064: r0 = (r0|0x10000u);
L_2039068: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2039074: return r0;
}
