/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbtp_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbta_from_thumb(unsigned int, unsigned int);
unsigned int LoadFlipperMapObject(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2097e8c: r1 = 0x216698cu;
L_2097e90: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2097e94: r2 = 0x217b0f8u;
L_2097e98: r1 = 0x216699cu;
L_2097e9c: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_2097ea0: r0 = StructMapObject_AddAnimationNsbtp_from_thumb(r0,r1);
L_2097ea4: r0 = 0x217b0f8u;
L_2097ea8: r1 = 0x21669acu;
L_2097eac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2097eb0: r0 = StructMapObject_AddAnimationNsbta_from_thumb(r0,r1);
L_2097ebc: return r0;
}
