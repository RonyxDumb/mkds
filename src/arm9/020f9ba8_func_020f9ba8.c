/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f7658(unsigned int, unsigned int);
unsigned int func_020f9ba8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20f9bb0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 284));
L_20f9bb4: cmp_a = r1; cmp_b = 0x12cu;
L_20f9bc0: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_20f9bc4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 116));
L_20f9bc8: r1 = (r1&0x8000u); cmp_a = r1; cmp_b = 0;
L_20f9bd4: if ((cmp_a == cmp_b)) { return r0; }
L_20f9bd8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 288));
L_20f9bdc: r1 = 0x20f68b0u;
L_20f9be0: cmp_a = r2; cmp_b = r1;
L_20f9bec: if ((cmp_a != cmp_b)) { return r0; }
L_20f9bf0: r1 = 0x1u;
L_20f9bf4: r0 = func_020f7658(r0,r1);
L_20f9c00: return r0;
}
