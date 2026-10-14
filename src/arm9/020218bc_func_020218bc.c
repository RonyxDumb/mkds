/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DC_InvalidateRangeNoClean(unsigned int, unsigned int);
unsigned int func_020218bc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20218c4: r0 = 0x2174e00u;
L_20218c8: r1 = 0x4u;
L_20218cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20218d0: r0 = (r0+0x4u);
L_20218d4: r0 = DC_InvalidateRangeNoClean(r0,r1);
L_20218d8: r0 = 0x2174e00u;
L_20218dc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20218e0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_20218ec: return r0;
}
