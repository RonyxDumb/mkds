/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d9480(unsigned int, unsigned int, unsigned int);
unsigned int func_020d8c74(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20d8c7c: ip = r0;
L_20d8c80: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 0));
L_20d8c84: r2 = r1;
L_20d8c88: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d8c8c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 12));
L_20d8c90: r0 = 0x54u;
L_20d8c94: r0 = (r1*r0+r3);
L_20d8c98: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 20));
L_20d8c9c: r0 = func_020d9480(r0,r1,r2);
L_20d8ca8: return r0;
}
