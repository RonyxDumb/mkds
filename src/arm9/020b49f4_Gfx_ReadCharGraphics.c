/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int Gfx_MakeCharGraphicsOffsetsAbsolute(unsigned int);
extern unsigned int Arm_FlushRange(unsigned int, unsigned int);
unsigned int Gfx_ReadCharGraphics(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20b49f8: r4 = r0;
L_20b49fc: cmp_a = r1; cmp_b = 0x0u;
L_20b4a00: if ((cmp_a == cmp_b)) { goto L_20b4a28; }
L_20b4a04: r0 = r1;
L_20b4a08: r1 = 0x43484152u;
L_20b4a0c: r0 = Common_FindBlockByMagic(r0,r1);
L_20b4a10: cmp_a = r0; cmp_b = 0x0u;
L_20b4a14: if ((cmp_a == cmp_b)) { goto L_20b4a28; }
L_20b4a18: r0 = (r0+0x8u);
L_20b4a1c: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20b4a20: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b4a24: r0 = Gfx_MakeCharGraphicsOffsetsAbsolute(r0);
L_20b4a28: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b4a2c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 20));
L_20b4a30: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 16));
L_20b4a34: r0 = Arm_FlushRange(r0,r1);
L_20b4a3c: return r0;
}
