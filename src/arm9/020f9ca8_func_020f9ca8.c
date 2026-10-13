/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int FindComputeSomeCollisionEntryId(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f9ca8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f9cac: r4 = r0;
L_20f9cb0: r1 = (unsigned int)(*(short *)((unsigned char *)r4 + 218));
L_20f9cb4: r0 = ~(0x0u);
L_20f9cb8: cmp_a = r1; cmp_b = r0;
L_20f9cc0: if ((cmp_a != cmp_b)) { return r0; }
L_20f9cc4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 224));
L_20f9cc8: r3 = r4;
L_20f9ccc: r0 = (r4+0x50u);
L_20f9cd0: r1 = (r1+0xa000u);
L_20f9cd4: r2 = 0x4000u;
L_20f9cd8: r0 = FindComputeSomeCollisionEntryId(r0,r1,r2,r3);
L_20f9cdc: *(unsigned short *)((unsigned char *)r4 + 218) = (unsigned short)r0;
L_20f9ce4: return r0;
}
