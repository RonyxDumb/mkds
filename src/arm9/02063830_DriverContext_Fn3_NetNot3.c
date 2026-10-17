/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0207a870(void);
extern unsigned int func_0203c1a8(unsigned int, unsigned int);
extern unsigned int StructMQRacerEntry_SomeFn_89(unsigned int);
extern unsigned int func_01ffcc50(unsigned int);
unsigned int DriverContext_Fn3_NetNot3(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20637e4: r4 = r0;
L_20637e8: r0 = func_0207a870();
L_20637ec: cmp_a = r0; cmp_b = 0x0u;
L_20637f0: if ((cmp_a == cmp_b)) { goto L_2063800; }
L_20637f4: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 116));
L_20637f8: r0 = (r4+0x80u);
L_20637fc: r0 = func_0203c1a8(r0,r1);
L_2063800: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 76));
L_2063804: r0 = (r0&0x1000u); cmp_a = r0; cmp_b = 0;
L_2063808: if ((cmp_a == cmp_b)) { goto L_2063814; }
L_206380c: r0 = r4;
L_2063810: r0 = StructMQRacerEntry_SomeFn_89(r0);
L_2063814: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 76));
L_2063818: r0 = r4;
L_206381c: r1 = (r1&~(0x1000u));
L_2063820: *(unsigned int *)((unsigned char *)r4 + 76) = (unsigned int)r1;
L_2063824: r0 = func_01ffcc50(r0);
L_206382c: return r0;
}
