/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Fs_OverlayInfo_End(unsigned int);
unsigned int Fs_OverlayInfo_UnloadImage(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20051fc: r0 = Fs_OverlayInfo_End(r0);
L_2005200: r0 = 0x1u;
L_200520c: return r0;
}
