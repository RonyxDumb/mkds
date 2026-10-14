/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbca_from_thumb(unsigned int, unsigned int);
unsigned int func_02092140(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2092148: r1 = 0x2166644u;
L_209214c: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_2092150: r2 = 0x217b0c0u;
L_2092154: r1 = 0x2166654u;
L_2092158: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209215c: r0 = StructMapObject_AddAnimationNsbca_from_thumb(r0,r1);
L_2092168: return r0;
}
