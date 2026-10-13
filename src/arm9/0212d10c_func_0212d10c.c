/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212cbd8(unsigned int, unsigned int, unsigned int);
unsigned int func_0212d10c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212d114: r0 = 0x217ddd0u;
L_212d118: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212d11c: cmp_a = r1; cmp_b = 0x0u;
L_212d128: if ((cmp_a == cmp_b)) { return r0; }
L_212d12c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_212d130: cmp_a = r0; cmp_b = 0x1u;
L_212d13c: if ((cmp_a != cmp_b)) { return r0; }
L_212d140: r0 = func_0212cbd8(r0,r1,r2);
L_212d14c: return r0;
}
