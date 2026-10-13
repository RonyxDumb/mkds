/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadTownTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099ef8: r1 = 0x2167144u;
L_2099efc: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099f00: r2 = 0x217b124u;
L_2099f04: r1 = 0x3fu;
L_2099f08: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099f0c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099f18: return r0;
}
