/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02028dd4(void);
extern unsigned int func_02028db8(unsigned int);
unsigned int Maybe_helper_028d9c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2028da4: r0 = func_02028dd4();
L_2028da8: r0 = func_02028db8(r0);
L_2028db4: return r0;
}
