/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetLoadedNkmPathEntry_from_thumb(unsigned int);
unsigned int GetLoadedNkmPathEntryPOIT(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2042048: r4 = r1;
L_204204c: r0 = GetLoadedNkmPathEntry_from_thumb(r0);
L_2042050: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_2042054: r0 = 0x14u;
L_2042058: r0 = (r4*r0+r1);
L_2042060: return r0;
}
