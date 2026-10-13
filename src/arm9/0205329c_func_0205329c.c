/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020533a0(void);
unsigned int func_0205329c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20532a4: r1 = 0x217aa00u;
L_20532a8: r2 = 0x0u;
L_20532ac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20532b0: *(unsigned int *)((unsigned char *)r1 + 16) = (unsigned int)r2;
L_20532b4: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20532b8: cmp_a = r0; cmp_b = 0x0u;
L_20532c4: if ((cmp_a == cmp_b)) { return r0; }
L_20532c8: r0 = func_020533a0();
L_20532d4: return r0;
}
