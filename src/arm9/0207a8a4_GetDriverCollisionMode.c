/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetDriverCollisionMode(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_207a8a4: r2 = 0x217ad18u;
L_207a8a8: r1 = 0x5a8u;
L_207a8ac: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_207a8b0: r1 = (r0*r1+r2);
L_207a8b4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 668));
L_207a8b8: return r0;
}
