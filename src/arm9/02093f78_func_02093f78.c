/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
unsigned int func_02093f78(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2093f80: r1 = 0x21667b0u;
L_2093f84: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2093f88: r1 = 0x217b0d4u;
L_2093f8c: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2093f98: return r0;
}
