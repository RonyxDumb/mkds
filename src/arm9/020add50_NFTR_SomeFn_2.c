/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int NFTR_SomeFn_3(unsigned int);
unsigned int NFTR_SomeFn_2(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20add58: r5 = r0;
L_20add5c: r4 = r1;
L_20add60: r0 = NFTR_SomeFn_3(r0);
L_20add64: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 0));
L_20add68: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_20add6c: r1 = (r1+0x8u);
L_20add70: r0 = (r4*r0+r1);
L_20add7c: return r0;
}
