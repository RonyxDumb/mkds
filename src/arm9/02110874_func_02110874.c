/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_021108bc(unsigned int);
unsigned int func_02110874(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_211087c: r0 = 0x217d1f4u;
L_2110880: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2110884: cmp_a = r0; cmp_b = 0x7u;
L_2110888: if ((cmp_a == cmp_b)) { r0 = 0x6u; }
L_211088c: r0 = func_021108bc(r0);
L_2110890: r0 = 0x217d1f4u;
L_2110894: r1 = 0x7u;
L_2110898: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_21108a4: return r0;
}
