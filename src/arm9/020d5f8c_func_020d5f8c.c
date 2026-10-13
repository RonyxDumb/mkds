/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d634c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020d5f8c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20d5f90: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_20d5f94: r4 = r3;
L_20d5f98: cmp_a = r1; cmp_b = 0x1u;
L_20d5f9c: if ((cmp_a != cmp_b)) { goto L_20d5fa8; }
L_20d5fa0: r1 = 0x1u;
L_20d5fa4: r0 = func_020d634c(r0,r1,r2,r3);
L_20d5fa8: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20d5fb0: return r0;
}
