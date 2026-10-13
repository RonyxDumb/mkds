/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModelAndAnimation_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadCrabMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_209b200: r1 = 0x2167228u;
L_209b204: r2 = 0x2167234u;
L_209b208: r4 = r0;
L_209b20c: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_209b210: r2 = 0x217b178u;
L_209b214: r1 = 0x2167240u;
L_209b218: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209b21c: r2 = 0x2167250u;
L_209b220: r0 = r4;
L_209b224: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_209b228: r2 = 0x217b174u;
L_209b22c: r1 = 0x217b178u;
L_209b230: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209b234: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_209b238: r1 = 0x3fu;
L_209b23c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209b240: r0 = 0x217b174u;
L_209b244: r1 = 0x3fu;
L_209b248: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_209b24c: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209b254: return r0;
}
