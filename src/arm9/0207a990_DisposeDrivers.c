/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DriverContext_Dispose(unsigned int);
unsigned int DisposeDrivers(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,r7,r8;
L_207a994: r7 = 0x217ad14u;
L_207a998: r4 = 0x0u;
L_207a99c: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r7 + 0));
L_207a9a0: cmp_a = r0; cmp_b = 0x0u;
L_207a9a4: if (((int)cmp_a <= (int)cmp_b)) { goto L_207a9d4; }
L_207a9a8: r6 = 0x217ad18u;
L_207a9ac: r5 = 0x5a8u;
L_207a9b0: r8 = r4;
L_207a9b4: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 0));
L_207a9b8: r0 = (r0+r8);
L_207a9bc: r0 = DriverContext_Dispose(r0);
L_207a9c0: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r7 + 0));
L_207a9c4: r4 = (r4+0x1u);
L_207a9c8: r8 = (r8+r5);
L_207a9cc: cmp_a = r4; cmp_b = r0;
L_207a9d0: if (((int)cmp_a < (int)cmp_b)) { goto L_207a9b4; }
L_207a9d4: r0 = 0x217ad18u;
L_207a9d8: r1 = 0x0u;
L_207a9dc: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_207a9e4: return r0;
}
