/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int RegisterFifoMicrophone(void);
extern unsigned int PM_Initialize(void);
extern unsigned int func_0214fb3c(unsigned int);
extern unsigned int func_02020430(unsigned int);
extern unsigned int func_020203d4(unsigned int);
extern unsigned int func_0214fb24(unsigned int);
unsigned int Struct59C4Sub_Initialize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_210f134: r1 = 0x217d1bcu;
L_210f138: r4 = r0;
L_210f13c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_210f140: cmp_a = r0; cmp_b = 0x0u;
L_210f144: if ((cmp_a != cmp_b)) { goto L_210f164; }
L_210f148: r0 = RegisterFifoMicrophone();
L_210f14c: r0 = PM_Initialize();
L_210f150: r0 = 0x1u;
L_210f154: r0 = func_0214fb3c(r0);
L_210f158: r0 = 0x217d1bcu;
L_210f15c: r1 = 0x1u;
L_210f160: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_210f164: r0 = 0x0u;
L_210f168: *(unsigned int *)((unsigned char *)r4 + 1052) = (unsigned int)r0;
L_210f16c: r3 = r0;
L_210f170: *(unsigned char *)((unsigned char *)r4 + (0 + r0)) = (unsigned char)r3;
L_210f174: r0 = (r0+0x1u);
L_210f178: cmp_a = r0; cmp_b = 0x400u;
L_210f17c: if (((int)cmp_a < (int)cmp_b)) { goto L_210f170; }
L_210f180: r0 = 0x2u;
L_210f184: *(unsigned int *)((unsigned char *)r4 + 1024) = (unsigned int)r0;
L_210f188: r0 = (r4+0x400u);
L_210f18c: *(unsigned int *)((unsigned char *)r0 + 4) = (unsigned int)r4;
L_210f190: r2 = 0x400u;
L_210f194: r1 = 0x105du;
L_210f198: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r2;
L_210f19c: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r1;
L_210f1a0: r1 = 0x1u;
L_210f1a4: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)r1;
L_210f1a8: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r3;
L_210f1ac: *(unsigned int *)((unsigned char *)r0 + 24) = (unsigned int)r3;
L_210f1b0: r0 = func_02020430(r0);
L_210f1b4: r0 = 0x0u;
L_210f1b8: r0 = func_020203d4(r0);
L_210f1bc: r0 = 0x3u;
L_210f1c0: r0 = func_0214fb24(r0);
L_210f1c8: return r0;
}
