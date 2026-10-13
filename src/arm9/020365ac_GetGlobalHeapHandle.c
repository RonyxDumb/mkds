/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int GetGlobalHeapHandle(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20365ac: r0 = 0x2174e78u;
L_20365b0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_20365b4: return r0;
}
