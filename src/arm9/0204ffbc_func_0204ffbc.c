/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0204ffbc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_204ffbc: r1 = 0x217aa00u;
L_204ffc0: r0 = 0x0u;
L_204ffc4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_204ffc8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 4));
L_204ffcc: cmp_a = r1; cmp_b = 0x8u;
L_204ffd0: if ((cmp_a == cmp_b)) { goto L_204ffdc; }
L_204ffd4: cmp_a = r1; cmp_b = 0x9u;
L_204ffd8: if ((cmp_a != cmp_b)) { return r0; }
L_204ffdc: r0 = 0x1u;
L_204ffe0: return r0;
}
