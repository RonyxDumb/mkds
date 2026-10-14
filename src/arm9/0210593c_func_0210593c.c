/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210d5c0(unsigned int);
unsigned int func_0210593c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2105944: cmp_a = r0; cmp_b = 0x4u;
L_2105950: if ((cmp_a != cmp_b)) { return r0; }
L_2105954: r0 = 0x217d070u;
L_2105958: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_210595c: cmp_a = r1; cmp_b = 0x0u;
L_2105968: if ((cmp_a != cmp_b)) { return r0; }
L_210596c: r0 = func_0210d5c0(r0);
L_2105978: return r0;
}
