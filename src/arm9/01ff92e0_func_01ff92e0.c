/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_01ff92e0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_1ff92e0: r1 = 0x2173204u;
L_1ff92e4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_1ff92e8: cmp_a = r2; cmp_b = 0x0u;
L_1ff92ec: if ((cmp_a == cmp_b)) { r2 = 0x0u; }
L_1ff92f0: if ((cmp_a == cmp_b)) { *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r2; }
L_1ff92f4: if ((cmp_a == cmp_b)) { *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0; }
L_1ff92f8: return r0;
}
