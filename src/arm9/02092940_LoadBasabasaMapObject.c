/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModelAndAnimation_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadBasabasaMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2092948: r1 = 0x2166698u;
L_209294c: r2 = 0x21666a8u;
L_2092950: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_2092954: r2 = 0x217b0c4u;
L_2092958: r1 = 0x3fu;
L_209295c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2092960: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209296c: return r0;
}
