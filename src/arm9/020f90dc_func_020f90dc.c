/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02109054(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f90dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20f90e0: r4 = r0;
L_20f90e4: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f90e8: r1 = (r1&0x400000u); cmp_a = r1; cmp_b = 0;
L_20f90f0: if ((cmp_a == cmp_b)) { return r0; }
L_20f90f4: r0 = func_02109054(r0,r1,r2,r3);
L_20f90f8: r0 = 0x0u;
L_20f90fc: *(unsigned int *)((unsigned char *)r4 + 48) = (unsigned int)r0;
L_20f9100: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20f9104: r0 = (r0&~(0x400000u));
L_20f9108: *(unsigned int *)((unsigned char *)r4 + 116) = (unsigned int)r0;
L_20f9110: return r0;
}
