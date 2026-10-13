/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int TextSystem_JustFadedIn_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2125f6c: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2125f6e: r1 = 0x217d3f0u;
L_2125f70: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2125f72: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 8));
L_2125f74: cmp_a = r1; cmp_b = 0x1u;
L_2125f76: if ((cmp_a != cmp_b)) { goto L_2125f80; }
L_2125f78: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2125f7a: cmp_a = r1; cmp_b = 0x2u;
L_2125f7c: if ((cmp_a != cmp_b)) { goto L_2125f80; }
L_2125f7e: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_2125f80: return r0;
}
