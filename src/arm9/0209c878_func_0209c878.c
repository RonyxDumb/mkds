/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int CreateMapObjectFromModel_from_thumb(unsigned int, unsigned int);
extern unsigned int StructMapObject_AddAnimationNsbtp_from_thumb(unsigned int, unsigned int);
unsigned int func_0209c878(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209c880: r1 = 0x216733cu;
L_209c884: r0 = CreateMapObjectFromModel_from_thumb(r0,r1);
L_209c888: r2 = 0x217b184u;
L_209c88c: r1 = 0x2167348u;
L_209c890: *(unsigned int *)((unsigned char *)r2 + 0) = (unsigned int)r0;
L_209c894: r0 = StructMapObject_AddAnimationNsbtp_from_thumb(r0,r1);
L_209c8a0: return r0;
}
