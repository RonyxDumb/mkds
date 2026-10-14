/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetCurrentSceneId(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int GetCurrentUnlockedSecretFlags(void);
extern unsigned int WriteSaveDataSectionHeaderToSaveData_from_thumb(void);
extern unsigned int WaitForWorkerTask(void);
extern unsigned int func_02145d38(void);
unsigned int GetCurrentUnlockedSecretFlagsAndSaveIfResultScene(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20911ac: r4 = 0x0u;
L_20911b0: r0 = GetCurrentSceneId(r0,r1,r2,r3);
L_20911b4: cmp_a = r0; cmp_b = 0xau;
L_20911b8: if ((cmp_a != cmp_b)) { goto L_20911e4; }
L_20911bc: r0 = GetCurrentUnlockedSecretFlags();
L_20911c0: r4 = r0;
L_20911c4: r0 = WriteSaveDataSectionHeaderToSaveData_from_thumb();
L_20911c8: r0 = WaitForWorkerTask();
L_20911cc: r0 = 0x21759d4u;
L_20911d0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20911d4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_20911d8: cmp_a = r0; cmp_b = 0x0u;
L_20911dc: if ((cmp_a == cmp_b)) { goto L_20911e4; }
L_20911e0: r0 = func_02145d38();
L_20911e4: r0 = r4;
L_20911ec: return r0;
}
