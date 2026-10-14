/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg3Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetTopEngineBg3Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4,stack_8;
L_20ad960: ip = a4;
L_20ad964: lr = a5;
L_20ad968: stack_0 = ip;
L_20ad96c: ip = a6;
L_20ad970: stack_4 = lr;
L_20ad974: r0 = (r0+0x28u);
L_20ad978: stack_8 = ip;
L_20ad97c: r0 = DisplayEngineConfig_SetBg3Config(r0,r1,r2,r3,stack_0,stack_4,stack_8);
L_20ad988: return r0;
}
