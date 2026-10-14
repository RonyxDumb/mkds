/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOsaTree1cMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099a84: r1 = 0x21670ecu;
L_2099a88: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099a8c: r2 = 0x217b12cu;
L_2099a90: r1 = 0x3fu;
L_2099a94: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099a98: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099aa4: return r0;
}
