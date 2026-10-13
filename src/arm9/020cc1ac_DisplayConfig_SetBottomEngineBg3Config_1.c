/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg3Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetBottomEngineBg3Config_1(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4,stack_8;
L_20cc1b4: ip = a4;
L_20cc1b8: lr = a5;
L_20cc1bc: stack_0 = ip;
L_20cc1c0: ip = a6;
L_20cc1c4: stack_4 = lr;
L_20cc1c8: r0 = (r0+0x70u);
L_20cc1cc: stack_8 = ip;
L_20cc1d0: r0 = DisplayEngineConfig_SetBg3Config(r0,r1,r2,r3,stack_0,stack_4,stack_8);
L_20cc1dc: return r0;
}
