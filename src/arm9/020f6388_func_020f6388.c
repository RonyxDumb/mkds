/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f92e8(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f6388(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f638c: r4 = r0;
L_20f6390: r1 = r2;
L_20f6394: r0 = (r4+0x5cu);
L_20f6398: r0 = func_020f92e8(r0,r1,r2,r3);
L_20f639c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f63a0: r1 = (r0&0x1000000u); cmp_a = r1; cmp_b = 0;
L_20f63a8: if ((cmp_a != cmp_b)) { return r0; }
L_20f63ac: r0 = (r0|0x1000000u);
L_20f63b0: *(unsigned int *)((unsigned char *)r4 + 116) = (unsigned int)r0;
L_20f63b4: r0 = 0x0u;
L_20f63b8: *(unsigned int *)((unsigned char *)r4 + 264) = (unsigned int)r0;
L_20f63bc: *(unsigned int *)((unsigned char *)r4 + 268) = (unsigned int)r0;
L_20f63c0: *(unsigned int *)((unsigned char *)r4 + 272) = (unsigned int)r0;
L_20f63c8: return r0;
}
