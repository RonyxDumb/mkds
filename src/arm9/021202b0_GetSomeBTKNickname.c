/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetSomeBTKNickname(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21202b0: r2 = 0x217d384u;
L_21202b4: r1 = 0x244u;
L_21202b8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_21202bc: r2 = (r2+0x228u);
L_21202c0: r0 = (r1*r0+r2);
L_21202c4: return r0;
}
