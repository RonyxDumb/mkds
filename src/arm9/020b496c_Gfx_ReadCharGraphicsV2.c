/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int Gfx_MakeCharGraphicsOffsetsAbsoluteV2(unsigned int);
extern unsigned int Arm_FlushRange(unsigned int, unsigned int);
unsigned int Gfx_ReadCharGraphicsV2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20b4970: r4 = r0;
L_20b4974: cmp_a = r1; cmp_b = 0x0u;
L_20b4978: if ((cmp_a == cmp_b)) { goto L_20b49a0; }
L_20b497c: r0 = r1;
L_20b4980: r1 = 0x43484152u;
L_20b4984: r0 = Common_FindBlockByMagic(r0,r1);
L_20b4988: cmp_a = r0; cmp_b = 0x0u;
L_20b498c: if ((cmp_a == cmp_b)) { goto L_20b49a0; }
L_20b4990: r0 = (r0+0x8u);
L_20b4994: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20b4998: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b499c: r0 = Gfx_MakeCharGraphicsOffsetsAbsoluteV2(r0);
L_20b49a0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b49a4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 20));
L_20b49a8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 16));
L_20b49ac: r0 = Arm_FlushRange(r0,r1);
L_20b49b4: return r0;
}
