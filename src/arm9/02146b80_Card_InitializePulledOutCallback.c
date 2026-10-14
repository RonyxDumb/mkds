/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0214d5b8(void);
extern unsigned int Fifo_RegisterHandler(unsigned int, unsigned int);
unsigned int Card_InitializePulledOutCallback(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2146b88: r0 = func_0214d5b8();
L_2146b8c: r1 = 0x2146b14u;
L_2146b90: r0 = 0xeu;
L_2146b94: r0 = Fifo_RegisterHandler(r0,r1);
L_2146b98: r0 = 0x21802a4u;
L_2146b9c: r1 = 0x0u;
L_2146ba0: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_2146bac: return r0;
}
