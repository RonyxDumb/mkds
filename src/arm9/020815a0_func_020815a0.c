/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
unsigned int func_020815a0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20815a4: r2 = 0x217ae84u;
L_20815a8: r1 = 0x58u;
L_20815ac: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20815b0: r4 = (r0*r1+r2);
L_20815b4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 44));
L_20815b8: cmp_a = r0; cmp_b = 0x0u;
L_20815c0: if ((cmp_a == cmp_b)) { return r0; }
L_20815c4: r0 = func_0208b710(r0);
L_20815c8: r0 = 0x0u;
L_20815cc: *(unsigned int *)((unsigned char *)r4 + 44) = (unsigned int)r0;
L_20815d4: return r0;
}
