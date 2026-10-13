/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d8cac(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020dff4c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20dff50: r4 = (r0+0x144u);
L_20dff54: r0 = r4;
L_20dff58: r0 = func_020d8cac(r0,r1,r2,r3);
L_20dff5c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 24));
L_20dff60: cmp_a = r1; cmp_b = 0x0u;
L_20dff64: if ((cmp_a == cmp_b)) { r0 = (0x1000u-r0); }
L_20dff6c: return r0;
}
