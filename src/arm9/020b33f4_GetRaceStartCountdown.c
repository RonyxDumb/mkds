/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetRaceStartCountdown(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20b33f4: r0 = 0x217b358u;
L_20b33f8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20b33fc: cmp_a = r0; cmp_b = 0x0u;
L_20b3400: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8)); }
L_20b3404: if ((cmp_a == cmp_b)) { r0 = ~(0x77u); }
L_20b3408: return r0;
}
