/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_42(unsigned int);
extern unsigned int func_020f4754(unsigned int, unsigned int);
extern unsigned int func_020f81b8(unsigned int, unsigned int);
unsigned int func_021051d4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_21051dc: r4 = r1;
L_21051e0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 4));
L_21051e4: r5 = r0;
L_21051e8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 508));
L_21051ec: r0 = StructMQRacerEntry_SomeFn_42(r0);
L_21051f0: r0 = r4;
L_21051f4: r1 = 0x1u;
L_21051f8: r0 = func_020f4754(r0,r1);
L_21051fc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_2105200: r1 = 0xeu;
L_2105204: r0 = func_020f81b8(r0,r1);
L_2105210: return r0;
}
