/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Common_FindBlockByMagic(unsigned int, unsigned int);
extern unsigned int func_02021dc8(unsigned int);
unsigned int func_020b486c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20b4870: r4 = r0;
L_20b4874: cmp_a = r1; cmp_b = 0x0u;
L_20b487c: if ((cmp_a == cmp_b)) { return r0; }
L_20b4880: r0 = r1;
L_20b4884: r1 = 0x41424e4bu;
L_20b4888: r0 = Common_FindBlockByMagic(r0,r1);
L_20b488c: cmp_a = r0; cmp_b = 0x0u;
L_20b4894: if ((cmp_a == cmp_b)) { return r0; }
L_20b4898: r0 = (r0+0x8u);
L_20b489c: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_20b48a0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 0));
L_20b48a4: r0 = func_02021dc8(r0);
L_20b48ac: return r0;
}
