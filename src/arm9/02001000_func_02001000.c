/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02050320(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020515b0(unsigned int);
unsigned int func_02001000(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2001004: r0 = 0x217aa00u;
L_2001008: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_200100c: r4 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 138));
L_2001010: cmp_a = r4; cmp_b = 0x0u;
L_2001018: if ((cmp_a == cmp_b)) { return r0; }
L_200101c: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 135));
L_2001020: r2 = r4;
L_2001024: r0 = 0x7u;
L_2001028: r0 = func_02050320(r0,r1,r2);
L_200102c: cmp_a = r0; cmp_b = 0x0u;
L_2001034: if ((cmp_a == cmp_b)) { return r0; }
L_2001038: r0 = r4;
L_200103c: r0 = func_020515b0(r0);
L_2001044: return r0;
}
