/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetDriverEntry(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_207a974: r2 = 0x217ad18u;
L_207a978: r1 = 0x5a8u;
L_207a97c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_207a980: r0 = (r1*r0+r2);
L_207a984: return r0;
}
