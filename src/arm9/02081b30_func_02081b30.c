/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetDriverEntry(unsigned int);
extern unsigned int func_02081ca0(unsigned int, unsigned int, unsigned int);
unsigned int func_02081b30(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2081b34: r4 = r0;
L_2081b38: cmp_a = r1; cmp_b = 0x0u;
L_2081b40: if ((cmp_a != cmp_b)) { return r0; }
L_2081b44: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 155));
L_2081b48: r0 = GetDriverEntry(r0);
L_2081b4c: r1 = r0;
L_2081b50: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 148));
L_2081b54: r0 = r4;
L_2081b58: r0 = func_02081ca0(r0,r1,r2);
L_2081b60: return r0;
}
