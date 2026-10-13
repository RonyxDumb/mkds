/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int G2d_Text_PrintString(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int G2d_Text_PrintString5(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4,unsigned int a5)
{
unsigned int cmp_a,cmp_b,ip,lr,stack_0,stack_4;
L_20ca7e8: lr = a4;
L_20ca7ec: ip = a5;
L_20ca7f0: stack_0 = lr;
L_20ca7f4: stack_4 = ip;
L_20ca7f8: r0 = G2d_Text_PrintString(r0,r1,r2,r3,stack_0,stack_4);
L_20ca804: return r0;
}
