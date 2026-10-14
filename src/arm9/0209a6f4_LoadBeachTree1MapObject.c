/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadBeachTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a6fc: r1 = 0x21671e0u;
L_209a700: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a704: r2 = 0x217b150u;
L_209a708: r1 = 0x3fu;
L_209a70c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a710: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a71c: return r0;
}
