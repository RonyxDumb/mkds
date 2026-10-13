/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int GetPortraitPalette_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20b4030: r1 = (r0 << 2); cmp_a = r1; cmp_b = 0;
L_20b4032: r0 = 0x217b368u;
L_20b4034: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + (0 + r1)));
L_20b4036: return r0;
}
