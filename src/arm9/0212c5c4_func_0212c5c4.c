/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020d68(unsigned int, unsigned int);
unsigned int func_0212c5c4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c5cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c5d0: cmp_a = r0; cmp_b = 0x0u;
L_212c5dc: if ((cmp_a == cmp_b)) { return r0; }
L_212c5e0: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c5e4: r0 = func_02020d68(r0,r1);
L_212c5f0: return r0;
}
