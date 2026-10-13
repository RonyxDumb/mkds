/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */

unsigned int func_0211ff74(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_211ff74: r0 = 0x217d384u;
L_211ff78: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_211ff7c: r0 = (r0+0x1000u);
L_211ff80: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 3896));
L_211ff84: cmp_a = r0; cmp_b = 0x0u;
L_211ff88: if ((cmp_a == cmp_b)) { return r0; }
L_211ff8c: r0 = 0x217aa14u;
L_211ff90: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_211ff94: r0 = (r0+0x700u);
L_211ff98: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 92));
L_211ff9c: r1 = (r1&~(0x4u));
L_211ffa0: *(unsigned short *)((unsigned char *)r0 + 92) = (unsigned short)r1;
L_211ffa4: return r0;
}
