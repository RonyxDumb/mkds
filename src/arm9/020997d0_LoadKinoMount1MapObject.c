/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadKinoMount1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20997d8: r1 = 0x21670b0u;
L_20997dc: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_20997e0: r2 = 0x217b120u;
L_20997e4: r1 = 0x3fu;
L_20997e8: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_20997ec: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_20997f8: return r0;
}
