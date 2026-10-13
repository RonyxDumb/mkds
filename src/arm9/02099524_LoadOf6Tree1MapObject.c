/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOf6Tree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209952c: r1 = 0x216707cu;
L_2099530: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099534: r2 = 0x217b138u;
L_2099538: r1 = 0x3fu;
L_209953c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099540: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209954c: return r0;
}
