/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020cb9b8(void);
extern unsigned int ResetRacersForTimeTrial(void);
unsigned int Scene_Menu_Finalize(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2039f64: r0 = func_020cb9b8();
L_2039f68: r0 = 0x21759d0u;
L_2039f6c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2039f70: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r1 + 80));
L_2039f74: r0 = (r0&~(0x1u));
L_2039f78: *(unsigned short *)((unsigned char *)r1 + 80) = (unsigned short)r0;
L_2039f7c: r0 = ResetRacersForTimeTrial();
L_2039f88: return r0;
}
