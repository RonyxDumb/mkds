/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212bcac(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0212c5f4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c5fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c600: cmp_a = r0; cmp_b = 0x0u;
L_212c60c: if ((cmp_a == cmp_b)) { return r0; }
L_212c610: r0 = func_0212bcac(r0,r1,r2,r3);
L_212c61c: return r0;
}
