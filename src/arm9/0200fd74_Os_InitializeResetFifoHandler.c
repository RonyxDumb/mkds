/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0214d5b8(void);
extern unsigned int Fifo_IsHandlerReady(unsigned int, unsigned int);
extern unsigned int Fifo_RegisterHandler(unsigned int, unsigned int);
unsigned int Os_InitializeResetFifoHandler(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_200fd7c: r0 = 0x217027cu;
L_200fd80: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_200fd84: cmp_a = r1; cmp_b = 0x0u;
L_200fd90: if ((cmp_a != cmp_b)) { return r0; }
L_200fd94: r1 = 0x1u;
L_200fd98: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_200fd9c: r0 = func_0214d5b8();
L_200fda0: r5 = 0xcu;
L_200fda4: r4 = 0x1u;
L_200fda8: r0 = r5;
L_200fdac: r1 = r4;
L_200fdb0: r0 = Fifo_IsHandlerReady(r0,r1);
L_200fdb4: cmp_a = r0; cmp_b = 0x0u;
L_200fdb8: if ((cmp_a == cmp_b)) { goto L_200fda8; }
L_200fdbc: r1 = 0x200fd30u;
L_200fdc0: r0 = 0xcu;
L_200fdc4: r0 = Fifo_RegisterHandler(r0,r1);
L_200fdd0: return r0;
}
