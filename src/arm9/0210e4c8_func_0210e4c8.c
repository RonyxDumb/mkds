/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int Sound_Context_BackupFrameState(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0210e4c8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210e4cc: r1 = 0x217d130u;
L_210e4d0: r4 = r0;
L_210e4d4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_210e4d8: r0 = Sound_Context_BackupFrameState(r0,r1,r2,r3);
L_210e4dc: *(unsigned int *)((unsigned char *)r4 + 12) = (unsigned int)r0;
L_210e4e4: return r0;
}
