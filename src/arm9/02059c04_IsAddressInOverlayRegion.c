/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int IsAddressInOverlayRegion(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2059c04: r1 = 0x217aa10u;
L_2059c08: r3 = 0x0u;
L_2059c0c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2059c10: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 168));
L_2059c14: cmp_a = r0; cmp_b = r1;
L_2059c18: if ((cmp_a < cmp_b)) { goto L_2059c28; }
L_2059c1c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 172));
L_2059c20: cmp_a = r0; cmp_b = r1;
L_2059c24: if ((cmp_a <= cmp_b)) { r3 = 0x1u; }
L_2059c28: r0 = r3;
L_2059c2c: return r0;
}
