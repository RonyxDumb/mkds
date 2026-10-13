/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d9340(unsigned int, unsigned int, unsigned int);
unsigned int func_020d8b88(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20d8b90: ip = r0;
L_20d8b94: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 0));
L_20d8b98: r2 = r1;
L_20d8b9c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d8ba0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 12));
L_20d8ba4: r0 = 0x54u;
L_20d8ba8: r0 = (r1*r0+r3);
L_20d8bac: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 20));
L_20d8bb0: r0 = func_020d9340(r0,r1,r2);
L_20d8bbc: return r0;
}
