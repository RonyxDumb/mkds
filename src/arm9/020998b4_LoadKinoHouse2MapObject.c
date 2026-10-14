/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadKinoHouse2MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20998bc: r1 = 0x21670c4u;
L_20998c0: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_20998c4: r2 = 0x217b128u;
L_20998c8: r1 = 0x3fu;
L_20998cc: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_20998d0: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_20998dc: return r0;
}
