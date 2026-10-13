/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_Terminate(void);
unsigned int MIi_CheckDma0SourceAddress(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214c780: cmp_a = r0; cmp_b = 0x0u;
L_214c78c: if ((cmp_a != cmp_b)) { return r0; }
L_214c790: cmp_a = r3; cmp_b = 0x0u;
L_214c794: r0 = (r1&0xff000000u);
L_214c798: if ((cmp_a == cmp_b)) { goto L_214c7a8; }
L_214c79c: cmp_a = r3; cmp_b = 0x800000u;
L_214c7a0: if ((cmp_a == cmp_b)) { r1 = (r1-r2); }
L_214c7a4: goto L_214c7ac;
L_214c7a8: r1 = (r1+r2);
L_214c7ac: cmp_a = r0; cmp_b = 0x4000000u;
L_214c7b0: if ((cmp_a == cmp_b)) { goto L_214c7d8; }
L_214c7b4: cmp_a = r0; cmp_b = 0x8000000u;
L_214c7b8: if ((cmp_a >= cmp_b)) { goto L_214c7d8; }
L_214c7bc: r0 = (r1&0xff000000u);
L_214c7c0: cmp_a = r0; cmp_b = 0x4000000u;
L_214c7c4: if ((cmp_a == cmp_b)) { goto L_214c7d8; }
L_214c7c8: cmp_a = r0; cmp_b = 0x8000000u;
L_214c7d4: if ((cmp_a < cmp_b)) { return r0; }
L_214c7d8: r0 = Os_Terminate();
L_214c7e4: return r0;
}
