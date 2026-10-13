/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212f638(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0210d834(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210d838: r4 = r0;
L_210d83c: r0 = func_0212f638(r0,r1,r2,r3);
L_210d840: r0 = 0x216cb24u;
L_210d844: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r4;
L_210d84c: return r0;
}
