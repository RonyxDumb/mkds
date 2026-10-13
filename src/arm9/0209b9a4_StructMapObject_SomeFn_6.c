/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Maybe_helper_01308c(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int StructMapObject_SomeFn_6(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_209b9ac: r5 = r0;
L_209b9b0: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 12));
L_209b9b4: r4 = r1;
L_209b9b8: cmp_a = r2; cmp_b = 0x0u;
L_209b9bc: if ((cmp_a == cmp_b)) { goto L_209b9d8; }
L_209b9c0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 20));
L_209b9c4: r0 = (r0&~(0x1f0000u));
L_209b9c8: *(unsigned int *)((unsigned char *)r2 + 20) = (unsigned int)r0;
L_209b9cc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r2 + 20));
L_209b9d0: r0 = (r0|(r4 << 16));
L_209b9d4: *(unsigned int *)((unsigned char *)r2 + 20) = (unsigned int)r0;
L_209b9d8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 16));
L_209b9dc: cmp_a = r0; cmp_b = 0x0u;
L_209b9e0: if ((cmp_a == cmp_b)) { goto L_209b9f0; }
L_209b9e4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_209b9e8: r1 = r4;
L_209b9ec: r0 = Maybe_helper_01308c(r0,r1,r2,r3);
L_209b9f0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 20));
L_209b9f4: cmp_a = r0; cmp_b = 0x0u;
L_209b9f8: if ((cmp_a != cmp_b)) { *(unsigned short *)((unsigned char *)r0 + 110) = (unsigned short)r4; }
L_209ba04: return r0;
}
