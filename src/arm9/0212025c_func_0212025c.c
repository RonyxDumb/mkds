/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_0212025c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212025c: r2 = 0x217d384u;
L_2120260: r1 = 0x244u;
L_2120264: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2120268: r1 = (r0*r1+r2);
L_212026c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 1108));
L_2120270: return r0;
}
