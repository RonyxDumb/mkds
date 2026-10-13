/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DriverContext_MaybeApplyBoost(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020a1ddc(unsigned int);
unsigned int DriverContext_ApplyShroomBoost(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2069dbc: r4 = r0;
L_2069dc0: r1 = 0x0u;
L_2069dc4: r2 = 0x5au;
L_2069dc8: r0 = DriverContext_MaybeApplyBoost(r0,r1,r2);
L_2069dcc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_2069dd0: r0 = (r4+0x500u);
L_2069dd4: r1 = (r1|0x100000u);
L_2069dd8: *(unsigned int *)((unsigned char *)r4 + 72) = (unsigned int)r1;
L_2069ddc: r2 = 0x5au;
L_2069de0: r1 = 0x21759c0u;
L_2069de4: *(unsigned short *)((unsigned char *)r0 + 56) = (unsigned short)r2;
L_2069de8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2069dec: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_2069df0: cmp_a = r0; cmp_b = 0x2u;
L_2069df8: if ((cmp_a != cmp_b)) { return r0; }
L_2069dfc: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2069e00: r0 = func_020a1ddc(r0);
L_2069e08: return r0;
}
