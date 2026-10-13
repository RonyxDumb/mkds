/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_02128274(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2128274: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2128276: r1 = 0x217d3f8u;
L_2128278: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_212827a: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 4));
L_212827c: cmp_a = r1; cmp_b = 0x0u;
L_212827e: if ((cmp_a != cmp_b)) { goto L_212828a; }
L_2128280: r1 = 0x810u;
L_2128282: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + (0 + r1)));
L_2128284: cmp_a = r1; cmp_b = 0x0u;
L_2128286: if ((cmp_a != cmp_b)) { goto L_212828a; }
L_2128288: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_212828a: return r0;
}
