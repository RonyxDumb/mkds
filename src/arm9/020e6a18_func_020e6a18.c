/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_01ff9048(unsigned int, unsigned int, unsigned int);
unsigned int func_020e6a18(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_20e6a1c: r4 = r0;
L_20e6a20: r0 = (unsigned int)(*(unsigned short *)((unsigned char *)r4 + 26));
L_20e6a24: cmp_a = r0; cmp_b = 0x1u;
L_20e6a28: if ((cmp_a != cmp_b)) { goto L_20e6a4c; }
L_20e6a2c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 32));
L_20e6a30: r0 = 0x2bu;
L_20e6a34: r2 = 0x1u;
L_20e6a38: r0 = func_01ff9048(r0,r1,r2);
L_20e6a3c: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r4 + 28));
L_20e6a40: r0 = 0x2au;
L_20e6a44: r2 = 0x1u;
L_20e6a48: r0 = func_01ff9048(r0,r1,r2);
L_20e6a4c: r1 = (r4+0xcu);
L_20e6a50: r0 = 0x30u;
L_20e6a54: r2 = 0x1u;
L_20e6a58: r0 = func_01ff9048(r0,r1,r2);
L_20e6a5c: r1 = (r4+0x10u);
L_20e6a60: r0 = 0x31u;
L_20e6a64: r2 = 0x1u;
L_20e6a68: r0 = func_01ff9048(r0,r1,r2);
L_20e6a70: return r0;
}
