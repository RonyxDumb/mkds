/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020ab640(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ab640: r1 = 0x217b2d8u;
L_20ab642: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 6));
L_20ab644: r1 = (r1&r0); cmp_a = r1; cmp_b = 0;
L_20ab646: r0 = (r1+0x0u); cmp_a = r0; cmp_b = 0;
L_20ab648: return r0;
}
