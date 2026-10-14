/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadOlaTree1cMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099b68: r1 = 0x21670fcu;
L_2099b6c: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099b70: r2 = 0x217b130u;
L_2099b74: r1 = 0x3fu;
L_2099b78: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099b7c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099b88: return r0;
}
