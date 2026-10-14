/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d91dc(unsigned int, unsigned int, unsigned int);
unsigned int func_020d8bc0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20d8bc8: ip = r0;
L_20d8bcc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 0));
L_20d8bd0: r2 = r1;
L_20d8bd4: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20d8bd8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 12));
L_20d8bdc: r0 = 0x54u;
L_20d8be0: r0 = (r1*r0+r3);
L_20d8be4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)ip + 20));
L_20d8be8: r0 = func_020d91dc(r0,r1,r2);
L_20d8bf4: return r0;
}
