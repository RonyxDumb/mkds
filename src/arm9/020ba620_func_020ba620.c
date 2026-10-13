/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int func_020ba620(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ba620: r0 = 0x217b3c8u;
L_20ba624: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20ba628: cmp_a = r0; cmp_b = 0x0u;
L_20ba62c: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8)); }
L_20ba630: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20ba634: return r0;
}
