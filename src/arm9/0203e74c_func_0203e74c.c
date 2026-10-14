/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0203e788(unsigned int, unsigned int);
unsigned int func_0203e74c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_203e754: r1 = 0x21759c0u;
L_203e758: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_203e75c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_203e760: cmp_a = r1; cmp_b = 0x4u;
L_203e76c: if ((cmp_a != cmp_b)) { return r0; }
L_203e770: r1 = 0x0u;
L_203e774: r0 = func_0203e788(r0,r1);
L_203e780: return r0;
}
