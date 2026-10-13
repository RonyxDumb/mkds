/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */

unsigned int OamBuffer_ResetValues16_from_thumb(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20ae6ac: cmp_a = r0; cmp_b = 0x0u;
L_20ae6ae: if ((cmp_a == cmp_b)) { goto L_20ae6ba; }
L_20ae6b0: r3 = 0x0u; cmp_a = r3; cmp_b = 0;
L_20ae6b2: r2 = 0x400u;
L_20ae6b4: *(unsigned short *)((unsigned char *)r0 + (0 + r2)) = (unsigned short)r3;
L_20ae6b6: r2 = 0x402u;
L_20ae6b8: *(unsigned short *)((unsigned char *)r0 + (0 + r2)) = (unsigned short)r3;
L_20ae6ba: cmp_a = r1; cmp_b = 0x0u;
L_20ae6bc: if ((cmp_a == cmp_b)) { goto L_20ae6c8; }
L_20ae6be: r2 = 0x0u; cmp_a = r2; cmp_b = 0;
L_20ae6c0: r0 = 0x400u;
L_20ae6c2: *(unsigned short *)((unsigned char *)r1 + (0 + r0)) = (unsigned short)r2;
L_20ae6c4: r0 = 0x402u;
L_20ae6c6: *(unsigned short *)((unsigned char *)r1 + (0 + r0)) = (unsigned short)r2;
L_20ae6c8: return r0;
}
