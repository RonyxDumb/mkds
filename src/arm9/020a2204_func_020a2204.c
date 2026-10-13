/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020a2204(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a2204: r2 = 0x217b1fcu;
L_20a2208: r1 = 0x70u;
L_20a220c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_20a2210: r1 = (r0*r1+r2);
L_20a2214: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 108));
L_20a2218: return r0;
}
