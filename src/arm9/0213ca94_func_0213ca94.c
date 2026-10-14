/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0213c9e8(unsigned int, unsigned int, unsigned int);
unsigned int func_0213ca94(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_213ca9c: r4 = r0;
L_213caa0: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 8));
L_213caa4: r5 = r2;
L_213caa8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_213caac: r0 = (r3+r5);
L_213cab0: cmp_a = r0; cmp_b = r2;
L_213cab4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_213cab8: if ((cmp_a > cmp_b)) { r5 = (r2-r3); }
L_213cabc: r2 = r5;
L_213cac0: r0 = (r0+(r3 << 1));
L_213cac4: r0 = func_0213c9e8(r0,r1,r2);
L_213cac8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 8));
L_213cacc: r1 = (r1+r5);
L_213cad0: *(unsigned int *)((unsigned char *)r4 + 8) = (unsigned int)r1;
L_213cadc: return r0;
}
