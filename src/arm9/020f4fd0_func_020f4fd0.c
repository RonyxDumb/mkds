/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f7658(unsigned int, unsigned int);
extern unsigned int func_020f68b0(unsigned int);
unsigned int func_020f4fd0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f4fd4: r4 = r0;
L_20f4fd8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 304));
L_20f4fdc: r1 = (r1-0x1u);
L_20f4fe0: *(unsigned int *)((unsigned char *)r4 + 304) = (unsigned int)r1;
L_20f4fe4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 304));
L_20f4fe8: cmp_a = r1; cmp_b = 0x0u;
L_20f4fec: if (((int)cmp_a >= (int)cmp_b)) { goto L_20f4ff8; }
L_20f4ff0: r1 = 0x0u;
L_20f4ff4: r0 = func_020f7658(r0,r1);
L_20f4ff8: r0 = r4;
L_20f4ffc: r0 = func_020f68b0(r0);
L_20f5004: return r0;
}
