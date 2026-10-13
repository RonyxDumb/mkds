/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020d5344(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f9c40(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f9c44: r4 = r0;
L_20f9c48: r0 = (unsigned int)(*(short *)((unsigned char *)r4 + 218));
L_20f9c4c: r1 = ~(0x0u);
L_20f9c50: cmp_a = r0; cmp_b = r1;
L_20f9c58: if ((cmp_a == cmp_b)) { return r0; }
L_20f9c5c: r0 = func_020d5344(r0,r1,r2,r3);
L_20f9c60: *(unsigned short *)((unsigned char *)r4 + 218) = (unsigned short)r0;
L_20f9c68: return r0;
}
