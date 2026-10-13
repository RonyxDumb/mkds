/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_0212b7fc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212b7fc: r1 = 0x0u; cmp_a = r1; cmp_b = 0;
L_212b7fe: r0 = 0x217d410u;
L_212b800: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212b802: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_212b804: return r0;
}
