/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d2398(unsigned int);
unsigned int func_02094df4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2094dfc: r0 = func_020d2398(r0);
L_2094e00: r0 = 0x217b0d8u;
L_2094e04: r1 = 0x0u;
L_2094e08: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_2094e14: return r0;
}
