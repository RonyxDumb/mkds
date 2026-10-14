/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int UpdateBldcntBldalphaBldy(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int UpdateBldcntBldalphaBldy_Sub(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3,unsigned int a4)
{
unsigned int cmp_a,cmp_b,ip,lr,r4,r5,stack_0,stack_4;
L_20caaf0: r5 = r0;
L_20caaf4: r4 = r1;
L_20caaf8: lr = r2;
L_20caafc: stack_0 = r3;
L_20cab00: ip = a4;
L_20cab04: r0 = 0x4001050u;
L_20cab08: r1 = r5;
L_20cab0c: r2 = r4;
L_20cab10: r3 = lr;
L_20cab14: stack_4 = ip;
L_20cab18: r0 = UpdateBldcntBldalphaBldy(r0,r1,r2,r3,stack_0,stack_4);
L_20cab24: return r0;
}
