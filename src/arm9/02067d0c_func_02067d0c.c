/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_27(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
extern unsigned int func_02081e3c(unsigned int, unsigned int, unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02067d0c(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2067d14: r4 = r1;
L_2067d18: r1 = 0x2u;
L_2067d1c: r2 = 0x0u;
L_2067d20: r5 = r0;
L_2067d24: r0 = StructMQRacerEntry_SomeFn_27(r0,r1,r2);
L_2067d28: cmp_a = r0; cmp_b = 0x0u;
L_2067d2c: if ((cmp_a == cmp_b)) { goto L_2067d70; }
L_2067d30: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 124));
L_2067d34: r0 = (r0&0x10u); cmp_a = r0; cmp_b = 0;
L_2067d38: if ((cmp_a == cmp_b)) { goto L_2067d54; }
L_2067d3c: r1 = (r5+0x80u);
L_2067d40: r0 = 0x4fu;
L_2067d44: r0 = func_0208b7bc(r0,r1);
L_2067d48: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r5 + 116));
L_2067d4c: r2 = 0x46u;
L_2067d50: r0 = func_02081e3c(r0,r1,r2);
L_2067d54: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 124));
L_2067d58: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2067d5c: if ((cmp_a == cmp_b)) { goto L_2067d70; }
L_2067d60: r0 = GetGlobalRK();
L_2067d64: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_2067d68: r1 = (r1+0x1u);
L_2067d6c: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_2067d70: r0 = 0x5u;
L_2067d74: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067d78: r0 = 0x0u;
L_2067d84: return r0;
}
