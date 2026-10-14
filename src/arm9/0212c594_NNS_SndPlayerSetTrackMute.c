/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02020af8(unsigned int, unsigned int, unsigned int);
unsigned int NNS_SndPlayerSetTrackMute(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_212c59c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_212c5a0: cmp_a = r0; cmp_b = 0x0u;
L_212c5ac: if ((cmp_a == cmp_b)) { return r0; }
L_212c5b0: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r0 + 60));
L_212c5b4: r0 = func_02020af8(r0,r1,r2);
L_212c5c0: return r0;
}
