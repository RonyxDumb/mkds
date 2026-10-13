/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int FindComputeSomeCollisionEntryId(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f9c6c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f9c70: r4 = r0;
L_20f9c74: r1 = (unsigned int)(*(short *)((unsigned char *)r4 + 218));
L_20f9c78: r0 = ~(0x0u);
L_20f9c7c: cmp_a = r1; cmp_b = r0;
L_20f9c84: if ((cmp_a != cmp_b)) { return r0; }
L_20f9c88: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 224));
L_20f9c8c: r3 = r4;
L_20f9c90: r0 = (r4+0x50u);
L_20f9c94: r2 = 0x4000u;
L_20f9c98: r0 = FindComputeSomeCollisionEntryId(r0,r1,r2,r3);
L_20f9c9c: *(unsigned short *)((unsigned char *)r4 + 218) = (unsigned short)r0;
L_20f9ca4: return r0;
}
