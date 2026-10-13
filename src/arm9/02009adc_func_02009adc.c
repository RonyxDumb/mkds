/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02009adc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2009adc: r1 = 0x216fdc0u;
L_2009ade: *(unsigned short *)((unsigned char *)r1 + 6) = (unsigned short)r0;
L_2009ae0: return r0;
}
