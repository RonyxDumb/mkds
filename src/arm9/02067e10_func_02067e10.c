/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_27(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02067e10(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2067e18: r5 = r0;
L_2067e1c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 676));
L_2067e20: r4 = r1;
L_2067e24: cmp_a = r0; cmp_b = 0x3000u;
L_2067e28: if (((int)cmp_a > (int)cmp_b)) { goto L_2067e38; }
L_2067e2c: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r2 + 2));
L_2067e30: r0 = (r0&0x200u); cmp_a = r0; cmp_b = 0;
L_2067e34: if ((cmp_a == cmp_b)) { goto L_2067eac; }
L_2067e38: r0 = r5;
L_2067e3c: r1 = 0x2u;
L_2067e40: r2 = 0x0u;
L_2067e44: r0 = StructMQRacerEntry_SomeFn_27(r0,r1,r2);
L_2067e48: cmp_a = r0; cmp_b = 0x0u;
L_2067e4c: if ((cmp_a == cmp_b)) { goto L_2067ea0; }
L_2067e50: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 1424));
L_2067e54: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 88));
L_2067e58: cmp_a = r0; cmp_b = 0x0u;
L_2067e5c: if ((cmp_a != cmp_b)) { goto L_2067e84; }
L_2067e60: r1 = (r5+0x80u);
L_2067e64: r0 = 0xcu;
L_2067e68: r0 = func_0208b7bc(r0,r1);
L_2067e6c: r1 = (r5+0x80u);
L_2067e70: r0 = 0xdu;
L_2067e74: r0 = func_0208b7bc(r0,r1);
L_2067e78: r1 = (r5+0x80u);
L_2067e7c: r0 = 0xeu;
L_2067e80: r0 = func_0208b7bc(r0,r1);
L_2067e84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 124));
L_2067e88: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2067e8c: if ((cmp_a == cmp_b)) { goto L_2067ea0; }
L_2067e90: r0 = GetGlobalRK();
L_2067e94: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_2067e98: r1 = (r1+0x1u);
L_2067e9c: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_2067ea0: r0 = 0x4u;
L_2067ea4: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067ea8: goto L_2067eb4;
L_2067eac: r0 = 0x2u;
L_2067eb0: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067eb4: r0 = 0xbu;
L_2067ec0: return r0;
}
