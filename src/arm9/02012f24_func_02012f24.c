/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int G3X_Initialize(void);
extern unsigned int func_02011074(void);
unsigned int func_02012f24(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2012f2c: r0 = G3X_Initialize();
L_2012f30: r0 = func_02011074();
L_2012f34: r1 = 0x4000600u;
L_2012f38: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_2012f3c: r0 = (r0&~(0xc0000000u));
L_2012f40: r0 = (r0|0x80000000u);
L_2012f44: *(unsigned int *)((unsigned char *)r1 + 0) = (unsigned int)r0;
L_2012f50: return r0;
}
