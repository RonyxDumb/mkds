/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020a305c(void);
unsigned int func_020a4c20(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20a4c28: r0 = 0x21759c0u;
L_20a4c2c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20a4c30: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 8));
L_20a4c34: cmp_a = r0; cmp_b = 0x2u;
L_20a4c40: if ((cmp_a != cmp_b)) { return r0; }
L_20a4c44: r0 = func_020a305c();
L_20a4c50: return r0;
}
