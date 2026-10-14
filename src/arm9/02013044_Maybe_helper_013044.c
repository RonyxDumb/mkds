/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02013424(unsigned int, unsigned int, unsigned int);
unsigned int Maybe_helper_013044(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013048: r6 = r0;
L_201304c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013050: r5 = r1;
L_2013054: r4 = 0x0u;
L_2013058: cmp_a = r0; cmp_b = 0x0u;
L_2013060: if ((cmp_a <= cmp_b)) { return r0; }
L_2013064: r0 = r6;
L_2013068: r1 = r4;
L_201306c: r2 = r5;
L_2013070: r0 = func_02013424(r0,r1,r2);
L_2013074: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r6 + 24));
L_2013078: r4 = (r4+0x1u);
L_201307c: cmp_a = r4; cmp_b = r0;
L_2013080: if ((cmp_a < cmp_b)) { goto L_2013064; }
L_2013088: return r0;
}
