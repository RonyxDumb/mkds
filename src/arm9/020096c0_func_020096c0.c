/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020096c0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20096c0: r1 = 0x0u; cmp_a = r1; cmp_b = 0;
L_20096c2: r0 = 0x216fc4cu;
L_20096c4: *(unsigned char *)((unsigned char *)r0 + 13) = (unsigned char)r1;
L_20096c6: *(unsigned char *)((unsigned char *)r0 + 14) = (unsigned char)r1;
L_20096c8: *(unsigned char *)((unsigned char *)r0 + 15) = (unsigned char)r1;
L_20096ca: *(unsigned char *)((unsigned char *)r0 + 16) = (unsigned char)r1;
L_20096cc: *(unsigned char *)((unsigned char *)r0 + 17) = (unsigned char)r1;
L_20096ce: return r0;
}
