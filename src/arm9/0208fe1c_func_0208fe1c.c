/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c078(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_0208fe1c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208fe24: r5 = r0;
L_208fe28: r4 = r1;
L_208fe2c: r0 = func_0207c078(r0);
L_208fe30: cmp_a = r0; cmp_b = 0x0u;
L_208fe3c: if ((cmp_a == cmp_b)) { return r0; }
L_208fe40: r0 = r5;
L_208fe44: r1 = r4;
L_208fe48: r0 = func_0207c614(r0,r1);
L_208fe54: return r0;
}
