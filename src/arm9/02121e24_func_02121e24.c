/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02121e24(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2121e24: r2 = 0x217d384u;
L_2121e28: r1 = 0x44u;
L_2121e2c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2121e30: r1 = (r0*r1+r2);
L_2121e34: r0 = (r1+0x1000u);
L_2121e38: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 3656));
L_2121e3c: return r0;
}
