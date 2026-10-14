/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020f7184(unsigned int, unsigned int, unsigned int);
extern unsigned int func_020fe7a0(unsigned int, unsigned int, unsigned int, unsigned int);
unsigned int func_020f7070(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_20f7078: r5 = r0;
L_20f707c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 116));
L_20f7080: r4 = r1;
L_20f7084: r1 = (r2&0x8000000u); cmp_a = r1; cmp_b = 0;
L_20f7088: if ((cmp_a != cmp_b)) { goto L_20f70a4; }
L_20f708c: r1 = 0x1u;
L_20f7090: r2 = 0x0u;
L_20f7094: r0 = func_020f7184(r0,r1,r2);
L_20f70a0: return r0;
L_20f70a4: r1 = 0x1u;
L_20f70a8: r2 = 0x0u;
L_20f70ac: r0 = func_020f7184(r0,r1,r2);
L_20f70b0: cmp_a = r0; cmp_b = 0x0u;
L_20f70bc: if ((cmp_a != cmp_b)) { return r0; }
L_20f70c0: cmp_a = r4; cmp_b = 0x0u;
L_20f70cc: if ((cmp_a == cmp_b)) { return r0; }
L_20f70d0: r3 = (unsigned int)(*(short *)((unsigned char *)r5 + 78));
L_20f70d4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 68));
L_20f70d8: r1 = 0x1u;
L_20f70dc: r2 = 0x8u;
L_20f70e0: r0 = func_020fe7a0(r0,r1,r2,r3);
L_20f70ec: return r0;
}
