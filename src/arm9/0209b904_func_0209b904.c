/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ModelBlock_SomeTexPltFn_3(unsigned int, unsigned int, unsigned int);
unsigned int func_0209b904(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209b90c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 16));
L_209b910: r3 = r1;
L_209b914: cmp_a = r0; cmp_b = 0x0u;
L_209b920: if ((cmp_a == cmp_b)) { return r0; }
L_209b924: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_209b928: r1 = r2;
L_209b92c: r2 = r3;
L_209b930: r0 = ModelBlock_SomeTexPltFn_3(r0,r1,r2);
L_209b93c: return r0;
}
