/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int ResetSomeVram(void);
unsigned int ResetDisplayConfig(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2037a9c: r0 = ResetSomeVram();
L_2037aa0: r0 = 0x21755a0u;
L_2037aa4: r1 = 0x0u;
L_2037aa8: *(unsigned int *)((unsigned char *)r0 + 0) = (unsigned int)r1;
L_2037ab4: return r0;
}
