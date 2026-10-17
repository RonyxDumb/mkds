/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DisplayEngineConfig_SetBg2Config2(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_ov001_02180740(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5,unsigned int a6)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4,stack_8;
L_20cc1e8: ip = a4;
L_20cc1ec: lr = a5;
L_20cc1f0: stack_0 = ip;
L_20cc1f4: ip = a6;
L_20cc1f8: stack_4 = lr;
L_20cc1fc: r0 = (r0+0x70u);
L_20cc200: stack_8 = ip;
L_20cc204: r0 = DisplayEngineConfig_SetBg2Config2(r0,r1,r2,r3,stack_0,stack_4,stack_8);
L_20cc210: return r0;
}
