/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_0214f1f4(unsigned int, unsigned int);
extern unsigned int func_0214eed8(void);
unsigned int func_0214f1b0(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_214f1b8: r0 = 0x214eef0u;
L_214f1bc: r1 = 0x0u;
L_214f1c0: r0 = func_0214f1f4(r0,r1);
L_214f1c4: r1 = 0x2180414u;
L_214f1c8: cmp_a = r0; cmp_b = 0x0u;
L_214f1cc: *(unsigned int *)((unsigned char *)r1 + 12) = (unsigned int)r0;
L_214f1d0: if ((cmp_a != cmp_b)) { goto L_214f1d8; }
L_214f1d4: r0 = func_0214eed8();
L_214f1d8: r0 = 0x2180414u;
L_214f1dc: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_214f1e8: return r0;
}
