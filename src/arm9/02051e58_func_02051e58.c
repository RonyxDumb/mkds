/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020533a0(void);
unsigned int func_02051e58(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2051e60: r1 = 0x217aa00u;
L_2051e64: r2 = 0x0u;
L_2051e68: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2051e6c: *(unsigned int *)((unsigned char *)r1 + 16) = (unsigned int)r2;
L_2051e70: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 2));
L_2051e74: cmp_a = r0; cmp_b = 0x0u;
L_2051e80: if ((cmp_a == cmp_b)) { return r0; }
L_2051e84: r0 = func_020533a0();
L_2051e90: return r0;
}
