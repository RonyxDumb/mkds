/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020533a0(void);
unsigned int func_020517d4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20517dc: r1 = 0x217aa00u;
L_20517e0: r2 = 0x0u;
L_20517e4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20517e8: *(unsigned int *)((unsigned char *)r1 + 16) = (unsigned int)r2;
L_20517ec: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_20517f0: cmp_a = r0; cmp_b = 0x0u;
L_20517fc: if ((cmp_a == cmp_b)) { return r0; }
L_2051800: r0 = func_020533a0();
L_205180c: return r0;
}
