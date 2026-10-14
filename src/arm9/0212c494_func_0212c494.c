/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020d98(unsigned int, unsigned int);
unsigned int func_0212c494(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c49c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c4a0: cmp_a = r0; cmp_b = 0x0u;
L_212c4ac: if ((cmp_a == cmp_b)) { return r0; }
L_212c4b0: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c4b4: r0 = func_02020d98(r0,r1);
L_212c4c0: return r0;
}
