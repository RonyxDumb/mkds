/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadMiniDokanMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099364: r1 = 0x2167058u;
L_2099368: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209936c: r2 = 0x217b160u;
L_2099370: r1 = 0x3fu;
L_2099374: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099378: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099384: return r0;
}
