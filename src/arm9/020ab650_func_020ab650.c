/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020ab650(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ab650: r1 = 0x217b2d8u;
L_20ab652: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 4));
L_20ab654: r1 = (r1&r0); cmp_a = r1; cmp_b = 0;
L_20ab656: r0 = (r1+0x0u); cmp_a = r0; cmp_b = 0;
L_20ab658: return r0;
}
