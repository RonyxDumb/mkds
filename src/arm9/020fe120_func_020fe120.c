/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f68b0(unsigned int);
extern unsigned int func_020f63cc(unsigned int);
unsigned int func_020fe120(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20fe124: r4 = r0;
L_20fe128: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20fe12c: r1 = (r2&0x8000u); cmp_a = r1; cmp_b = 0;
L_20fe130: if ((cmp_a == cmp_b)) { goto L_20fe140; }
L_20fe134: r0 = func_020f68b0(r0);
L_20fe13c: return r0;
L_20fe140: r1 = (r2&0x4000u); cmp_a = r1; cmp_b = 0;
L_20fe148: if ((cmp_a == cmp_b)) { return r0; }
L_20fe14c: r0 = func_020f63cc(r0);
L_20fe150: r0 = 0x5au;
L_20fe154: *(unsigned int *)((unsigned char *)r4 + 368) = (unsigned int)r0;
L_20fe158: r0 = 0x0u;
L_20fe15c: *(unsigned int *)((unsigned char *)r4 + 372) = (unsigned int)r0;
L_20fe164: return r0;
}
