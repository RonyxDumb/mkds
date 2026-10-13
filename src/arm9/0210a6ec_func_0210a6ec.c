/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02105b28(unsigned int, unsigned int);
extern unsigned int func_02105b0c(unsigned int, unsigned int);
unsigned int func_0210a6ec(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_210a6f4: r5 = r1;
L_210a6f8: r1 = (unsigned int)(*(unsigned char *)((unsigned char *)r5 + 26));
L_210a6fc: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 76));
L_210a700: r0 = r5;
L_210a704: r0 = func_02105b28(r0,r1);
L_210a708: r1 = (unsigned int)(*(short *)((unsigned char *)r5 + 20));
L_210a70c: r0 = r5;
L_210a710: r1 = (r1+r4);
L_210a714: r0 = func_02105b0c(r0,r1);
L_210a720: return r0;
}
