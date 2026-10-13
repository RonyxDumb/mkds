/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020849f8(unsigned int, unsigned int, unsigned int);
unsigned int func_02063228(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2063230: r0 = 0x217ab1cu;
L_2063234: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_2063238: cmp_a = r0; cmp_b = 0x0u;
L_2063244: if ((cmp_a == cmp_b)) { return r0; }
L_2063248: r1 = 0x217abccu;
L_206324c: r2 = 0x2154a20u;
L_2063250: r0 = func_020849f8(r0,r1,r2);
L_206325c: return r0;
}
