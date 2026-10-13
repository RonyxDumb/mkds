/* Verified complete local bytes; any relocations fully resolved. Caller ABI and full ROM remain unverified. */
extern unsigned int Os_DisableScheduler(void);
extern unsigned int Os_UnlockAllMutexes(unsigned int);
extern unsigned int Os_PopThread(unsigned int);
extern unsigned int Os_Thread_WakeUp(unsigned int);
extern unsigned int Os_EnableScheduler(void);
extern unsigned int Os_RescheduleThread(void);
extern unsigned int Os_Terminate(void);
unsigned int Os_DisposeCurrentThreadImpl(unsigned int r0,unsigned int r1,unsigned int r2,unsigned int r3)
{
unsigned int cmp_a,cmp_b,r4;
L_200e164: r0 = 0x216ff54u;
L_200e168: r0 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_200e16c: r4 = (unsigned int)(*(unsigned int *)((unsigned char *)r0 + 0));
L_200e170: r0 = Os_DisableScheduler();
L_200e174: r0 = r4;
L_200e178: r0 = Os_UnlockAllMutexes(r0);
L_200e17c: r0 = r4;
L_200e180: r0 = Os_PopThread(r0);
L_200e184: r1 = 0x2u;
L_200e188: r0 = (r4+0x9cu);
L_200e18c: *(unsigned int *)((unsigned char *)r4 + 100) = (unsigned int)r1;
L_200e190: r0 = Os_Thread_WakeUp(r0);
L_200e194: r0 = Os_EnableScheduler();
L_200e198: r0 = Os_RescheduleThread();
L_200e19c: r0 = Os_Terminate();
L_200e1a4: return r0;
}
