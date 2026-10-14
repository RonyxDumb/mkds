/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOlgPipe1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a450: r1 = 0x21671b0u;
L_209a454: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a458: r2 = 0x217b14cu;
L_209a45c: r1 = 0x3fu;
L_209a460: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a464: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a470: return r0;
}
