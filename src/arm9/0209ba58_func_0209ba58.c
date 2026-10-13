/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ea740(unsigned int, unsigned int);
unsigned int func_0209ba58(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_209ba60: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 16));
L_209ba64: cmp_a = r0; cmp_b = 0x0u;
L_209ba70: if ((cmp_a == cmp_b)) { return r0; }
L_209ba74: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r2 + 102));
L_209ba78: r0 = func_020ea740(r0,r1);
L_209ba84: return r0;
}
