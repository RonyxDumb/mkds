/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02148f8c(void);
unsigned int func_0214b4dc(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214b4e4: r0 = func_02148f8c();
L_214b4e8: r1 = 0x21802ccu;
L_214b4ec: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_214b4f8: return r0;
}
