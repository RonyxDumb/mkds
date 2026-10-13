/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadKinoHouse1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20999a0: r1 = 0x21670d8u;
L_20999a4: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_20999a8: r2 = 0x217b148u;
L_20999ac: r1 = 0x3fu;
L_20999b0: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_20999b4: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_20999c0: return r0;
}
