/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg2Config2(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetTopEngineBg2Config2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4,stack_8;
L_20cc2c8: ip = a4;
L_20cc2cc: lr = a5;
L_20cc2d0: stack_0 = ip;
L_20cc2d4: ip = a6;
L_20cc2d8: stack_4 = lr;
L_20cc2dc: r0 = (r0+0x28u);
L_20cc2e0: stack_8 = ip;
L_20cc2e4: r0 = DisplayEngineConfig_SetBg2Config2(r0,r1,r2,r3,stack_0,stack_4,stack_8);
L_20cc2f0: return r0;
}
