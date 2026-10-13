/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_Lock_HandleTryLock(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int Os_Lock_Wait(void);
unsigned int Os_Lock_TryLockImpl(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6,r7;
L_200cfd8: r7 = r0;
L_200cfdc: r6 = r1;
L_200cfe0: r5 = r2;
L_200cfe4: r4 = r3;
L_200cfe8: r0 = Os_Lock_HandleTryLock(r0,r1,r2,r3);
L_200cfec: cmp_a = r0; cmp_b = 0x0u;
L_200cff8: if (((int)cmp_a <= (int)cmp_b)) { return r0; }
L_200cffc: r0 = Os_Lock_Wait();
L_200d000: r0 = r7;
L_200d004: r1 = r6;
L_200d008: r2 = r5;
L_200d00c: r3 = r4;
L_200d010: r0 = Os_Lock_HandleTryLock(r0,r1,r2,r3);
L_200d014: cmp_a = r0; cmp_b = 0x0u;
L_200d018: if (((int)cmp_a > (int)cmp_b)) { goto L_200cffc; }
L_200d024: return r0;
}
