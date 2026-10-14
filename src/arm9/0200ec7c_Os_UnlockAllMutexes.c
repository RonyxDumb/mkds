/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_MutexQueue_Pop(unsigned int);
extern unsigned int Os_Thread_WakeUp(unsigned int);
unsigned int Os_UnlockAllMutexes(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4,r5,r6;
L_200ec80: r6 = r0;
L_200ec84: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 136));
L_200ec88: cmp_a = r0; cmp_b = 0x0u;
L_200ec90: if ((cmp_a == cmp_b)) { return r0; }
L_200ec94: r5 = (r6+0x88u);
L_200ec98: r4 = 0x0u;
L_200ec9c: r0 = r5;
L_200eca0: r0 = Os_MutexQueue_Pop(r0);
L_200eca4: *(unsigned int *)((unsigned char *)r0 + 12) = (unsigned int)r4;
L_200eca8: *(unsigned int *)((unsigned char *)r0 + 8) = (unsigned int)r4;
L_200ecac: r0 = Os_Thread_WakeUp(r0);
L_200ecb0: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r6 + 136));
L_200ecb4: cmp_a = r0; cmp_b = 0x0u;
L_200ecb8: if ((cmp_a != cmp_b)) { goto L_200ec9c; }
L_200ecc0: return r0;
}
