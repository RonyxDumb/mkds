/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020c7148(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20c7148: r0 = 0x217b3f4u;
L_20c714c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20c7150: cmp_a = r0; cmp_b = 0x0u;
L_20c7154: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8)); }
L_20c7158: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20c715c: return r0;
}
