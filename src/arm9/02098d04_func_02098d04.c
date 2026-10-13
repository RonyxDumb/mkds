/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbca_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_SomeFn_6(unsigned int, unsigned int);
unsigned int func_02098d04(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2098d0c: r1 = 0x2166a18u;
L_2098d10: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2098d14: r2 = 0x217b100u;
L_2098d18: r1 = 0x2166a2cu;
L_2098d1c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2098d20: r0 = StructMapObject_AddAnimationNsbca_from_thumb(r0,r1);
L_2098d24: r0 = 0x217b100u;
L_2098d28: r1 = 0x1fu;
L_2098d2c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2098d30: r0 = StructMapObject_SomeFn_6(r0,r1);
L_2098d3c: return r0;
}
