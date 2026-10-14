/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
extern unsigned int StructMapObject_SomeFn_6(unsigned int, unsigned int);
unsigned int LoadPakkunBodyMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2098a1c: r1 = 0x21669f0u;
L_2098a20: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2098a24: r2 = 0x217b10cu;
L_2098a28: r1 = 0x3fu;
L_2098a2c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2098a30: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2098a34: r0 = 0x217b10cu;
L_2098a38: r1 = 0x1fu;
L_2098a3c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2098a40: r0 = StructMapObject_SomeFn_6(r0,r1);
L_2098a4c: return r0;
}
