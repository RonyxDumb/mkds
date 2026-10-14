/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int Gfx_MakePaletteOffsetsAbsolute(unsigned int);
extern unsigned int Arm_FlushRange(unsigned int, unsigned int);
unsigned int Gfx_ReadPalette(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20b4a80: r4 = r0;
L_20b4a84: cmp_a = r1; cmp_b = 0x0u;
L_20b4a88: if ((cmp_a == cmp_b)) { goto L_20b4ab0; }
L_20b4a8c: r0 = r1;
L_20b4a90: r1 = 0x504c5454u;
L_20b4a94: r0 = Common_FindBlockByMagic(r0,r1);
L_20b4a98: cmp_a = r0; cmp_b = 0x0u;
L_20b4a9c: if ((cmp_a == cmp_b)) { goto L_20b4ab0; }
L_20b4aa0: r0 = (r0+0x8u);
L_20b4aa4: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20b4aa8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b4aac: r0 = Gfx_MakePaletteOffsetsAbsolute(r0);
L_20b4ab0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b4ab4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 12));
L_20b4ab8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20b4abc: r0 = Arm_FlushRange(r0,r1);
L_20b4ac4: return r0;
}
