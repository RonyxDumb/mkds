/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int FX_DivAsync(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int FX_GetDivResult(void);
unsigned int FX_Div(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2147f3c: r0 = FX_DivAsync(r0,r1,r2,r3);
L_2147f40: r0 = FX_GetDivResult();
L_2147f4c: return r0;
}
