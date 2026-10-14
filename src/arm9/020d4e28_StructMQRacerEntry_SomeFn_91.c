/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_47(unsigned int, unsigned int, unsigned int);
unsigned int StructMQRacerEntry_SomeFn_91(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,ip;
L_20d4e30: r2 = (r2&0x4u); cmp_a = r2; cmp_b = 0;
L_20d4e34: if ((cmp_a == cmp_b)) { goto L_20d4e64; }
L_20d4e38: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d4e3c: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d4e48: if ((cmp_a == cmp_b)) { return r0; }
L_20d4e4c: r1 = 0x2u;
L_20d4e50: r2 = 0x1u;
L_20d4e54: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d4e60: return r0;
L_20d4e64: r3 = 0x217b4f8u;
L_20d4e68: r2 = 0x12c000u;
L_20d4e6c: ip = (unsigned int)(*(unsigned int *)((unsigned char *)r3 + 12));
L_20d4e70: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 4));
L_20d4e74: r1 = (0x0u-r2);
L_20d4e78: r2 = (ip-r3);
L_20d4e7c: cmp_a = r2; cmp_b = r1;
L_20d4e80: if (((int)cmp_a <= (int)cmp_b)) { goto L_20d4ec0; }
L_20d4e84: r1 = 0x217b4f4u;
L_20d4e88: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 0));
L_20d4e8c: cmp_a = r2; cmp_b = r1;
L_20d4e90: if (((int)cmp_a >= (int)cmp_b)) { goto L_20d4ec0; }
L_20d4e94: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d4e98: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d4ea4: if ((cmp_a != cmp_b)) { return r0; }
L_20d4ea8: r1 = 0x2u;
L_20d4eac: r2 = 0x1u;
L_20d4eb0: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d4ebc: return r0;
L_20d4ec0: r1 = (unsigned int)(*(unsigned short *)((unsigned char *)r0 + 52));
L_20d4ec4: r1 = (r1&0x1u); cmp_a = r1; cmp_b = 0;
L_20d4ed0: if ((cmp_a == cmp_b)) { return r0; }
L_20d4ed4: r1 = 0x2u;
L_20d4ed8: r2 = 0x1u;
L_20d4edc: r0 = StructMQRacerEntry_SomeFn_47(r0,r1,r2);
L_20d4ee8: return r0;
}
