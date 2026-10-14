/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_Alarm_Cancel(unsigned int);
unsigned int Os_Thread_CancelAlarmForSleep(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b;
L_200e0c8: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 176));
L_200e0cc: cmp_a = r0; cmp_b = 0x0u;
L_200e0d8: if ((cmp_a == cmp_b)) { return r0; }
L_200e0dc: r0 = Os_Alarm_Cancel(r0);
L_200e0e8: return r0;
}
