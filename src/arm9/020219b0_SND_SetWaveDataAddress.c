/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Sound_LockMutex(void);
extern unsigned int DC_SomeClean(unsigned int, unsigned int);
extern unsigned int Sound_UnlockMutex(void);
unsigned int SND_SetWaveDataAddress(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20219b4: r6 = r0;
L_20219b8: r5 = r1;
L_20219bc: r4 = r2;
L_20219c0: r0 = Sound_LockMutex();
L_20219c4: r0 = (r6+0x3cu);
L_20219c8: r2 = (r6+(r5 << 2));
L_20219cc: r0 = (r0+(r5 << 2));
L_20219d0: r1 = 0x4u;
L_20219d4: *(unsigned int *)((unsigned char *)r2 + 60) = (unsigned int)r4;
L_20219d8: r0 = DC_SomeClean(r0,r1);
L_20219dc: r0 = Sound_UnlockMutex();
L_20219e4: return r0;
}
