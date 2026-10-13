/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02049838(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int BrightCtx_SomeFn_1(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_02055bd4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2055bd8: r4 = r0;
L_2055bdc: r0 = func_02049838(r0,r1,r2,r3);
L_2055be0: cmp_a = r0; cmp_b = 0x2u;
L_2055be8: if ((cmp_a != cmp_b)) { return r0; }
L_2055bec: r1 = 0x217aa04u;
L_2055bf0: r0 = r4;
L_2055bf4: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2055bf8: r1 = 0x1u;
L_2055bfc: r2 = (unsigned int)(*(unsigned short *)((unsigned char *)r3 + 8));
L_2055c00: r2 = (r2|0x4u);
L_2055c04: *(unsigned short *)((unsigned char *)r3 + 8) = (unsigned short)r2;
L_2055c08: r0 = BrightCtx_SomeFn_1(r0,r1,r2,r3);
L_2055c10: return r0;
}
