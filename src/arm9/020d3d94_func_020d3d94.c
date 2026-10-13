/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_020d3d94(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20d3d94: r1 = 0x217b4e4u;
L_20d3d98: r0 = 0x0u;
L_20d3d9c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20d3da0: cmp_a = r1; cmp_b = 0x0u;
L_20d3da4: if ((cmp_a == cmp_b)) { return r0; }
L_20d3da8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 368));
L_20d3dac: cmp_a = r1; cmp_b = 0x0u;
L_20d3db0: if ((cmp_a != cmp_b)) { r0 = 0x1u; }
L_20d3db4: return r0;
}
