/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int IncreaseMDCounter(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2021764: r2 = 0x2174da0u;
L_2021768: r1 = 0xcu;
L_202176c: r1 = (r0*r1+r2);
L_2021770: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r1 + 8));
L_2021774: r0 = (r0+0x1u);
L_2021778: *(unsigned char *)((unsigned char *)r1 + 8) = (unsigned char)r0;
L_202177c: return r0;
}
