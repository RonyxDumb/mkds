/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int IsRaceCountdownEnded(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20b33d8: r0 = 0x217b358u;
L_20b33dc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20b33e0: cmp_a = r0; cmp_b = 0x0u;
L_20b33e4: if ((cmp_a != cmp_b)) { r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4)); }
L_20b33e8: if ((cmp_a == cmp_b)) { r0 = 0x0u; }
L_20b33ec: return r0;
}
