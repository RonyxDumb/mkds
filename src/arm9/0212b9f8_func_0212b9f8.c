/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212cb78(unsigned int, unsigned int, unsigned int);
extern unsigned int SND_StopTimer(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int func_02021114(void);
extern unsigned int Sound_FlushCommand(unsigned int);
extern unsigned int func_02021154(unsigned int);
unsigned int func_0212b9f8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_212b9fc: r0 = func_0212cb78(r0,r1,r2);
L_212ba00: r0 = 0x0u;
L_212ba04: r1 = r0;
L_212ba08: r2 = r0;
L_212ba0c: r3 = r0;
L_212ba10: r0 = SND_StopTimer(r0,r1,r2,r3);
L_212ba14: r0 = func_02021114();
L_212ba18: r4 = r0;
L_212ba1c: r0 = 0x1u;
L_212ba20: r0 = Sound_FlushCommand(r0);
L_212ba24: r0 = r4;
L_212ba28: r0 = func_02021154(r0);
L_212ba30: return r0;
}
