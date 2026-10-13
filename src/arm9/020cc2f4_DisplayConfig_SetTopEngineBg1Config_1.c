/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg1Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetTopEngineBg1Config_1(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_4,stack_8;
L_20cc2fc: lr = a4;
L_20cc300: ip = a5;
L_20cc304: stack_0 = lr;
L_20cc308: lr = a6;
L_20cc30c: stack_4 = ip;
L_20cc310: ip = a7;
L_20cc314: stack_8 = lr;
L_20cc318: r0 = (r0+0x28u);
L_20cc31c: stack_12 = ip;
L_20cc320: r0 = DisplayEngineConfig_SetBg1Config(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12);
L_20cc32c: return r0;
}
