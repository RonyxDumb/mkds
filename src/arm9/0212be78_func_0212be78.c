/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020d80(unsigned int, unsigned int);
extern unsigned int func_02020e10(unsigned int);
extern unsigned int func_0212bd6c(unsigned int);
unsigned int func_0212be78(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_212be7c: r4 = r0;
L_212be80: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 44));
L_212be84: cmp_a = r0; cmp_b = 0x2u;
L_212be88: if ((cmp_a != cmp_b)) { goto L_212be98; }
L_212be8c: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 60));
L_212be90: r1 = 0xfffffd2du;
L_212be94: r0 = func_02020d80(r0,r1);
L_212be98: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 60));
L_212be9c: r0 = func_02020e10(r0);
L_212bea0: r0 = r4;
L_212bea4: r0 = func_0212bd6c(r0);
L_212beac: return r0;
}
