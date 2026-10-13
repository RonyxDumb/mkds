/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020df3f8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20df3f8: r1 = 0x0u; cmp_a = r1; cmp_b = 0;
L_20df3fa: r0 = 0x217b750u;
L_20df3fc: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_20df3fe: r0 = 0x217b754u;
L_20df400: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20df402: r1 = 0x1000u;
L_20df404: r0 = 0x217b75cu;
L_20df406: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20df408: r0 = 0x217b760u;
L_20df40a: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_20df40c: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r1;
L_20df40e: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r1;
L_20df410: return r0;
}
