/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int func_020ea1d4(unsigned int, unsigned int, unsigned int);
extern unsigned int StateDualHandler_SetState(unsigned int, unsigned int);
unsigned int E7Fn2_7(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_20e8284: r0 = 0x217b990u;
L_20e8288: r1 = 0x21593e0u;
L_20e828c: r2 = 0x21593ecu;
L_20e8290: r0 = func_020ea1d4(r0,r1,r2);
L_20e8294: r0 = 0x217b8c8u;
L_20e8298: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_20e829c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 72));
L_20e82a0: r0 = (r0&0x800u); cmp_a = r0; cmp_b = 0;
L_20e82ac: if ((cmp_a == cmp_b)) { return r0; }
L_20e82b0: r0 = 0x217b9ecu;
L_20e82b4: r1 = 0x5u;
L_20e82b8: r0 = StateDualHandler_SetState(r0,r1);
L_20e82c4: return r0;
}
