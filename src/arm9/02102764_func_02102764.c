/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020fecdc(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020fe8ac(unsigned int);
unsigned int func_02102764(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_210276c: r5 = r1;
L_2102770: r4 = r2;
L_2102774: r0 = func_020fecdc(r0,r1,r2);
L_2102778: cmp_a = r5; cmp_b = 0x0u;
L_2102784: if ((cmp_a == cmp_b)) { return r0; }
L_2102788: cmp_a = r4; cmp_b = 0x0u;
L_2102794: if ((cmp_a == cmp_b)) { return r0; }
L_2102798: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 68));
L_210279c: r0 = func_020fe8ac(r0);
L_21027a8: return r0;
}
