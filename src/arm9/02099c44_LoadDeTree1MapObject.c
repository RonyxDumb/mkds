/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadDeTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099c4c: r1 = 0x216710cu;
L_2099c50: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099c54: r2 = 0x217b154u;
L_2099c58: r1 = 0x3fu;
L_2099c5c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099c60: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099c6c: return r0;
}
