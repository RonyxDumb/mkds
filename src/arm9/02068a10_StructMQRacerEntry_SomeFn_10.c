/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_7(unsigned int, unsigned int, unsigned int);
extern unsigned int CharacterKartContext_SetNsbtpAnimationProgress(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_5(unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_10(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2068a14: r4 = r0;
L_2068a18: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_2068a1c: r1 = (r1&0x10u); cmp_a = r1; cmp_b = 0;
L_2068a20: if ((cmp_a == cmp_b)) { goto L_2068a3c; }
L_2068a24: r1 = 0x1u;
L_2068a28: r2 = 0x0u;
L_2068a2c: r0 = StructMQRacerEntry_SomeFn_7(r0,r1,r2);
L_2068a30: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 1424));
L_2068a34: r1 = 0x1u;
L_2068a38: r0 = CharacterKartContext_SetNsbtpAnimationProgress(r0,r1);
L_2068a3c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_2068a40: r0 = (r0&0x840u); cmp_a = r0; cmp_b = 0;
L_2068a48: if ((cmp_a != cmp_b)) { return r0; }
L_2068a4c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 972));
L_2068a50: r0 = r4;
L_2068a54: r2 = 0x0u;
L_2068a58: r0 = StructMQRacerEntry_SomeFn_5(r0,r1,r2);
L_2068a60: return r0;
}
