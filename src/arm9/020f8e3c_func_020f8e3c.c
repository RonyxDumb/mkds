/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020719bc(unsigned int, unsigned int);
unsigned int func_020f8e3c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f8e44: cmp_a = r0; cmp_b = 0x0u;
L_20f8e50: if ((cmp_a == cmp_b)) { return r0; }
L_20f8e54: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 124));
L_20f8e58: r2 = (r2&0x1u); cmp_a = r2; cmp_b = 0;
L_20f8e64: if ((cmp_a == cmp_b)) { return r0; }
L_20f8e68: r0 = func_020719bc(r0,r1);
L_20f8e74: return r0;
}
