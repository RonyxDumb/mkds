/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int TextSystem_IsDialogFinished_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2125f88: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2125f8a: r1 = 0x217d3f0u;
L_2125f8c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2125f8e: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2125f90: cmp_a = r1; cmp_b = 0x0u;
L_2125f92: if ((cmp_a != cmp_b)) { goto L_2125f9c; }
L_2125f94: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 52));
L_2125f96: cmp_a = r1; cmp_b = 0x0u;
L_2125f98: if ((cmp_a != cmp_b)) { goto L_2125f9c; }
L_2125f9a: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_2125f9c: return r0;
}
