#pragma once
/* Function-specific inferred declarations. */
uint Os_DisableScheduler(void);
void Os_DisposeCurrentThreadImpl(void);
uint Os_EnableScheduler(void);
void Os_PopThread(uint param_1);
void Os_RescheduleThread(void);
void Os_Terminate(void);
void Os_Thread_WakeUp(uint *param_1);
void Os_UnlockAllMutexes(int param_1);
#define uRam0200e1a8 (*(uint *)(uintptr_t)0x200e1a8u)
