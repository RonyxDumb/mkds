/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int Screen_ReadBlock(unsigned int, unsigned int);
extern unsigned int Arm_FlushRange(unsigned int, unsigned int);
unsigned int MaybeReadScreenBlock_0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20b4818: r4 = r1; cmp_a = r4; cmp_b = 0;
L_20b481c: r5 = r0;
L_20b4820: if ((cmp_a == cmp_b)) { goto L_20b484c; }
L_20b4824: r1 = 0x5343524eu;
L_20b4828: r0 = r4;
L_20b482c: r0 = Common_FindBlockByMagic(r0,r1);
L_20b4830: cmp_a = r0; cmp_b = 0x0u;
L_20b4834: if ((cmp_a == cmp_b)) { goto L_20b484c; }
L_20b4838: r2 = (r0+0x8u);
L_20b483c: r0 = r4;
L_20b4840: r1 = r5;
L_20b4844: *(unsigned int *)((unsigned char *)r5 + 0) = (unsigned int)r2;
L_20b4848: r0 = Screen_ReadBlock(r0,r1);
L_20b484c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 0));
L_20b4850: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20b4854: r0 = (r0+0xcu);
L_20b4858: r0 = Arm_FlushRange(r0,r1);
L_20b4864: return r0;
}
