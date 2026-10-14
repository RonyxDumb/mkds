/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int MI_DmaCopy16(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int CopyMemory16(unsigned int, unsigned int, unsigned int);
unsigned int CopyPaletteTop(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip,lr,r4;
L_214c164: r3 = 0x216f074u;
L_214c168: r4 = r0;
L_214c16c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 0));
L_214c170: ip = ~(0x0u);
L_214c174: lr = r1;
L_214c178: r3 = r2;
L_214c17c: cmp_a = r0; cmp_b = ip;
L_214c180: if ((cmp_a == cmp_b)) { goto L_214c1a0; }
L_214c184: cmp_a = r3; cmp_b = 0x1cu;
L_214c188: if ((cmp_a <= cmp_b)) { goto L_214c1a0; }
L_214c18c: r1 = r4;
L_214c190: r2 = (lr+0x5000000u);
L_214c194: r0 = MI_DmaCopy16(r0,r1,r2,r3);
L_214c19c: return r0;
L_214c1a0: r0 = r4;
L_214c1a4: r2 = r3;
L_214c1a8: r1 = (lr+0x5000000u);
L_214c1ac: r0 = CopyMemory16(r0,r1,r2);
L_214c1b4: return r0;
}
