/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int FX_InvAsync(unsigned int);
extern unsigned int FX_GetDivResult(void);
unsigned int FX_Inv(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2147f20: r0 = FX_InvAsync(r0);
L_2147f24: r0 = FX_GetDivResult();
L_2147f30: return r0;
}
