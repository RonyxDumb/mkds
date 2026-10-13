/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadBankTree1MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209a0c0: r1 = 0x2167168u;
L_209a0c4: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_209a0c8: r2 = 0x217b144u;
L_209a0cc: r1 = 0x3fu;
L_209a0d0: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209a0d4: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_209a0e0: return r0;
}
