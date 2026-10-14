/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int func_0209bd90(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadBakubakuMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_209595c: r1 = 0x216687cu;
L_2095960: r4 = r0;
L_2095964: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2095968: r2 = 0x217b0e4u;
L_209596c: r1 = 0x216688cu;
L_2095970: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2095974: r0 = r4;
L_2095978: r0 = func_0209bd90(r0,r1);
L_209597c: r2 = 0x217b0e0u;
L_2095980: r1 = 0x217b0e4u;
L_2095984: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2095988: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_209598c: r1 = 0x3fu;
L_2095990: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2095994: r0 = 0x217b0e0u;
L_2095998: r1 = 0x3fu;
L_209599c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20959a0: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_20959a8: return r0;
}
