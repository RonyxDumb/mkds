/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadKinoMount2MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20996f4: r1 = 0x216709cu;
L_20996f8: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_20996fc: r2 = 0x217b13cu;
L_2099700: r1 = 0x3fu;
L_2099704: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099708: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099714: return r0;
}
