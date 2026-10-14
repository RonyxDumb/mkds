/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020ce4(unsigned int, unsigned int, unsigned int);
unsigned int func_0212c524(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c52c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c530: cmp_a = r0; cmp_b = 0x0u;
L_212c53c: if ((cmp_a == cmp_b)) { return r0; }
L_212c540: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c544: r0 = func_02020ce4(r0,r1,r2);
L_212c550: return r0;
}
