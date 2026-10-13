/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02049838(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int BrightCtx_SomeFn_0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02055c18(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2055c1c: r4 = r0;
L_2055c20: r0 = func_02049838(r0,r1,r2,r3);
L_2055c24: cmp_a = r0; cmp_b = 0x2u;
L_2055c2c: if ((cmp_a != cmp_b)) { return r0; }
L_2055c30: r1 = 0x217aa04u;
L_2055c34: r0 = r4;
L_2055c38: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2055c3c: r1 = 0x1u;
L_2055c40: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r3 + 8));
L_2055c44: r2 = (r2|0x4u);
L_2055c48: *(unsigned short *)((unsigned char *)r3 + 8) = (unsigned short)r2;
L_2055c4c: r0 = BrightCtx_SomeFn_0(r0,r1,r2,r3);
L_2055c54: return r0;
}
