/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c078(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_020901f0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20901f8: r5 = r0;
L_20901fc: r4 = r1;
L_2090200: r0 = func_0207c078(r0);
L_2090204: cmp_a = r0; cmp_b = 0x0u;
L_2090208: if ((cmp_a != cmp_b)) { goto L_2090220; }
L_209020c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_2090210: cmp_a = r0; cmp_b = 0x0u;
L_209021c: if ((cmp_a == cmp_b)) { return r0; }
L_2090220: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 112));
L_2090224: cmp_a = r0; cmp_b = 0xa000u;
L_2090230: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_2090234: r0 = r5;
L_2090238: r1 = r4;
L_209023c: r0 = func_0207c614(r0,r1);
L_2090248: return r0;
}
