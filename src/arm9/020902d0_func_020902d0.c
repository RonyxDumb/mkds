/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_020902d0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20902d8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 176));
L_20902dc: cmp_a = r2; cmp_b = 0x0u;
L_20902e8: if ((cmp_a == cmp_b)) { return r0; }
L_20902ec: r0 = func_0207c614(r0,r1);
L_20902f8: return r0;
}
