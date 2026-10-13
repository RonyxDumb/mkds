/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ec450(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020d26f8(unsigned int, unsigned int);
unsigned int func_020e5ba0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_20e5ba4: r6 = r0;
L_20e5ba8: r5 = r1;
L_20e5bac: r4 = r3;
L_20e5bb0: r0 = func_020ec450(r0,r1,r2);
L_20e5bb4: cmp_a = r0; cmp_b = 0x0u;
L_20e5bb8: if ((cmp_a == cmp_b)) { goto L_20e5bc8; }
L_20e5bbc: r0 = r6;
L_20e5bc0: r1 = r5;
L_20e5bc4: r0 = func_020d26f8(r0,r1);
L_20e5bc8: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20e5bd0: return r0;
}
