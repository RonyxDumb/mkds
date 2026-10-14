/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOpaTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a618: r1 = 0x21671d0u;
L_209a61c: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a620: r2 = 0x217b140u;
L_209a624: r1 = 0x3fu;
L_209a628: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a62c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a638: return r0;
}
