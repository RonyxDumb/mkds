/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int VecFx32_Subtract(unsigned int, unsigned int, unsigned int);
extern unsigned int Vector3_MaybeNormalize(unsigned int, unsigned int);
unsigned int func_0207ff5c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_207ff60: r4 = r0;
L_207ff64: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207ff68: r2 = (r4+0x8u);
L_207ff6c: *(unsigned int *)((unsigned char *)r4 + 4) = (unsigned int)r0;
L_207ff70: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207ff74: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_207ff78: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_207ff7c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_207ff80: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_207ff84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 24));
L_207ff88: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 24));
L_207ff8c: r0 = VecFx32_Subtract(r0,r1,r2);
L_207ff90: r0 = (r4+0x8u);
L_207ff94: r1 = r0;
L_207ff98: r0 = Vector3_MaybeNormalize(r0,r1);
L_207ffa0: return r0;
}
