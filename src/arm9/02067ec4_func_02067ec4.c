/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_27(unsigned int, unsigned int, unsigned int);
extern unsigned int func_0208b7bc(unsigned int, unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02067ec4(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2067ecc: r5 = r0;
L_2067ed0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 676));
L_2067ed4: r4 = r1;
L_2067ed8: cmp_a = r0; cmp_b = 0x3000u;
L_2067edc: if (((int)cmp_a > (int)cmp_b)) { goto L_2067eec; }
L_2067ee0: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r2 + 2));
L_2067ee4: r0 = (r0&0x200u); cmp_a = r0; cmp_b = 0;
L_2067ee8: if ((cmp_a == cmp_b)) { goto L_2067f60; }
L_2067eec: r0 = r5;
L_2067ef0: r1 = 0x1u;
L_2067ef4: r2 = 0x0u;
L_2067ef8: r0 = StructMQRacerEntry_SomeFn_27(r0,r1,r2);
L_2067efc: cmp_a = r0; cmp_b = 0x0u;
L_2067f00: if ((cmp_a == cmp_b)) { goto L_2067f54; }
L_2067f04: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 1424));
L_2067f08: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 88));
L_2067f0c: cmp_a = r0; cmp_b = 0x0u;
L_2067f10: if ((cmp_a != cmp_b)) { goto L_2067f38; }
L_2067f14: r1 = (r5+0x80u);
L_2067f18: r0 = 0xcu;
L_2067f1c: r0 = func_0208b7bc(r0,r1);
L_2067f20: r1 = (r5+0x80u);
L_2067f24: r0 = 0xdu;
L_2067f28: r0 = func_0208b7bc(r0,r1);
L_2067f2c: r1 = (r5+0x80u);
L_2067f30: r0 = 0xeu;
L_2067f34: r0 = func_0208b7bc(r0,r1);
L_2067f38: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 124));
L_2067f3c: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2067f40: if ((cmp_a == cmp_b)) { goto L_2067f54; }
L_2067f44: r0 = GetGlobalRK();
L_2067f48: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_2067f4c: r1 = (r1+0x1u);
L_2067f50: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_2067f54: r0 = 0x3u;
L_2067f58: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067f5c: goto L_2067f68;
L_2067f60: r0 = 0x2u;
L_2067f64: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067f68: r0 = 0xbu;
L_2067f74: return r0;
}
