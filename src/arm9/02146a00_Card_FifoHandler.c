/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_Thread_WakeUpDirect(unsigned int);
unsigned int Card_FifoHandler(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_2146a08: cmp_a = r0; cmp_b = 0xbu;
L_2146a14: if ((cmp_a != cmp_b)) { return r0; }
L_2146a18: cmp_a = r2; cmp_b = 0x0u;
L_2146a24: if ((cmp_a == cmp_b)) { return r0; }
L_2146a28: r1 = 0x217fa40u;
L_2146a2c: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 276));
L_2146a30: r0 = (r0&~(0x20u));
L_2146a34: *(unsigned int *)((unsigned char *)r1 + 276) = (unsigned int)r0;
L_2146a38: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r1 + 260));
L_2146a3c: r0 = Os_Thread_WakeUpDirect(r0);
L_2146a48: return r0;
}
