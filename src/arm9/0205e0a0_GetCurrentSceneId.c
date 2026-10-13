/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int GetCurrentSceneId(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_205e0a0: r0 = 0x21653b8u;
L_205e0a4: r0 = (unsigned int)(*(short *)((unsigned char *)r0 + 2));
L_205e0a8: return r0;
}
