/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_02055fc8(void);
extern unsigned int ConfigureDispcntDisplay(unsigned int, unsigned int, unsigned int);
unsigned int func_02055f68(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2055f70: r0 = 0x217aa04u;
L_2055f74: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2055f78: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_2055f7c: cmp_a = r0; cmp_b = 0x1u;
L_2055f80: if ((cmp_a == cmp_b)) { goto L_2055f98; }
L_2055f84: cmp_a = r0; cmp_b = 0x2u;
L_2055f88: if ((cmp_a == cmp_b)) { goto L_2055fa8; }
L_2055f94: return r0;
L_2055f98: r0 = func_02055fc8();
L_2055fa4: return r0;
L_2055fa8: r0 = 0xeu;
L_2055fac: r1 = 0x0u;
L_2055fb0: r2 = 0x1u;
L_2055fb4: r0 = ConfigureDispcntDisplay(r0,r1,r2);
L_2055fc0: return r0;
}
