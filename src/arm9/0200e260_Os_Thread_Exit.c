/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_DisableIrq(void);
extern unsigned int Os_Thread_ExitImpl(unsigned int, unsigned int);
unsigned int Os_Thread_Exit(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_200e268: r0 = Os_DisableIrq();
L_200e26c: r0 = 0x216ff5cu;
L_200e270: r1 = 0x0u;
L_200e274: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 4));
L_200e278: r0 = Os_Thread_ExitImpl(r0,r1);
L_200e284: return r0;
}
