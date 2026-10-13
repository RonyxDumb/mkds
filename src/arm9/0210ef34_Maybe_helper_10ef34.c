/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02108950(void);
extern unsigned int func_0210e434(unsigned int);
unsigned int Maybe_helper_10ef34(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210ef3c: r0 = func_02108950();
L_210ef40: r0 = func_0210e434(r0);
L_210ef4c: return r0;
}
