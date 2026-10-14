/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadNsCannon1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a288: r1 = 0x2167190u;
L_209a28c: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a290: r2 = 0x217b170u;
L_209a294: r1 = 0x3fu;
L_209a298: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a29c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a2a8: return r0;
}
