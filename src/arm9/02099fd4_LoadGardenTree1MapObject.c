/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadGardenTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2099fdc: r1 = 0x2167154u;
L_2099fe0: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2099fe4: r2 = 0x217b118u;
L_2099fe8: r1 = 0x3fu;
L_2099fec: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2099ff0: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2099ffc: return r0;
}
