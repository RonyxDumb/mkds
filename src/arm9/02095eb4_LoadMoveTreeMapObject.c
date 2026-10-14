/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbca_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadMoveTreeMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2095ebc: r1 = 0x21668d4u;
L_2095ec0: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2095ec4: r2 = 0x217b0e8u;
L_2095ec8: r1 = 0x21668e4u;
L_2095ecc: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2095ed0: r0 = StructMapObject_AddAnimationNsbca_from_thumb(r0,r1);
L_2095ed4: r0 = 0x217b0e8u;
L_2095ed8: r1 = 0x3fu;
L_2095edc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2095ee0: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2095eec: return r0;
}
