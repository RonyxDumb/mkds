/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModelAndAnimation_from_thumb(unsigned int, unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int func_02094db4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2094db8: r1 = 0x21667f4u;
L_2094dbc: r2 = 0x2166804u;
L_2094dc0: r4 = r0;
L_2094dc4: r0 = CreateMapObjectFromModelAndAnimation_from_thumb(r0,r1,r2);
L_2094dc8: r2 = 0x217b0dcu;
L_2094dcc: r1 = 0x3fu;
L_2094dd0: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2094dd4: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2094dd8: r0 = 0x1u;
L_2094ddc: *(unsigned int *)((unsigned char *)r4 + 28) = (unsigned int)r0;
L_2094de4: return r0;
}
