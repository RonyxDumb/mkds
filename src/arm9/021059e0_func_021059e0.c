/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210d5c0(unsigned int);
unsigned int func_021059e0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_21059e8: r0 = 0x217d070u;
L_21059ec: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_21059f0: cmp_a = r1; cmp_b = 0x0u;
L_21059fc: if ((cmp_a != cmp_b)) { return r0; }
L_2105a00: r1 = 0x217c838u;
L_2105a04: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 4));
L_2105a08: cmp_a = r1; cmp_b = 0x0u;
L_2105a14: if ((cmp_a != cmp_b)) { return r0; }
L_2105a18: r0 = func_0210d5c0(r0);
L_2105a24: return r0;
}
