/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ddaa0(unsigned int, unsigned int);
extern unsigned int func_020dda38(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020de270(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,stack_0;
L_20de278: r0 = 0x217b6e8u;
L_20de27c: r6 = r1;
L_20de280: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20de284: r0 = (r6+0xa4u);
L_20de288: r5 = r2;
L_20de28c: r4 = r3;
L_20de290: r0 = func_020ddaa0(r0,r1);
L_20de294: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 244));
L_20de298: cmp_a = r0; cmp_b = 0x0u;
L_20de2a4: if ((cmp_a == cmp_b)) { return r0; }
L_20de2a8: r0 = 0x217b6e4u;
L_20de2ac: stack_0 = r4;
L_20de2b0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20de2b4: r3 = r5;
L_20de2b8: r0 = (r6+0xa4u);
L_20de2bc: r2 = (r6+0x4u);
L_20de2c0: r0 = func_020dda38(r0,r1,r2,r3,stack_0);
L_20de2cc: return r0;
}
