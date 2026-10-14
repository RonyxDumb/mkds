/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DC_InvalidateRangeNoClean(unsigned int, unsigned int);
unsigned int func_02021834(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_202183c: r0 = 0x2174e00u;
L_2021840: r1 = 0x4u;
L_2021844: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2021848: r0 = DC_InvalidateRangeNoClean(r0,r1);
L_202184c: r0 = 0x2174e00u;
L_2021850: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2021854: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2021860: return r0;
}
