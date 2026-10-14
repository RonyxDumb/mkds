/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020c94(unsigned int, unsigned int, unsigned int);
unsigned int func_0212c4c4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c4cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c4d0: cmp_a = r0; cmp_b = 0x0u;
L_212c4dc: if ((cmp_a == cmp_b)) { return r0; }
L_212c4e0: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c4e4: r0 = func_02020c94(r0,r1,r2);
L_212c4f0: return r0;
}
