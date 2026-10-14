/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ed5c0(unsigned int, unsigned int, unsigned int);
unsigned int func_020f5008(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20f5010: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 308));
L_20f5014: ip = r1;
L_20f5018: cmp_a = r3; cmp_b = 0x0u;
L_20f5024: if ((cmp_a == cmp_b)) { return r0; }
L_20f5028: r1 = r2;
L_20f502c: r2 = ip;
L_20f5030: r0 = func_020ed5c0(r0,r1,r2);
L_20f503c: return r0;
}
