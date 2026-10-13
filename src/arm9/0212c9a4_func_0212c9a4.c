/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0212bc20(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_0212c9a4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_212c9a8: r4 = r0;
L_212c9ac: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_212c9b0: cmp_a = r0; cmp_b = 0x0u;
L_212c9b8: if ((cmp_a == cmp_b)) { return r0; }
L_212c9bc: r0 = func_0212bc20(r0,r1,r2,r3);
L_212c9c0: r0 = 0x0u;
L_212c9c4: *(unsigned int *)((unsigned char *)r4 + 68) = (unsigned int)r0;
L_212c9c8: *(unsigned int *)((unsigned char *)r4 + 72) = (unsigned int)r0;
L_212c9d0: return r0;
}
