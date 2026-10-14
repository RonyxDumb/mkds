/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int StateDualHandler_SetState(unsigned int, unsigned int);
unsigned int func_020e7a40(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20e7a48: r0 = 0x21759c0u;
L_20e7a4c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20e7a50: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 12));
L_20e7a54: cmp_a = r0; cmp_b = 0x6u;
L_20e7a60: if ((cmp_a == cmp_b)) { return r0; }
L_20e7a64: r0 = 0x217b9ecu;
L_20e7a68: r1 = 0x4u;
L_20e7a6c: r0 = StateDualHandler_SetState(r0,r1);
L_20e7a78: return r0;
}
