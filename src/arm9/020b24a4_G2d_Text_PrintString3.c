/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int G2d_Text_PrintString(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int G2d_Text_PrintString3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4;
L_20b24ac: lr = a4;
L_20b24b0: ip = a5;
L_20b24b4: stack_0 = lr;
L_20b24b8: stack_4 = ip;
L_20b24bc: r0 = G2d_Text_PrintString(r0,r1,r2,r3,stack_0,stack_4);
L_20b24c8: return r0;
}
