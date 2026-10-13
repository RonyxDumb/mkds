/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020cb51c(unsigned int);
extern unsigned int func_020cb4c0(void);
unsigned int Scene_Menu_Update(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2039f3c: r0 = func_020cb51c(r0);
L_2039f40: r0 = func_020cb4c0();
L_2039f4c: return r0;
}
