/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020789d4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20789d4: r1 = 0x1u; cmp_a = r1; cmp_b = 0;
L_20789d6: r0 = 0x217ad08u;
L_20789d8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20789da: *(unsigned int *)((unsigned char *)r0 + 84) = (unsigned int)r1;
L_20789dc: return r0;
}
