/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Anim_GetBlock(unsigned int, unsigned int);
unsigned int Anim_LoadFindAnimationBlock(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_2013c1c: r6 = r0;
L_2013c20: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 0));
L_2013c24: r5 = r2;
L_2013c28: cmp_a = r0; cmp_b = r1;
L_2013c2c: if ((cmp_a != cmp_b)) { goto L_2013c6c; }
L_2013c30: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r6 + 14));
L_2013c34: r4 = 0x0u;
L_2013c38: cmp_a = r0; cmp_b = 0x0u;
L_2013c3c: if ((cmp_a <= cmp_b)) { goto L_2013c6c; }
L_2013c40: r0 = r6;
L_2013c44: r1 = r4;
L_2013c48: r0 = Anim_GetBlock(r0,r1);
L_2013c4c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2013c50: cmp_a = r1; cmp_b = r5;
L_2013c58: if ((cmp_a == cmp_b)) { return r0; }
L_2013c5c: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r6 + 14));
L_2013c60: r4 = (r4+0x1u);
L_2013c64: cmp_a = r4; cmp_b = r0;
L_2013c68: if ((cmp_a < cmp_b)) { goto L_2013c40; }
L_2013c6c: r0 = 0x0u;
L_2013c74: return r0;
}
