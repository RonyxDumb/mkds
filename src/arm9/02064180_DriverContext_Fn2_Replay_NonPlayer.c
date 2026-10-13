/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int GetAED0PlayerUnk(unsigned int);
extern unsigned int func_0210b7ec(unsigned int, unsigned int);
unsigned int DriverContext_Fn2_Replay_NonPlayer(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_2064184: r4 = r0;
L_2064188: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_206418c: r0 = GetAED0PlayerUnk(r0);
L_2064190: *(unsigned int *)((unsigned char *)r4 + 64) = (unsigned int)r0;
L_2064194: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_2064198: r0 = GetAED0PlayerUnk(r0);
L_206419c: r2 = 0x518u;
L_20641a0: r1 = r0;
L_20641a4: r0 = (r4+r2);
L_20641a8: r0 = func_0210b7ec(r0,r1);
L_20641b0: return r0;
}
