/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadBankEgg1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099448: r1 = 0x216706cu;
L_209944c: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099450: r2 = 0x217b164u;
L_2099454: r1 = 0x3fu;
L_2099458: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209945c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099468: return r0;
}
