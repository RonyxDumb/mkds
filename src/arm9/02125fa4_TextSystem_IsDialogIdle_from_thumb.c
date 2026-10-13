/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int TextSystem_IsDialogIdle_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2125fa4: r0 = 0x0u; cmp_a = r0; cmp_b = 0;
L_2125fa6: r1 = 0x217d3f0u;
L_2125fa8: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2125faa: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2125fac: cmp_a = r1; cmp_b = 0x2u;
L_2125fae: if ((cmp_a != cmp_b)) { goto L_2125fb8; }
L_2125fb0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 56));
L_2125fb2: cmp_a = r1; cmp_b = 0x0u;
L_2125fb4: if ((cmp_a != cmp_b)) { goto L_2125fb8; }
L_2125fb6: r0 = 0x1u; cmp_a = r0; cmp_b = 0;
L_2125fb8: return r0;
}
