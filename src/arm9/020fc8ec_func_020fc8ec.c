/* Verified complete local bytes after resolving all relocations. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020fcb9c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020fc8ec(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20fc8f0: r4 = r0;
L_20fc8f4: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 552));
L_20fc8f8: cmp_a = r2; cmp_b = 0x0u;
L_20fc900: if ((cmp_a != cmp_b)) { return r0; }
L_20fc904: r0 = func_020fcb9c(r0,r1,r2,r3);
L_20fc908: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 552));
L_20fc90c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 116));
L_20fc910: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 508));
L_20fc914: r0 = (r0&0x40000000u); cmp_a = r0; cmp_b = 0;
L_20fc918: if ((cmp_a != cmp_b)) { goto L_20fc928; }
L_20fc91c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 72));
L_20fc920: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_20fc924: if ((cmp_a == cmp_b)) { goto L_20fc930; }
L_20fc928: r1 = 0x2u;
L_20fc92c: goto L_20fc934;
L_20fc930: r1 = 0x3u;
L_20fc934: r0 = (r4+0x200u);
L_20fc938: *(unsigned short *)((unsigned char *)r0 + 248) = (unsigned short)r1;
L_20fc93c: r1 = 0x1u;
L_20fc940: *(unsigned short *)((unsigned char *)r0 + 250) = (unsigned short)r1;
L_20fc948: return r0;
}
