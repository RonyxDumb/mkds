/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg1Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetTopEngineBg1Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_4,stack_8;
L_20ad9c8: lr = a4;
L_20ad9cc: ip = a5;
L_20ad9d0: stack_0 = lr;
L_20ad9d4: lr = a6;
L_20ad9d8: stack_4 = ip;
L_20ad9dc: ip = a7;
L_20ad9e0: stack_8 = lr;
L_20ad9e4: r0 = (r0+0x28u);
L_20ad9e8: stack_12 = ip;
L_20ad9ec: r0 = DisplayEngineConfig_SetBg1Config(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12);
L_20ad9f8: return r0;
}
