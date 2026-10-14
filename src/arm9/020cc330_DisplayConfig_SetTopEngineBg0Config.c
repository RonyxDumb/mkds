/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg0Config(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int DisplayConfig_SetTopEngineBg0Config(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6,unsigned int a7)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_12,stack_4,stack_8;
L_20cc338: lr = a4;
L_20cc33c: ip = a5;
L_20cc340: stack_0 = lr;
L_20cc344: lr = a6;
L_20cc348: stack_4 = ip;
L_20cc34c: ip = a7;
L_20cc350: stack_8 = lr;
L_20cc354: r0 = (r0+0x28u);
L_20cc358: stack_12 = ip;
L_20cc35c: r0 = DisplayEngineConfig_SetBg0Config(r0,r1,r2,r3,stack_0,stack_4,stack_8,stack_12);
L_20cc368: return r0;
}
