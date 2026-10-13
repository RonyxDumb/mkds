/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020e24d0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020e246c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e2470: r2 = (unsigned int)(*(unsigned char *)((unsigned char *)r2 + 0));
L_20e2474: r4 = r3;
L_20e2478: cmp_a = r2; cmp_b = 0x1u;
L_20e247c: if ((cmp_a != cmp_b)) { goto L_20e2488; }
L_20e2480: r1 = (r1+0x50u);
L_20e2484: r0 = func_020e24d0(r0,r1,r2,r3);
L_20e2488: r0 = (unsigned int)(*(unsigned char *)((unsigned char *)r4 + 0));
L_20e2490: return r0;
}
