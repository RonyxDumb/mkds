/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0214d5b8(void);
extern unsigned int Fifo_IsHandlerReady(unsigned int, unsigned int);
extern unsigned int Fifo_RegisterHandler(unsigned int, unsigned int);
unsigned int Os_InitializeTouchPanelFifo(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_214eb90: r0 = 0x21803d4u;
L_214eb94: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 0));
L_214eb98: cmp_a = r1; cmp_b = 0x0u;
L_214eba4: if ((cmp_a != cmp_b)) { return r0; }
L_214eba8: r1 = 0x1u;
L_214ebac: *(unsigned short *)((unsigned char *)r0 + 0) = (unsigned short)r1;
L_214ebb0: r0 = func_0214d5b8();
L_214ebb4: r0 = 0x21803d8u;
L_214ebb8: r1 = 0x0u;
L_214ebbc: *(unsigned short *)((unsigned char *)r0 + 50) = (unsigned short)r1;
L_214ebc0: *(unsigned short *)((unsigned char *)r0 + 54) = (unsigned short)r1;
L_214ebc4: *(unsigned short *)((unsigned char *)r0 + 12) = (unsigned short)r1;
L_214ebc8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_214ebcc: *(unsigned int *)((unsigned char *)r0 + 16) = (unsigned int)r1;
L_214ebd0: *(unsigned short *)((unsigned char *)r0 + 48) = (unsigned short)r1;
L_214ebd4: *(unsigned short *)((unsigned char *)r0 + 52) = (unsigned short)r1;
L_214ebd8: r5 = 0x6u;
L_214ebdc: r4 = 0x1u;
L_214ebe0: r0 = r5;
L_214ebe4: r1 = r4;
L_214ebe8: r0 = Fifo_IsHandlerReady(r0,r1);
L_214ebec: cmp_a = r0; cmp_b = 0x0u;
L_214ebf0: if ((cmp_a == cmp_b)) { goto L_214ebe0; }
L_214ebf4: r1 = 0x214ec18u;
L_214ebf8: r0 = 0x6u;
L_214ebfc: r0 = Fifo_RegisterHandler(r0,r1);
L_214ec08: return r0;
}
