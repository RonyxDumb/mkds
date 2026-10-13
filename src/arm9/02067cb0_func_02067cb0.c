/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StructMQRacerEntry_SomeFn_65(unsigned int);
extern unsigned int GetGlobalRK(void);
unsigned int func_02067cb0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5;
L_2067cb8: r5 = r0;
L_2067cbc: r4 = r1;
L_2067cc0: r0 = StructMQRacerEntry_SomeFn_65(r0);
L_2067cc4: cmp_a = r0; cmp_b = 0x0u;
L_2067cc8: if ((cmp_a == cmp_b)) { goto L_2067cf4; }
L_2067ccc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 124));
L_2067cd0: r0 = (r0&0x1u); cmp_a = r0; cmp_b = 0;
L_2067cd4: if ((cmp_a == cmp_b)) { goto L_2067ce8; }
L_2067cd8: r0 = GetGlobalRK();
L_2067cdc: r1 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 20));
L_2067ce0: r1 = (r1+0x1u);
L_2067ce4: *(unsigned int *)((unsigned char *)r0 + 20) = (unsigned int)r1;
L_2067ce8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r5 + 72));
L_2067cec: r0 = (r0|0x20000u);
L_2067cf0: *(unsigned int *)((unsigned char *)r5 + 72) = (unsigned int)r0;
L_2067cf4: r0 = 0x7u;
L_2067cf8: *(unsigned int *)((unsigned char *)r4 + 0) = (unsigned int)r0;
L_2067cfc: r0 = 0x2u;
L_2067d08: return r0;
}
