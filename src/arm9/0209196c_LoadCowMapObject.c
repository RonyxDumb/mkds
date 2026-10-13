/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModelAndAnimation_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadCowMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2091974: r1 = 0x21665f8u;
L_2091978: r2 = 0x2166604u;
L_209197c: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_2091980: r2 = 0x217b0bcu;
L_2091984: r1 = 0x3fu;
L_2091988: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209198c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2091998: return r0;
}
