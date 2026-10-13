/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02148f64(void);
unsigned int func_0214b3f8(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214b400: r0 = func_02148f64();
L_214b404: r1 = 0x21802e4u;
L_214b408: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_214b414: return r0;
}
