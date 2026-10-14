/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int VecFx32_Subtract(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0208eb10(unsigned int);
extern unsigned int func_020fe71c(unsigned int, unsigned int, unsigned int);
unsigned int func_020fba6c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20fba70: r4 = r0;
L_20fba74: r0 = 0x5000u;
L_20fba78: *(unsigned int *)((unsigned char *)r4 + 612) = (unsigned int)r0;
L_20fba7c: r0 = (r4+0x200u);
L_20fba80: r1 = 0x3e8u;
L_20fba84: *(unsigned short *)((unsigned char *)r0 + 136) = (unsigned short)r1;
L_20fba88: r0 = (r4+0x238u);
L_20fba8c: r1 = (r4+0x298u);
L_20fba90: r2 = (r4+0x28cu);
L_20fba94: r0 = VecFx32_Subtract(r0,r1,r2);
L_20fba98: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 620));
L_20fba9c: cmp_a = r0; cmp_b = 0x0u;
L_20fbaa0: if ((cmp_a == cmp_b)) { goto L_20fbab0; }
L_20fbaa4: r0 = func_0208eb10(r0);
L_20fbaa8: r0 = 0x0u;
L_20fbaac: *(unsigned int *)((unsigned char *)r4 + 620) = (unsigned int)r0;
L_20fbab0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20fbab4: r0 = (r0&0x8000000u); cmp_a = r0; cmp_b = 0;
L_20fbabc: if ((cmp_a == cmp_b)) { return r0; }
L_20fbac0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 552));
L_20fbac4: r2 = (unsigned int)(*(short *)((unsigned char *)r4 + 78));
L_20fbac8: r0 = (r0+0x100u);
L_20fbacc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 248));
L_20fbad0: r0 = 0x5u;
L_20fbad4: r0 = func_020fe71c(r0,r1,r2);
L_20fbadc: return r0;
}
