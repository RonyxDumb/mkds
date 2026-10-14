/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02022a90(unsigned int);
unsigned int func_02022a60(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2022a68: r5 = r1;
L_2022a6c: r4 = r2;
L_2022a70: r0 = func_02022a90(r0);
L_2022a74: r1 = ~(0x0u);
L_2022a78: *(unsigned int *)((unsigned char *)r0 + 36) = (unsigned int)r1;
L_2022a7c: *(unsigned int *)((unsigned char *)r0 + 40) = (unsigned int)r5;
L_2022a80: *(unsigned int *)((unsigned char *)r0 + 44) = (unsigned int)r4;
L_2022a8c: return r0;
}
