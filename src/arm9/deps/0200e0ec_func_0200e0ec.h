#pragma once
/* Function-specific inferred declarations. */
longlong Os_DisableIrq(void);
uint Os_DisableScheduler(void);
void Os_DisposeCurrentThreadImpl(void);
uint Os_EnableScheduler(void);
void Os_PopThread(uint param_1);
void Os_RescheduleThread(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_CancelAlarmForSleep(int param_1);
void Os_Thread_WakeUp(uint *param_1);
void Os_UnlockAllMutexes(int param_1);
void func_0200e0ec(uint param_1);
#define iRam0200e15c (*(int *)(uintptr_t)0x200e15cu)
