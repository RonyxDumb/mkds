/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int EraseNonGhostSaveDataSections_from_thumb(void);
extern unsigned int Bmg_GetRawStringPointer_from_thumb(unsigned int, unsigned int);
extern unsigned int TextSystem_DisplayProgressDialog_from_thumb(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int Logo_StateHandler_EraseCorruptedSaveData_First(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,stack_0,stack_4;
L_2001778: r0 = EraseNonGhostSaveDataSections_from_thumb();
L_200177c: r0 = 0x21a99e0u;
L_2001780: r1 = 0x7eu;
L_2001784: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2001788: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 56));
L_200178c: r0 = Bmg_GetRawStringPointer_from_thumb(r0,r1);
L_2001790: r1 = 0x1u;
L_2001794: r2 = 0x0u;
L_2001798: stack_0 = r2;
L_200179c: r2 = r1;
L_20017a0: r3 = r1;
L_20017a4: stack_4 = r1;
L_20017a8: r0 = TextSystem_DisplayProgressDialog_from_thumb(r0,r1,r2,r3,stack_0,stack_4);
L_20017ac: r0 = 0x21a99e0u;
L_20017b0: r1 = 0x0u;
L_20017b4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20017b8: *(unsigned int *)((unsigned char *)r0 + 52) = (unsigned int)r1;
L_20017c4: return r0;
}
