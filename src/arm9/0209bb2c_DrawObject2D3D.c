/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ff9048(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ea5b0(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020ea670(unsigned int, unsigned int);
extern unsigned int func_020ea7cc(unsigned int, unsigned int);
extern unsigned int func_020ea618(unsigned int, unsigned int);
unsigned int DrawObject2D3D(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_209bb34: r4 = r2;
L_209bb38: r5 = r1;
L_209bb3c: r0 = 0x1bu;
L_209bb40: r2 = 0x3u;
L_209bb44: r0 = func_01ff9048(r0,r1,r2);
L_209bb48: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_209bb4c: cmp_a = r0; cmp_b = 0x0u;
L_209bb50: if ((cmp_a == cmp_b)) { goto L_209bb60; }
L_209bb54: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bb58: r2 = 0x0u;
L_209bb5c: r0 = func_020ea5b0(r0,r1,r2);
L_209bb60: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 16));
L_209bb64: cmp_a = r0; cmp_b = 0x0u;
L_209bb68: if ((cmp_a != cmp_b)) { goto L_209bb80; }
L_209bb6c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209bb70: cmp_a = r1; cmp_b = 0x0u;
L_209bb7c: if ((cmp_a == cmp_b)) { return r0; }
L_209bb80: cmp_a = r0; cmp_b = 0x0u;
L_209bb84: if ((cmp_a == cmp_b)) { goto L_209bba8; }
L_209bb88: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 36));
L_209bb8c: cmp_a = r1; cmp_b = 0x0u;
L_209bb90: if ((cmp_a == cmp_b)) { goto L_209bba0; }
L_209bb94: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bb98: r0 = func_020ea670(r0,r1);
L_209bb9c: goto L_209bba8;
L_209bba0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bba4: r0 = func_020ea7cc(r0,r1);
L_209bba8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209bbac: cmp_a = r0; cmp_b = 0x0u;
L_209bbb8: if ((cmp_a == cmp_b)) { return r0; }
L_209bbbc: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 102));
L_209bbc0: r0 = func_020ea618(r0,r1);
L_209bbcc: return r0;
}
