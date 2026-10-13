/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0210d73c(unsigned int);
extern unsigned int NNS_SndMain(void);
unsigned int func_0210d7ac(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210d7b4: r0 = 0x217d070u;
L_210d7b8: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_210d7bc: cmp_a = r1; cmp_b = 0x0u;
L_210d7c0: if ((cmp_a == cmp_b)) { goto L_210d7c8; }
L_210d7c4: r0 = func_0210d73c(r0);
L_210d7c8: r0 = NNS_SndMain();
L_210d7d4: return r0;
}
