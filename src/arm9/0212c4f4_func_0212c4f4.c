/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020cbc(unsigned int, unsigned int, unsigned int);
unsigned int func_0212c4f4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c4fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c500: cmp_a = r0; cmp_b = 0x0u;
L_212c50c: if ((cmp_a == cmp_b)) { return r0; }
L_212c510: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c514: r0 = func_02020cbc(r0,r1,r2);
L_212c520: return r0;
}
