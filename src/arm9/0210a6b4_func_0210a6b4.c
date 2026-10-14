/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02105b28(unsigned int, unsigned int);
extern unsigned int func_02105b0c(unsigned int, unsigned int);
unsigned int func_0210a6b4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_210a6bc: r5 = r1;
L_210a6c0: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r5 + 26));
L_210a6c4: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 76));
L_210a6c8: r0 = r5;
L_210a6cc: r0 = func_02105b28(r0,r1);
L_210a6d0: r1 = (unsigned int)(*(short *)((unsigned char *)r5 + 20));
L_210a6d4: r0 = r5;
L_210a6d8: r1 = (r1+r4);
L_210a6dc: r0 = func_02105b0c(r0,r1);
L_210a6e8: return r0;
}
