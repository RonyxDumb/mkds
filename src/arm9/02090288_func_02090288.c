/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c078(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_02090288(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2090290: r5 = r0;
L_2090294: r4 = r1;
L_2090298: r0 = func_0207c078(r0);
L_209029c: cmp_a = r0; cmp_b = 0x0u;
L_20902a0: if ((cmp_a != cmp_b)) { goto L_20902b8; }
L_20902a4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 176));
L_20902a8: cmp_a = r0; cmp_b = 0x0u;
L_20902b4: if ((cmp_a == cmp_b)) { return r0; }
L_20902b8: r0 = r5;
L_20902bc: r1 = r4;
L_20902c0: r0 = func_0207c614(r0,r1);
L_20902cc: return r0;
}
