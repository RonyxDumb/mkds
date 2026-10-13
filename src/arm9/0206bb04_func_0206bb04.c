/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int DriverContext_UpdateCharacterAnimation(unsigned int, unsigned int, unsigned int);
extern unsigned int func_02088c7c(unsigned int);
unsigned int func_0206bb04(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_206bb08: r4 = r0;
L_206bb0c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 76));
L_206bb10: r1 = (r1&0x20u); cmp_a = r1; cmp_b = 0;
L_206bb18: if ((cmp_a != cmp_b)) { return r0; }
L_206bb1c: r2 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_206bb20: r1 = (r4+0x200u);
L_206bb24: r2 = (r2|0x44000u);
L_206bb28: *(unsigned int *)((unsigned char *)r4 + 72) = (unsigned int)r2;
L_206bb2c: r2 = 0xau;
L_206bb30: *(unsigned short *)((unsigned char *)r1 + 58) = (unsigned short)r2;
L_206bb34: r1 = 0x0u;
L_206bb38: *(unsigned int *)((unsigned char *)r4 + 384) = (unsigned int)r1;
L_206bb3c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 76));
L_206bb40: r2 = 0x1u;
L_206bb44: r3 = (r3&~(0x30u));
L_206bb48: *(unsigned int *)((unsigned char *)r4 + 76) = (unsigned int)r3;
L_206bb4c: r3 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 72));
L_206bb50: r3 = (r3&~(0x20000u));
L_206bb54: *(unsigned int *)((unsigned char *)r4 + 72) = (unsigned int)r3;
L_206bb58: r0 = DriverContext_UpdateCharacterAnimation(r0,r1,r2);
L_206bb5c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 68));
L_206bb60: r0 = (r0|0x80000000u);
L_206bb64: *(unsigned int *)((unsigned char *)r4 + 68) = (unsigned int)r0;
L_206bb68: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 124));
L_206bb6c: r0 = (r0&0x2u); cmp_a = r0; cmp_b = 0;
L_206bb74: if ((cmp_a == cmp_b)) { return r0; }
L_206bb78: r0 = 0x21759c0u;
L_206bb7c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_206bb80: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 8));
L_206bb84: cmp_a = r0; cmp_b = 0x2u;
L_206bb8c: if ((cmp_a != cmp_b)) { return r0; }
L_206bb90: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 24));
L_206bb94: cmp_a = r0; cmp_b = 0x0u;
L_206bb9c: if ((cmp_a != cmp_b)) { return r0; }
L_206bba0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 784));
L_206bba4: r0 = func_02088c7c(r0);
L_206bbac: return r0;
}
