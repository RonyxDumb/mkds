/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0208b710(unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
unsigned int func_02081724(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2081728: r2 = 0x217ae84u;
L_208172c: r1 = 0x58u;
L_2081730: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 0));
L_2081734: r4 = (r0*r1+r2);
L_2081738: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 44));
L_208173c: cmp_a = r0; cmp_b = 0x0u;
L_2081740: if ((cmp_a == cmp_b)) { goto L_2081748; }
L_2081744: r0 = func_0208b710(r0);
L_2081748: r1 = 0x2155a14u;
L_208174c: r0 = 0x63u;
L_2081750: r0 = func_0208b7bc(r0,r1);
L_2081754: *(unsigned int *)((unsigned char *)r4 + 44) = (unsigned int)r0;
L_208175c: return r0;
}
