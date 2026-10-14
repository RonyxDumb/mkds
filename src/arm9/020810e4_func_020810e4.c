/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
unsigned int func_020810e4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20810e8: r2 = 0x217ae84u;
L_20810ec: r1 = 0x58u;
L_20810f0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20810f4: r4 = (r0*r1+r2);
L_20810f8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 48));
L_20810fc: cmp_a = r0; cmp_b = 0x0u;
L_2081104: if ((cmp_a == cmp_b)) { return r0; }
L_2081108: r0 = func_0208b710(r0);
L_208110c: r0 = 0x0u;
L_2081110: *(unsigned int *)((unsigned char *)r4 + 48) = (unsigned int)r0;
L_2081118: return r0;
}
