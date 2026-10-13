/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c078(unsigned int);
extern unsigned int func_0207c6d0(unsigned int, unsigned int);
unsigned int func_0208fdcc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_208fdd4: r5 = r0;
L_208fdd8: r4 = r1;
L_208fddc: r0 = func_0207c078(r0);
L_208fde0: cmp_a = r0; cmp_b = 0x0u;
L_208fdec: if ((cmp_a == cmp_b)) { return r0; }
L_208fdf0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 112));
L_208fdf4: cmp_a = r0; cmp_b = 0xa000u;
L_208fe00: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_208fe04: r0 = r5;
L_208fe08: r1 = r4;
L_208fe0c: r0 = func_0207c6d0(r0,r1);
L_208fe18: return r0;
}
