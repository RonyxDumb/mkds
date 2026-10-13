/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Animation_Update(unsigned int);
unsigned int HandleCourseAnim(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_206329c: r0 = 0x217ab1cu;
L_20632a0: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 32));
L_20632a4: cmp_a = r0; cmp_b = 0x0u;
L_20632a8: if ((cmp_a == cmp_b)) { goto L_20632b4; }
L_20632ac: r0 = 0x217ab24u;
L_20632b0: r0 = Animation_Update(r0);
L_20632b4: r0 = 0x217ab1cu;
L_20632b8: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 88));
L_20632bc: cmp_a = r0; cmp_b = 0x0u;
L_20632c0: if ((cmp_a == cmp_b)) { goto L_20632cc; }
L_20632c4: r0 = 0x217ab5cu;
L_20632c8: r0 = Animation_Update(r0);
L_20632cc: r0 = 0x217ab1cu;
L_20632d0: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_20632d4: cmp_a = r1; cmp_b = 0x0u;
L_20632e0: if ((cmp_a == cmp_b)) { return r0; }
L_20632e4: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 144));
L_20632e8: cmp_a = r0; cmp_b = 0x0u;
L_20632f4: if ((cmp_a == cmp_b)) { return r0; }
L_20632f8: r0 = 0x217ab94u;
L_20632fc: r0 = Animation_Update(r0);
L_2063308: return r0;
}
