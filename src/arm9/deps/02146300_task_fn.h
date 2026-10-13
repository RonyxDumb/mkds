#pragma once
/* Function-specific inferred declarations. */
bool GlobalSZ_SomeFn(int param_1);
longlong Os_DisableIrq(void);
undefined4 Os_RestoreIrq(void);
void Os_Thread_WakeUp(uint *param_1);
void Os_Thread_WakeUpDirect(int param_1);
void task_fn(void);
#define uRam0214639c (*(uint *)(uintptr_t)0x214639cu)
#define uRam021463a0 (*(uint *)(uintptr_t)0x21463a0u)
