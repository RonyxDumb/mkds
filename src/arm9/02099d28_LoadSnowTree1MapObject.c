/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadSnowTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099d30: r1 = 0x216711cu;
L_2099d34: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099d38: r2 = 0x217b168u;
L_2099d3c: r1 = 0x3fu;
L_2099d40: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099d44: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099d50: return r0;
}
