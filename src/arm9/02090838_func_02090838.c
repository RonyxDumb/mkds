/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207ffa4(unsigned int, unsigned int, unsigned int);
unsigned int func_02090838(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2090840: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_2090844: r2 = r1;
L_2090848: cmp_a = r2; cmp_b = r3;
L_2090854: if ((cmp_a == cmp_b)) { return r0; }
L_2090858: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 36));
L_209085c: r0 = func_0207ffa4(r0,r1,r2);
L_2090868: return r0;
}
