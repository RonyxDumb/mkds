/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetHeyhoColorPaletteDataForRacer_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2077f7c: r3 = 0x0u; cmp_a = r3; cmp_b = 0;
L_2077f7e: r1 = 0x217ad00u;
L_2077f80: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2077f82: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 20));
L_2077f84: cmp_a = r2; cmp_b = 0x0u;
L_2077f86: if ((cmp_a == cmp_b)) { goto L_2077f94; }
L_2077f88: r0 = (r0 << 1); cmp_a = r0; cmp_b = 0;
L_2077f8a: r1 = (r1+r0); cmp_a = r1; cmp_b = 0;
L_2077f8c: r0 = 0x18u; cmp_a = r0; cmp_b = 0;
L_2077f8e: r0 = (unsigned int)(*(short *)((unsigned char *)r1 + (0 + r0)));
L_2077f90: r0 = (r0 << 5); cmp_a = r0; cmp_b = 0;
L_2077f92: r3 = (r2+r0); cmp_a = r3; cmp_b = 0;
L_2077f94: r0 = (r3+0x0u); cmp_a = r0; cmp_b = 0;
L_2077f96: return r0;
}
