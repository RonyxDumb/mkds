/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02121e64(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2121e64: r2 = 0x217d384u;
L_2121e68: r1 = 0x44u;
L_2121e6c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2121e70: r1 = (r0*r1+r2);
L_2121e74: r0 = (r1+0x1000u);
L_2121e78: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 3648));
L_2121e7c: return r0;
}
