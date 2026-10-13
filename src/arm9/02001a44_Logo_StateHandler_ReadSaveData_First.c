/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ReadSaveData_NonGhost_from_thumb(void);
unsigned int Logo_StateHandler_ReadSaveData_First(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2001a4c: r0 = ReadSaveData_NonGhost_from_thumb();
L_2001a50: r0 = 0x21a99e0u;
L_2001a54: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2001a58: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 44));
L_2001a5c: r0 = (r0&~(0x2u));
L_2001a60: *(unsigned int *)((unsigned char *)r1 + 44) = (unsigned int)r0;
L_2001a6c: return r0;
}
