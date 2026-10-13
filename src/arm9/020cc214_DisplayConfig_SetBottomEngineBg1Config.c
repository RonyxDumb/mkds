/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg1Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetBottomEngineBg1Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_4,stack_8;
L_20cc21c: lr = a4;
L_20cc220: ip = a5;
L_20cc224: stack_0 = lr;
L_20cc228: lr = a6;
L_20cc22c: stack_4 = ip;
L_20cc230: ip = a7;
L_20cc234: stack_8 = lr;
L_20cc238: r0 = (r0+0x70u);
L_20cc23c: stack_12 = ip;
L_20cc240: r0 = DisplayEngineConfig_SetBg1Config(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12);
L_20cc24c: return r0;
}
