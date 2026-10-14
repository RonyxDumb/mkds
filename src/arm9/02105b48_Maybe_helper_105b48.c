/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210d960(void);
extern unsigned int func_0212c6ac(unsigned int);
unsigned int Maybe_helper_105b48(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2105b50: r0 = func_0210d960();
L_2105b54: r0 = func_0212c6ac(r0);
L_2105b60: return r0;
}
