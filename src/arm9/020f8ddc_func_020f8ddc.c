/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int func_020f8ddc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f8de0: r4 = r0; cmp_a = r4; cmp_b = 0;
L_20f8de8: if ((cmp_a == cmp_b)) { return r0; }
L_20f8dec: r0 = 0x21759c0u;
L_20f8df0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20f8df4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20f8df8: cmp_a = r0; cmp_b = 0x4u;
L_20f8e00: if ((cmp_a != cmp_b)) { return r0; }
L_20f8e04: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_20f8e08: cmp_a = r0; cmp_b = 0x1u;
L_20f8e10: if ((cmp_a > cmp_b)) { return r0; }
L_20f8e14: r0 = 0x441u;
L_20f8e18: r1 = (r4+0x50u);
L_20f8e1c: r0 = func_0208b7bc(r0,r1);
L_20f8e20: r1 = (r4+0x50u);
L_20f8e24: r0 = 0x440u;
L_20f8e28: r0 = func_0208b7bc(r0,r1);
L_20f8e30: return r0;
}
