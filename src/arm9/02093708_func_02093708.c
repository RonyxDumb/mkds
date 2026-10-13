/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbta_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int func_02093708(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_209370c: r1 = 0x2166720u;
L_2093710: r4 = r0;
L_2093714: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2093718: r2 = 0x217b0c8u;
L_209371c: r1 = 0x2166734u;
L_2093720: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2093724: r0 = StructMapObject_AddAnimationNsbta_from_thumb(r0,r1);
L_2093728: r0 = 0x217b0c8u;
L_209372c: r1 = 0x3fu;
L_2093730: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2093734: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2093738: r0 = 0x1u;
L_209373c: *(unsigned int *)((unsigned char *)r4 + 28) = (unsigned int)r0;
L_2093744: return r0;
}
