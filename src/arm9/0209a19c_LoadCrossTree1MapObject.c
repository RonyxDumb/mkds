/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadCrossTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a1a4: r1 = 0x216717cu;
L_209a1a8: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a1ac: r2 = 0x217b11cu;
L_209a1b0: r1 = 0x3fu;
L_209a1b4: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a1b8: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a1c4: return r0;
}
