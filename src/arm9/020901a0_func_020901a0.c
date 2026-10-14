/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207c078(unsigned int);
extern unsigned int func_0207c614(unsigned int, unsigned int);
unsigned int func_020901a0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20901a8: r5 = r0;
L_20901ac: r4 = r1;
L_20901b0: r0 = func_0207c078(r0);
L_20901b4: cmp_a = r0; cmp_b = 0x0u;
L_20901c0: if ((cmp_a == cmp_b)) { return r0; }
L_20901c4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 112));
L_20901c8: cmp_a = r0; cmp_b = 0xa000u;
L_20901d4: if (((int)cmp_a >= (int)cmp_b)) { return r0; }
L_20901d8: r0 = r5;
L_20901dc: r1 = r4;
L_20901e0: r0 = func_0207c614(r0,r1);
L_20901ec: return r0;
}
