/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOlgMush1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a534: r1 = 0x21671c0u;
L_209a538: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a53c: r2 = 0x217b16cu;
L_209a540: r1 = 0x3fu;
L_209a544: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a548: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a554: return r0;
}
