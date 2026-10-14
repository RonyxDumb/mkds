/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int RegisterFifoMicrophone(void);
extern unsigned int PM_Initialize(void);
extern unsigned int func_0214fb3c(unsigned int);
unsigned int InitializeBalloonHardware(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_210f1dc: r0 = RegisterFifoMicrophone();
L_210f1e0: r0 = PM_Initialize();
L_210f1e4: r0 = 0x1u;
L_210f1e8: r0 = func_0214fb3c(r0);
L_210f1ec: r0 = 0x217d1bcu;
L_210f1f0: r1 = 0x1u;
L_210f1f4: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_210f200: return r0;
}
