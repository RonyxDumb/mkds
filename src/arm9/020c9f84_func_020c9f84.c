/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020c0b84(unsigned int);
unsigned int func_020c9f84(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c9f8c: r0 = 0x217b428u;
L_20c9f90: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c9f94: r0 = (r0+0x190u);
L_20c9f98: r0 = func_020c0b84(r0);
L_20c9f9c: r0 = 0x217b428u;
L_20c9fa0: r1 = 0x0u;
L_20c9fa4: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20c9fb0: return r0;
}
