/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int func_0209bd90(unsigned int, unsigned int);
extern unsigned int StructMapObject_MaybeSetPolygonId(unsigned int, unsigned int);
unsigned int LoadNsKiller2MapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2093b34: r1 = 0x2166748u;
L_2093b38: r4 = r0;
L_2093b3c: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2093b40: r2 = 0x217b0ccu;
L_2093b44: r1 = 0x2166758u;
L_2093b48: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2093b4c: r0 = r4;
L_2093b50: r0 = func_0209bd90(r0,r1);
L_2093b54: r2 = 0x217b0d0u;
L_2093b58: r1 = 0x3fu;
L_2093b5c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2093b60: r0 = StructMapObject_MaybeSetPolygonId(r0,r1);
L_2093b68: return r0;
}
