/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg0Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetBottomEngineBg0Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_4,stack_8;
L_20cc258: lr = a4;
L_20cc25c: ip = a5;
L_20cc260: stack_0 = lr;
L_20cc264: lr = a6;
L_20cc268: stack_4 = ip;
L_20cc26c: ip = a7;
L_20cc270: stack_8 = lr;
L_20cc274: r0 = (r0+0x70u);
L_20cc278: stack_12 = ip;
L_20cc27c: r0 = DisplayEngineConfig_SetBg0Config(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12);
L_20cc288: return r0;
}
