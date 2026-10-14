/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_2_from_thumb(unsigned int, unsigned int);
extern unsigned int CreateMapObjectFromModelAndAnimation_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int func_02096d68(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2096d6c: r1 = 0x2166928u;
L_2096d70: r4 = r0;
L_2096d74: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2096d78: r2 = 0x217b0f0u;
L_2096d7c: r1 = 0x2166934u;
L_2096d80: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2096d84: r2 = 0x2166940u;
L_2096d88: r0 = r4;
L_2096d8c: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_2096d90: r2 = 0x217b0f4u;
L_2096d94: r1 = 0x216694cu;
L_2096d98: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2096d9c: r0 = r4;
L_2096da0: r0 = CreateMapObjectFromModel_2_from_thumb(r0,r1);
L_2096da4: r2 = 0x217b0ecu;
L_2096da8: r1 = 0x217b0f4u;
L_2096dac: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2096db0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2096db4: r1 = 0x3fu;
L_2096db8: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2096dbc: r0 = 0x217b0ecu;
L_2096dc0: r1 = 0x3fu;
L_2096dc4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2096dc8: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2096dd0: return r0;
}
