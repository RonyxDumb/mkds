/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MTX_MultVec33(unsigned int, unsigned int, unsigned int);
extern unsigned int VecFx32_Add(unsigned int, unsigned int, unsigned int);
unsigned int func_020e0538(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20e0540: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20e0544: r5 = r1;
L_20e0548: cmp_a = r4; cmp_b = 0x0u;
L_20e0554: if ((cmp_a == cmp_b)) { return r0; }
L_20e0558: r2 = r5;
L_20e055c: r0 = (r0+0x4u);
L_20e0560: r1 = (r4+0x28u);
L_20e0564: r0 = MTX_MultVec33(r0,r1,r2);
L_20e0568: r1 = r5;
L_20e056c: r2 = r5;
L_20e0570: r0 = (r4+0x4u);
L_20e0574: r0 = VecFx32_Add(r0,r1,r2);
L_20e0580: return r0;
}
