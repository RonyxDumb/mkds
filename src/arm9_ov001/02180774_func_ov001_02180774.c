/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg2Config2(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_ov001_02180774(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4,stack_8;
L_20ad994: ip = a4;
L_20ad998: lr = a5;
L_20ad99c: stack_0 = ip;
L_20ad9a0: ip = a6;
L_20ad9a4: stack_4 = lr;
L_20ad9a8: r0 = (r0+0x28u);
L_20ad9ac: stack_8 = ip;
L_20ad9b0: r0 = DisplayEngineConfig_SetBg2Config2(r0,r1,r2,r3,stack_0,stack_4,stack_8);
L_20ad9bc: return r0;
}
